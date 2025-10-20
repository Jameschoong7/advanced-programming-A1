#pragma once
#include <iostream>
#include "User.h"

using namespace std;


User::User():Person(){
    height = 0;
    weight =0;
    bmi = 0;
    personalGoal = "";
    historyCounter=0;
}

User::User(string name, int age, char gender, double h, double w, string pg):Person(name,age,gender){
    height =h;
    weight = w;
    bmi = weight / (height * height);
    personalGoal = pg;
    historyCounter =0;

}
User::~User(){
    cout<<"Destructor called"<<endl;
}

void User::setValue(string name, int age, char gender,double h, double w, double bmi, string pg){
    Person::setValue(name,age,gender);
    height =h;
    weight = w;
    bmi = weight / (height * height);
    personalGoal = pg;
}

void getValue(double &height, double &wwight, double &bmi, string &personalGoal);
void User::print(){
    Person::print();
    cout<<"Height: "<<height<<" m"
        <<"\nWeight: "<<weight<<" kg"
        <<"\nBMI: "<<bmi
        <<"\nPersonal Goal: "<<personalGoal<<endl;
}
void User::updateMeasurement(double w,double h){
    history[historyCounter].weight = weight;
    history[historyCounter].height = height;
    history[historyCounter].bmi = bmi;
    historyCounter ++;
    weight  =w;
    height = h;
    bmi =  weight / (height * height);
    cout<<"Weight Updated: "<<weight<<" KG"<<endl;
    cout<<"Height Updated: "<<height<<" m"<<endl;
    cout<<"New BMI: "<<bmi<<endl;
}

void User::displayProgressReport(){
    cout<<"Previous Measurement Records (Max: 50)\n";
    for(const MeasurementRecords &record:history){
        cout<<"Weight: "<<record.weight
            <<"\nHeight: "<<record.height
            <<"\nBMI: "<<record.bmi<<endl;
    }
}