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


double getValidateDouble(string prompt, double min, double max) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= min && value <= max) {
            cin.ignore();
            return value;
        }
        cout << "Invalid input. Try again.\n";
        cin.clear();
        cin.ignore();
    }
}

char getValidateChar(string prompt, string validChars = "") {
    char value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            value = tolower(value);
            cin.ignore();
            if (validChars.empty() || validChars.find(tolower(value)) != string::npos)
                return value;
        }
        cout << "Invalid input. Try again.\n";
        cin.clear();
        cin.ignore();
    }
}

string getValidateString(string prompt, int minLen = 1, int maxLen = 100) {
    string value;
    while (true) {
        cout << prompt;
        getline(cin, value);
        if ((int)value.length() >= minLen && (int)value.length() <= maxLen)
            return value;
        cout << "Invalid input length. Try again.\n";
    }
}

void showMenu() {
    cout << "\n==========================================" << endl;
    cout << "1. View User Details & BMI" << endl;
    cout << "2. Update Weight/Height" << endl;
    cout << "3. View Progress Report" << endl;
    cout << "4. Compare Progress (Start vs. Current)" << endl; 
    cout << "5. Generate Recommended Diet Plan" << endl;         
    cout << "6. Add Meal to Diet Plan (Manual)" << endl;       
    cout << "7. View Current Diet Plan" << endl;               
    cout << "8. Generate Recommended Workout Routine" << endl; 
    cout << "9. Add Workout Activity (Manual)" << endl;      
    cout << "10. View Current Workout Plan" << endl;           
    cout << "11. Exit" << endl;
    cout << "------------------------------------------" << endl;
    
}