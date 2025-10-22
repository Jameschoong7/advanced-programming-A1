
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

void User::getValue(string &name, int &age, char &gender, double &weight, double &height, double &bmi, string &personalGoal){
    Person::getValue(name,age,gender);
    weight = this->weight;
    height = this->height;
    bmi = weight / (height * height);
    personalGoal = this->personalGoal;
}



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

string User::getName(){
    return this->name;

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
    cout<<"\nTotal calories: "<<totalCalories;



}

void User::generateRecommendedWorkoutPlan(const WorkoutActivity allActivities[], int activityCount){
    srand(time(0));
    double minBurnTarget = 0.0;
    double maxBurnTarget = 0.0;
    int minIntensity = 1;
    int maxIntensity = 4;


    if (gender == 'M') { // Max burn is 500
        if (personalGoal == "lose") {
            minBurnTarget = 450;
            maxBurnTarget = 500;
            minIntensity = 3;
            maxIntensity = 4;
        } else if (personalGoal == "maintain") {
            minBurnTarget = 300;
            maxBurnTarget = 400;
            minIntensity = 2;
            maxIntensity = 3;
        } else { // "gain"
            minBurnTarget = 150;
            maxBurnTarget = 250;
            minIntensity = 1;
            maxIntensity = 2;
        }
    } else { // 'F', Max burn is 400
        if (personalGoal == "lose") {
            minBurnTarget = 350;
            maxBurnTarget = 400;
            minIntensity = 3;
            maxIntensity = 4;
        } else if (personalGoal == "maintain") {
            minBurnTarget = 200;
            maxBurnTarget = 300;
            minIntensity = 2;
            maxIntensity = 3;
        } else { // "gain"
            minBurnTarget = 100;
            maxBurnTarget = 150;
            minIntensity = 1;
            maxIntensity = 2;
        }
    }

    cout << "\nTarget Calorie Burn: Between " << minBurnTarget 
         << " and " << maxBurnTarget << " calories." << endl;


    //filter activity based on intensity level
    WorkoutActivity suitableActivities[ARRAY_SIZE];
    int suitableActivityCount = 0;

    for (int i = 0; i < activityCount; i++) {
        int currentIntensity = allActivities[i].intensityLevel;
        if (currentIntensity >= minIntensity && currentIntensity <= maxIntensity) {
            suitableActivities[suitableActivityCount] = allActivities[i];
            suitableActivityCount++;
        }
    }

    // Check min 2 activity for routines
    if (suitableActivityCount < 2) {
        cout << "Sorry, not enough different activities were found (need at least 2) "
             << "to build a routine for your goal." << endl;
        return; // Exit the function
    }

    //randomly pick 2 activity
    int index1 = rand() % suitableActivityCount;
    int index2 = rand() % suitableActivityCount;

    // Keep picking a new index2 until it's different from index1
    while (index1 == index2) {
        index2 = rand() % suitableActivityCount;
    }

    WorkoutActivity chosenActivity1 = suitableActivities[index1];
    WorkoutActivity chosenActivity2 = suitableActivities[index2];

    //Pick a random total calorie goal from our target range (min + random of max-min)
    double randomBurnGoal = minBurnTarget + (rand() % (int)(maxBurnTarget - minBurnTarget + 1));

    //Divide the calorie goal between the two activities (e.g., 50/50 split)
    double goal1 = randomBurnGoal * 0.5;
    double goal2 = randomBurnGoal * 0.5;

    //Calculate the duration for each activity
    int duration1 = goal1 / chosenActivity1.caloriesBurnPerminute;
    int duration2 = goal2 / chosenActivity2.caloriesBurnPerminute;

    workoutPlan.clearPlan();
    workoutPlan.addActivity(chosenActivity1, duration1);
    workoutPlan.addActivity(chosenActivity2, duration2);

    //Print the result
    cout << "\n--- Your New Recommended Workout Routine ---" << endl;
    this->workoutPlan.displayLog();
    cout << "------------------------------------------" << endl;
    cout << "Estimated Total Calories Burned: " 
         << this->workoutPlan.getTotalCaloriesBurned() << endl;
}