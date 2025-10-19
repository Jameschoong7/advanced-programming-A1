#pragma once
#include <iostream>
using namespace std;


class Person{
    protected:
        string name;
        int age;
        char gender;
    
    public:
        Person();
        Person(string n, int a, char g);
        
        void setValue(string n, int a, char g);
        void getValue(string &n, int &a, char &g);
        void print();

};