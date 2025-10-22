#pragma once
#include <iostream>
#include "config.h"
using namespace std;


//struct to store meals
struct MealItem {
    string mealType; 
    string food;
    double calorie;
};

class DietPlan{
    private:
        MealItem meals[ARRAY_SIZE];
        int numMeals;
    public:
        DietPlan();
        ~DietPlan();
        void addMeal(const MealItem& newMeal);
        void clearMeal();
        void displayPlan();
        double getTotalCalories();
};