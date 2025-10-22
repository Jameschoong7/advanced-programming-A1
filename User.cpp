
#include <iostream>
#include "User.h"
#include <cstdlib>   
#include <ctime>     
#include "config.h"
#include "FileOperation.h"
using namespace std;



User::User():Person(){
    height = 0;
    weight =0;
    bmi = 0;
    personalGoal = "";
    historyCounter=0;
}

User::User(string name, int age, char gender, double w, double h, string pg):Person(name,age,gender){
    weight = w;
    height =h;
    
    bmi = weight / (height * height);
    personalGoal = pg;
    historyCounter =0;

}
User::~User(){
    //cout<<"Destructor called"<<endl;
}

void User::setValue(string name, int age, char gender,double w, double h, double bmi, string pg){
    Person::setValue(name,age,gender);
    weight = w;
    height =h;
    
    bmi = weight / (height * height);
    personalGoal = pg;
}

void getValue(double &weight, double &height, double &bmi, string &personalGoal);
void User::print(){
    Person::print();
    cout<<"Weight: "<<weight<<" kg"
        <<"\nHeight: "<<height<<" m"
        <<"\nBMI: "<<bmi
        <<"\nPersonal Goal: "<<personalGoal<<endl;
}
void User::updateMeasurement(double w,double h){
    history[historyCounter].weight = weight;
    history[historyCounter].height = height;
    history[historyCounter].bmi = bmi;
    historyCounter ++;
    weight  =w;
    height = h;
    bmi =  weight / (height * height);
    cout<<"Weight Updated: "<<weight<<" KG"<<endl;
    cout<<"Height Updated: "<<height<<" m"<<endl;
    cout<<"New BMI: "<<bmi<<endl;
}

void User::displayProgressReport(){
    cout<<"Previous Measurement Records (Max: 50)\n";
    for(const MeasurementRecords &record:history){
        cout<<"Weight: "<<record.weight
            <<"\nHeight: "<<record.height
            <<"\nBMI: "<<record.bmi<<endl;
    }
}

void User::generateRecommendedDietPlan(const MealItem allMeals[], int mealCount){
    srand(time(0)); 
    double minCalories = 0.0;
    double maxCalories = 0.0;

    if (gender == 'M') {
        if (personalGoal == "lose") {
            minCalories = 1500;
            maxCalories = 1800;
        } else if (personalGoal == "maintain") {
            minCalories = 1800;
            maxCalories = 2100;
        } else { 
            minCalories = 2100;
            maxCalories = 2400;
        }
    } else { 
        if (personalGoal == "lose") {
            minCalories = 1200;
            maxCalories = 1400;
        } else if (personalGoal == "maintain") {
            minCalories = 1400;
            maxCalories = 1700;
        } else { 
            minCalories = 1700;
            maxCalories = 2000;
        }
    }
    
    
    cout << "\nTarget Calories: Between " << minCalories 
         << " and " << maxCalories << endl;
    
    MealItem allBreakfast[ARRAY_SIZE], allLunch[ARRAY_SIZE], allDinner[ARRAY_SIZE],allSnack[ARRAY_SIZE];
    int breakfastCounter=0,lunchCounter=0,dinnerCounter =0,snackCounter =0;
    double currentCalories=0.0, minDinnerNeeded=0.0,maxDinnerNeeded=0.0;

    //classify meals to different meal type array
    for(int i=0;i<mealCount;i++){
        if (allMeals[i].mealType=="Breakfast"){
            allBreakfast[breakfastCounter]=allMeals[i];
            breakfastCounter ++;
        }
        else if (allMeals[i].mealType=="Lunch"){
            allLunch[lunchCounter] = allMeals[i];
            lunchCounter ++;
        }
        else if (allMeals[i].mealType=="Dinner"){
            allDinner[dinnerCounter] = allMeals[i];
            dinnerCounter++;
        }
        else if (allMeals[i].mealType=="Snack"){
            allSnack[snackCounter]=allMeals[i];
            snackCounter++;
        }
    }
    int randomBreakfastIndex = rand() % breakfastCounter;
    int randomLunchIndex = rand() % lunchCounter;

    //random select breakfast and lunch as recommendation
    MealItem chosenBreakfast = allBreakfast[randomBreakfastIndex];
    MealItem chosenLunch = allLunch[randomLunchIndex];

    //calculate calorie needed for dinner
    currentCalories = chosenBreakfast.calorie + chosenLunch.calorie;
    minDinnerNeeded = minCalories - currentCalories;
    maxDinnerNeeded = maxCalories - currentCalories;

    //temporary array for valid dinner (within the remaining calorie range)
    MealItem validDinners[ARRAY_SIZE];
    int validDinnerCount = 0;
    for (int i = 0; i < dinnerCounter; i++) {
        double dinnerCal = allDinner[i].calorie;
        
        // Check if this dinner's calorie is in required range
        if (dinnerCal >= minDinnerNeeded && dinnerCal <= maxDinnerNeeded) {
            validDinners[validDinnerCount] = allDinner[i];
            validDinnerCount++;
        }
    }
    if (validDinnerCount == 0) {
        cout << "Sorry, no suitable dinner could be found to meet your calorie target with the random breakfast/lunch." << endl;
        cout << "Please try generating again." << endl;
        return; 
    }

    //random select dinner from valid dinner list
    int randomDinnerIndex = rand() % validDinnerCount;
    MealItem chosenDinner = validDinners[randomDinnerIndex];

    //update latest diet plan
    dietPlan.clearMeal();
    dietPlan.addMeal(chosenBreakfast);
    dietPlan.addMeal(chosenLunch);
    dietPlan.addMeal(chosenDinner);

    //display the plan
    cout<<"New recommended plan: \n";
    dietPlan.displayPlan();
    double totalCalories= dietPlan.getTotalCalories();
    cout<<"Total calories: "<<totalCalories;



}