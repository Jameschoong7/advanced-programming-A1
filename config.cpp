#include "config.h"
#include <iostream>
#include <string>

int getValidateInt(string prompt, int min, int max){
    int value;
    while(true){
        cout<<prompt;
        if(cin>>value && value>=min && value<=max){
            cin.ignore();
            return value;
        }
        cout<<"Invalid Input, try again: ";
        cin.clear();
        cin.ignore();
    }

}

void showMenu(){
    return;

}