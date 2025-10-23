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

//function to clear workout plan
void WorkoutPlan::clearPlan() {
    for (int i = 0; i < numActivities; i++) {
        activities[i].activity = "";
        activities[i].intensityLevel = 0;
        activities[i].caloriesBurnPerminute = 0.0;
         activities[numActivities].durations =0;
    }

    numActivities = 0;

    cout << "Workout plan cleared successfully." << endl;
}


//function to show activity added
void WorkoutPlan::displayLog(){
    if(numActivities!=0){
    for (int i = 0; i < numActivities; i++) {
        cout << "\nActivity: " << activities[i].activity
             << "\nIntensity Level (1-4): " << activities[i].intensityLevel
             << "\nCalories Burn Per Minute: " << activities[i].caloriesBurnPerminute
             <<"\nDuration: "<< activities[i].durations << endl;
        }
    }
    else{
        cout<<"No Workout Plan Yet..."<<endl;
    }
}

//function to calculate total calorie burnt
double WorkoutPlan::getTotalCaloriesBurned(){
    double totalCalories = 0.0;
    for (int i = 0; i < numActivities; i++) {
        totalCalories += activities[i].caloriesBurnPerminute * activities[i].durations;
    }
    return totalCalories;
}
