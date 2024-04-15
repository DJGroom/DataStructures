
/*
================================================================================================#=
Fraction Type Unit Test Driver

FILE: fraction_type_driver.cpp

ACKNOWLEDGEMENTS:
This code is substantially based on:
    Fraction Class Case Study
    C++ Plus Data Structures
    Nell Dale, University of Texas, Austin
    Chip Weems, University of Massachusetts, Amherst
    Tim Richards, University of Massachusetts, Amherst
    Jones & Bartlett Learning, LLC
================================================================================================#=
*/


#include <iostream>
#include <fstream>
#include <string>
#include "fraction_type.hpp"


int main()
{
  using namespace std;
  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;
  string command;        // operation to be executed
  int numCommands;

  // Prompt for file names, read file names, and prepare files
  cout << "Enter name of input file; press return." << endl;
  cin  >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter name of output file; press return." << endl;
  cin  >> outFileName;
  outFile.open(outFileName.c_str());

  cout << "Enter name of test run; press return." << endl;
  cin  >> outputLabel;
  outFile << outputLabel << endl;

  // -----------------------------------------------------+-
  // The Object Under Test
  // -----------------------------------------------------+-
  FractionType *the_fraction = NULL;

  inFile >> command;
  numCommands = 0;

    while (command != "Quit")
    {
        if (command == "Initialize")
        {
            int numerator, denominator;
            inFile  >> numerator;
            inFile  >> denominator;

            if(the_fraction) {
                delete the_fraction;
            }
            the_fraction = new FractionType(numerator, denominator);

            outFile << "Numerator: "   << the_fraction->NumeratorIs() << " ";
            outFile << "Denominator: " << the_fraction->DenominatorIs() << endl;
        }
    else if (command == "NumeratorIs")
      outFile <<  "Numerator: "  << the_fraction->NumeratorIs() << endl;
    else if (command == "DenominatorIs")
      outFile << "Denominator: " << the_fraction->DenominatorIs() << endl;
    else if (command == "IsZero")
      if (the_fraction->IsZero())
        outFile << "Fraction is zero " << endl;
      else
        outFile << "Fraction is not zero " << endl;
    else if (command == "IsNotProper")
      if (the_fraction->IsNotProper())
        outFile << "Fraction is improper " << endl;
      else
        outFile << "Fraction is proper " << endl;
    else
    {
      outFile << "Whole number is " << the_fraction->ConvertToProper() 
              << endl;
      outFile <<  "Numerator: "  << the_fraction->NumeratorIs() 
              <<   " Denominator: " << the_fraction->DenominatorIs() << endl;

    }

    numCommands++;
    cout << "Command number " << numCommands << " completed." 
         << endl;

    inFile >> command;
  };

  cout << "Testing completed."  << endl;
  return 0;
}

