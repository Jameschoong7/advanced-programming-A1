#pragma once
#include <iostream>
#include "config.h"
using namespace std;

struct WorkoutActivity{
    string activity;
    int intensityLevel;
    double caloriesBurnPerminute;
    double durations;
};

class WorkoutPlan{
    private:
        WorkoutActivity activities[ARRAY_SIZE];

        int numActivities;
    public:
        WorkoutPlan();
        ~WorkoutPlan();
        void addActivity(const WorkoutActivity& newActivity, int minutes);
        void clearPlan();
        void displayLog();
        double getTotalCaloriesBurned();
};