#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // Checks the range to make sure its between 1-9
    if(digit<48||digit>57){
        throw std::invalid_argument("pee1 ");
    }
    return digit - '0';
}

char decimal_to_digit(unsigned int decimal) {
    // Checks the range to make sure its between 1-9
    if(decimal>9){
        throw std::invalid_argument("pee2");
    }
    return char(decimal) + '0';
}

string trim_leading_zeros(string num) {
    char sign = '+';
    if(num.at(0)=='-'){
        sign = '-';
        num = num.substr(1,num.length()-1);
    }
    while(num.length()>=1 && num.at(0)=='0'){
        num = num.substr(1,num.length()-1);
    }
    if(num == "") return "0";
    if(sign == '-'){
        num.insert(0,1,sign);
    }
    return num;
}

string add(string lhs, string rhs) {
    char sign = '+';
    int temp_num = 0;
    int temp_num_extra = 0;
    int size = 0;
    string final_answer = "";
    if(lhs.at(0)=='-' && rhs.at(0)=='-'){
        sign = '-';
        lhs = lhs.substr(1,lhs.size()-1);
        rhs = rhs.substr(1,rhs.size()-1);
    }
    while(lhs.length() != rhs.length()){
        if(lhs.length() < rhs.length()) lhs.insert(0, "0");
        else rhs.insert(0, "0");
    }
    size = lhs.length();
    for(int i = 1; i <= size; i++){
        temp_num = (digit_to_decimal(lhs.back()))+(digit_to_decimal(rhs.back()));
        lhs.pop_back();
        rhs.pop_back();
        temp_num += temp_num_extra;
        temp_num_extra = 0;
        if(temp_num >= 10){
            temp_num_extra = temp_num / 10;
            temp_num = temp_num % 10;         
        }
        final_answer.insert(0,1,decimal_to_digit(temp_num));
    }
    if(temp_num_extra != 0){
        final_answer.insert(0,1,decimal_to_digit(temp_num_extra));
    }
    if(sign == '-'){
        final_answer.insert(0,1,sign);
    }
    return trim_leading_zeros(final_answer);
}

string multiply(string lhs, string rhs) {
    int temp_num = 0;
    int temp_num_extra = 0;
    string temp_answer = "";
    string final_answer = "0";
    char sign = '+';
    if(lhs.at(0)=='-' && rhs.at(0)!='-'){
        sign = '-';
        lhs = lhs.substr(1,lhs.size()-1);
    }
    else if(lhs.at(0)!='-' && rhs.at(0)=='-'){
        sign = '-';
        rhs = rhs.substr(1,rhs.size()-1);
    }
    else if(lhs.at(0)=='-' && rhs.at(0)=='-'){
        lhs = lhs.substr(1,lhs.size()-1);
        rhs = rhs.substr(1,rhs.size()-1);
    }
    for(int i = lhs.size()-1; i >= 0; i--){
        temp_answer = "";
        temp_num_extra = 0;
        for(int k = lhs.size()-1; k > i; k--){
            temp_answer += "0";
        }
        for(int j = rhs.size()-1; j >= 0; j--){
            temp_num = digit_to_decimal(lhs.at(i)) * digit_to_decimal(rhs.at(j));
            temp_num += temp_num_extra;
            temp_num_extra = temp_num/10;
            temp_num %= 10;
            temp_answer.insert(0,1,decimal_to_digit(temp_num));
        }
        if(temp_num_extra != 0){
            temp_answer.insert(0,1,decimal_to_digit(temp_num_extra));
        }
        final_answer = add(final_answer,temp_answer);
    }
    if(sign=='-'){
        final_answer.insert(0,1,sign);
    }
    return trim_leading_zeros(final_answer);
}