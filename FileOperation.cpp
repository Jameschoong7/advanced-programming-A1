#include <fstream>
#include <iostream>
#include "FileOperation.h"
#include <string>
using namespace std;




void FileOperation::loadDietPlanFile(string fileName, int &size){
    int counter =0;
    ifstream inData(fileName);
    if (!inData.is_open()) {
    cerr << "Error: Cannot open file " << fileName << endl;
    size = 0;
    return;
    }
    string temp;
    while(counter<ARRAY_SIZE&& getline(inData,allMeals[counter].mealType,',')){
        getline(inData,allMeals[counter].food,',');
        getline(inData,temp);
        allMeals[counter].calorie = stod(temp);
        counter++;
    }
    inData.close();
    size = counter;

}

void FileOperation::loadWorkoutPlanFile(string fileName, int &size){

    int counter =0;
    ifstream inData(fileName);
    if (!inData.is_open()) {
    cerr << "Error: Cannot open file " << fileName << endl;
    size = 0;
    return;
    }
    string temp;
    while(counter<ARRAY_SIZE&& getline(inData,allWorkout[counter].activity,',')){
        getline(inData,temp,',');
        allWorkout[counter].caloriesBurnPerminute = stoi(temp);
        getline(inData,temp);
        allMeals[counter].calorie = stod(temp);
        counter++;
    }
    inData.close();
    size = counter;


}


void FileOperation::loadUser(string fileName, int &size){
    int counter = 0;
    ifstream inData(fileName);

    // Make sure file is opened
    if (!inData.is_open()) {
        cerr << "Error: Unable to open file " << fileName << endl;
        size = 0;
        return;
    }

    // Read until end of file or max array size
    string name, goal;
    int age;
    char gender;
    double weight,height;
    while (counter < ARRAY_SIZE &&
           inData >> name
                  >> age
                  >> gender
                  >> weight
                  >>height
                  >>goal) {
        allUser[counter]=User(name,age,gender,weight,height,goal);
        counter++;
        if (counter >= ARRAY_SIZE) break;
    }

    inData.close();
    size = counter;


}