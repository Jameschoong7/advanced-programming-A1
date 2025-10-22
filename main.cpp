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

   cout << "--- Please Select a User ---" << endl;
    for (int i = 0; i < userSize; i++) {
        
        cout << (i + 1) << ". " << fo.allUser[i].getName() << endl;
    }
    
    int selection;
    selection = getValidateInt("Enter User Number: ",1,userSize);
    int selectedIndex = selection - 1;

    User& selectedUser = fo.allUser[selectedIndex];
    
    cout << "You selected: " << selectedUser.getName() << endl;

    selectedUser.generateRecommendedDietPlan(fo.allMeals,dietInfoSize);
    selectedUser.generateRecommendedWorkoutPlan(fo.allWorkout,workoutPlanSize);
}