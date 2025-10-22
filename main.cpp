#include "User.h"
#include "FileOperation.h"
#include "config.h"
#include <iostream>

using namespace std;

const string dietPlansFile = "dietPlans.txt";
const string userFile = "userinfo.txt";
const string workoutPlansFile = "workoutPlans.txt";

int main(){

    FileOperation fo;
    int dietInfoSize,userSize,workoutPlanSize;
    fo.loadDietPlanFile(dietPlansFile,dietInfoSize);
    fo.loadUser(userFile,userSize);
    fo.loadWorkoutPlanFile(workoutPlansFile,workoutPlanSize);

   




}