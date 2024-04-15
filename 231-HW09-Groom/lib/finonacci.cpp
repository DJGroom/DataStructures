#include "finonacci.hpp"
#include<math.h>
#include <string>
#include <iostream>
using namespace std;

Fibo::Fibo()
{
result = 0;
odd_fibnum = 1;
even_fibnum = 1;
itervation_value = 0;
};

void Fibo::fibiFunction(int fibinacci_num)
{
if(itervation_value == 0)
{
    result = 0;
    odd_fibnum = 1;
    even_fibnum = 1;
    itervation_value = 0;
    itervation_value++;
    fibiFunction(fibinacci_num);
}
if(fibinacci_num == 0)
{
    return;
}
if(itervation_value < 3)
{
    result = 1;
    if(itervation_value == fibinacci_num)
    {
        return;
    }
    itervation_value++;
    fibiFunction(fibinacci_num);
}
else
{
    result = odd_fibnum + even_fibnum;
    if(itervation_value == fibinacci_num)
    {
        return;
    }
    if(odd_fibnum > even_fibnum)
    {
        even_fibnum = result;
        cout << "Even:" << to_string(even_fibnum) << endl;
    }
    else
    {
        odd_fibnum = result;
        cout << "Odd:" << to_string(odd_fibnum) << endl;
    }
    itervation_value++;
    fibiFunction(fibinacci_num);
}
};
int Fibo::GetResult()
{
    return result;
};
