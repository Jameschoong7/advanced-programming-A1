#include "Person.h"
#include <iostream>

using namespace std;

Person::Person(){
    name = "User";
    age = 21;
    gender = 'M';
}

Person::Person(string n, int a, char g){
    name =n;
    age =a;
    gender = g;
}

void Person::print(){
    cout<<"Name: "<<name
        <<"\nAge: "<<age
        <<"\nGender: "<<gender<<endl;
}

void Person::setValue(string n, int a, char g){
    name =n;
    age =a;
    gender = g;
}

void Person::getValue(string &n, int &a, char &g){
    n = name;
    a = age;
    g = gender;
}