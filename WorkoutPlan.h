#pragma once
#include <iostream>
using namespace std;

constexpr int ARRAY_SIZE = 50;

struct WorkoutActivity{
    string activity;
    int intensityLevel;
    double caloriesBurnPerminute;

};

class WorkoutPlan{
    private:
        WorkoutActivity activity[ARRAY_SIZE];

        int numActivities;
    public:
        WorkoutPlan();
        ~WorkoutPlan();
        void addActivity(const WorkoutActivity& newActivity, int minutes);
        void displayLog();
        double getTotalCaloriesBurned();
};