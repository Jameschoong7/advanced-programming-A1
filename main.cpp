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
    int choice;
    do{
        
        showMenu();
        choice = getValidateInt("Enter your choice (1-11): ",1,11);
        switch (choice) {
            case 1:
                //operator overload
                cout<<selectedUser;    

                break;

            case 2: {
                double newWeight = getValidateDouble("Enter new weight (kg): ", 30, 200);
                double newHeight = getValidateDouble("Enter new height (m): ", 1.0, 2.5);
                selectedUser.updateMeasurement(newWeight, newHeight);
                break;
            }

            case 3:
                selectedUser.displayProgressReport();
                break;

            case 4: 
                selectedUser.compareProgress();

              
                cout << "\nBased on this progress, you can:" << endl;
                cout << " - Generate a new plan (Options 5 & 8)" << endl;
                cout << " - Manually adjust your plan (Options 6 & 9)" << endl;
                break;
            case 5: 
                selectedUser.generateRecommendedDietPlan(fo.allMeals, dietInfoSize);
                break;
            case 6: 
                selectedUser.addMealManually(fo.allMeals, dietInfoSize);
                break;
            case 7: 
                cout << "\n--- Current Diet Plan ---\n";
                selectedUser.getDietPlan();
                break;
            case 8: 
                selectedUser.generateRecommendedWorkoutPlan(fo.allWorkout, workoutPlanSize);
                break;
            case 9: 
                selectedUser.addWorkoutManually(fo.allWorkout, workoutPlanSize);
                break;
            case 10:
                cout << "\n--- Current Workout Plan ---\n";
                selectedUser.getWorkoutPlan();
                break;
            case 11: 
                cout << "Exiting program... Goodbye!\n";
                break;

            default:
                cout << "Invalid choice.\n";
                break;
        }



    }while(choice!=11);
    


    
    


}