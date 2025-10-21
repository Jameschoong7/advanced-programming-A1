#include <fstream>
#include <iostream>
#include "DietPlan.h"
#include "WorkoutPlan.h"
#include "User.h"
using namespace std;

constexpr int ARRAY_SIZE = 50;

struct FileOperation{
    MealItem allMeals[ARRAY_SIZE];
    WorkoutActivity allWorkout[ARRAY_SIZE];
    User allUser[ARRAY_SIZE];

    
    
    void loadDietPlanFile(string fileName, int &size);
    void loadWorkoutPlanFile(string fileName, int &size);
    void loadUser(string fileName, int &size);

};