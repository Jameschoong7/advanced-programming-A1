#include <iostream>
#include "DietPlan.h"
#include "config.h"
using namespace std;



DietPlan::DietPlan(){
    numMeals = 0;
}



DietPlan::~DietPlan(){
    //cout<<"Destructor is called"<<endl;
}

//function to add meal 
void DietPlan::addMeal(const MealItem &meal){
    meals[numMeals] = meal;
    cout<<"Meal added:\n"
        <<"Meal Type: "<<  meals[numMeals].mealType
        <<"\nFood: "<< meals[numMeals].food
        <<"\nCalorie: "<< meals[numMeals].calorie<<endl;
    
    numMeals +=1;
}

//function to clear meal list
void DietPlan::clearMeal(){
    for (int i =0;i<numMeals;i++){
        meals[i].mealType ="";
         meals[i].food="";
         meals[i].calorie=0;
    }
  
    numMeals =0;
}

//function to display diet plan
void DietPlan::displayPlan(){
    if(numMeals!=0){
        for (int i =0;i<numMeals;i++){
            cout<<"Meal Type: "<<  meals[i].mealType
            <<"\nFood: "<< meals[i].food
            <<"\nCalorie: "<< meals[i].calorie<<endl;
        }
    }
    else{
        cout<<"No Diet Plan yet..."<<endl;
    }
}

//function to get total meal plan calories
double DietPlan::getTotalCalories(){
    double calories = 0.0;
    for (int i =0;i<numMeals;i++){
        calories += meals[i].calorie;
    }
    
    return calories;
}