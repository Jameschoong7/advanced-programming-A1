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
    for(MealItem &meal:meals){
        meal.mealType="";
        meal.food="";
        meal.calorie=0;
    }
    numMeals =0;
}

//function to display diet plan
void DietPlan::displayPlan(){
    for(const MealItem &meal:meals){
        cout<<"Meal Type: "<<  meal.mealType
        <<"\nFood: "<< meal.food
        <<"\nCalorie: "<< meal.calorie<<endl;
    }
}

//function to get total meal plan calories
double DietPlan::getTotalCalories(){
    double calories = 0.0;
    for(const MealItem &meal:meals){
        calories += meal.calorie;
    }
    return calories;
}