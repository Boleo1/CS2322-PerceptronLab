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
    double learningCurve = 0.01;
    Perceptron perceptron1(0,0,0, learningCurve);
    Perceptron perceptron2(0, 1, -2, learningCurve);
    Perceptron perceptron3(-2, 1, -2, learningCurve);
    string filename = "C:\\Users\\beaul\\Downloads\\percepGrades.csv";

    perceptron1.loadData(filename);
    perceptron1.trainPerceptron();

    perceptron2.loadData(filename);
    perceptron2.trainPerceptron();

    perceptron3.loadData(filename);
    perceptron3.trainPerceptron();

    double result1 = perceptron1.test(20,15);
    double result2 = perceptron1.test(2, 10);
    double result3 = perceptron1.test(10, 1);

    cout << "Perceptron 1 test: " << result1 << endl;
    cout << "Perceptron 2 test: " << result2 << endl;
    cout << "Perceptron 3 test: " << result3 << endl;
    return 0;
 }