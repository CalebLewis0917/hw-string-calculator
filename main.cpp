#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

int main() {
    string num1;
    string num2;
    char operatr = '-';
    string user_line;
    std::istringstream inSS;
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    cout << ">> ";

    getline(cin, user_line);
    cout << endl;
    
    while(user_line != "quit" && user_line != "q"){

        inSS.clear();
        inSS.str(user_line);
        inSS >> num1 >> operatr >> num2;

        if(operatr=='+'){
            cout << "ans =" << endl << endl << "    " << add(num1,num2) << endl;
        }
        else if(operatr=='*'){
            cout << "ans =" << endl << endl << "    " << multiply(num1,num2) << endl;
        }

        cout << endl << ">> ";
        getline(cin, user_line);
        cout << endl;
    }
    cout << "farvel!" << endl << endl;
}

