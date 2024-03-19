// PerceptronLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Perceptron.h"

using namespace std;

int main()            
{
    Perceptron test1;
    string filename = "C:\\Users\\beaul\\Downloads\\percepGrades.csv";

    test1.loadData(filename);
    cout << "----- End of load data function -----" << endl << endl;
    test1.trainPerceptron();
    test1.printResults();

    return 0;
 }