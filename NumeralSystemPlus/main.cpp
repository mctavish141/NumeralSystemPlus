//
//  main.cpp
//  NumeralSystemPlus
//
//  Created by Serhii Kopach on 14.09.15.
//  Copyright (c) 2015 Serhii Kopach. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>

// Checking if current symbol is a digit (from 0 to 9)

bool isDigit (char symbol) {
    return (symbol >= 48) && (symbol <= 57);
}

// Converting from char to int

int charToInt (char symbol) {
    return (isDigit(symbol)) ? symbol - 48 : 0;
}

////////////////
////////////////
////////////////

using namespace std;

int main () {
    // Reading incoming system value
    
    int incomingSystem = 0;
    cout << "Enter incoming system: ";
    cin >> incomingSystem;
    
    // Reading incoming number string
    
    string incomingNumber;
    cout << "Enter number in " << incomingSystem << " numeral system: ";
    cin >> incomingNumber;
    
    int incomingStringLength = (int)incomingNumber.length();
    
    // Converting incoming number to another numeral system
    
    int x = 0;
    for (int i = 0; i < incomingStringLength; i++) {
        x = x + charToInt(incomingNumber[incomingStringLength - 1 - i]) * pow(incomingSystem, i);
    }
    
    // Printing result
    
    cout << "Number in 10 numeral system: " << x << endl;
    
    return 0;
}