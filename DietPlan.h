#pragma once
#include <iostream>
using namespace std;


constexpr int ARRAY_SIZE = 50;

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
        void displayPlan();
        double getTotalCalories();
};