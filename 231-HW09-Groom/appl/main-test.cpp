
/*
================================================================================#=
FILE: appl/main_test.cpp

Test application for the Sorted List.
================================================================================#=
*/
#include "finonacci.cpp"
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <vector>
using namespace std;
bool test(void)
{
    Fibo example;
    example.fibiFunction(46);
    cout << "Result: " << to_string(example.GetResult()) << endl;
    Fibo example2;
    example2.fibiFunction(8);
    cout << "Result: " << to_string(example2.GetResult()) << endl;
    return true;
};
int main() {
    if(test() == true)
    {
        cout << "YES!";
        return 0;
    }
    else
    {
        cout << "Getting closer!";
        return 0;
    }
};
