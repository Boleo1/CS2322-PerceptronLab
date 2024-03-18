#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


class Perceptron
{
public:
	string filename;
	int x, y, truth;

	Perceptron();
	void loadData(string filename);
	void trainPerceptron();
	void printResults();


private:

};

