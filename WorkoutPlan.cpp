#include "config.h"
#include <iostream>
#include "WorkoutPlan.h"

using namespace std;

WorkoutPlan::WorkoutPlan(){
    numActivities = 0;
}

WorkoutPlan::~WorkoutPlan(){
    //cout<<"Destructor is called"<<endl;
}

//function to add activity
void WorkoutPlan::addActivity(const WorkoutActivity& newActivity, int minutes){
    activities[numActivities].activity = newActivity.activity;
    activities[numActivities].intensityLevel = newActivity.intensityLevel;
    activities[numActivities].caloriesBurnPerminute = newActivity.caloriesBurnPerminute;
    activities[numActivities].durations = minutes;

    cout<<"Activity Added:"
        <<"\nActivity: "<< activities[numActivities].activity
        <<"\nIntensity Level (1-4): "<<activities[numActivities].intensityLevel
        <<"\nCalories Burn Per Minute: "<<activities[numActivities].caloriesBurnPerminute
        <<"\nDuration (min): "<<activities[numActivities].durations<<endl;

    numActivities ++;

}

//function to show activity added
void WorkoutPlan::displayLog(){

    for(const WorkoutActivity &activity:activities){
        cout<<"\nActivity: "<< activity.activity
        <<"\nIntensity Level (1-4): "<<activity.intensityLevel
        <<"\nCalories Burn Per Minute: "<<activity.caloriesBurnPerminute<<endl;

    }
}

//function to calculate total calorie burnt
double WorkoutPlan::getTotalCaloriesBurned(){
    double totalCalories =0.0;
    for(const WorkoutActivity &activity:activities){
        totalCalories+=(activity.caloriesBurnPerminute * activity.durations);
    }
    return totalCalories;
}
