#pragma once
#include <iostream>
#include "Person.h"
#include "WorkoutPlan.h"
#include "DietPlan.h"

#include "config.h"
using namespace std;



struct MeasurementRecords{
    double height;
    double weight;
    double bmi;
};

class User:public Person{

    private:
        double height;
        double weight;
        double bmi;
        string personalGoal;

        //Measurement Record
        MeasurementRecords history[ARRAY_SIZE];
        int historyCounter;

        WorkoutPlan workoutPlan;
        DietPlan dietPlan;
    
    public:
        User();
        User(string n, int a, char g, double h, double w, string pg);
        ~User();

        void setValue(string name, int age, char gender, double w, double h, double bmi, string pg);
        void getValue(double &weight, double &height, double &bmi, string &personalGoal);
        void print();
        void updateMeasurement(double w,double h);
        
        void displayProgressReport();


        void generateRecommendedDietPlan(const MealItem allMeals[], int mealCount);
};