#pragma once 
#include <iostream>
#include <string>

using namespace std;


constexpr int ARRAY_SIZE = 50;



int getValidateInt(string prompt, int min, int max);
double getValidateDouble(string prompt, double min, double max);
char getValidateChar(string prompt, string validChars);
string getValidateString(string prompt, int minLen , int maxLen);


void showMenu();