#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct DataPoint {
	int x;
	int y;
	int truth;

	DataPoint(int x, int y, int truth)
	{
		this->x = x;
		this->y = y;
		this->truth = truth;
	}
};

class Perceptron
{
public:
	Perceptron(double initialC1, double initialC2, double initialC3, double initialLearningRate);
	void loadData(const string& filename);
	int modelFunction(int x, int y);
	void trainPerceptron();
	void printResults();
	int test(int gradeNum, int gradeDen);


private:
	double c1, c2, c3;
	double learningRate;
	vector<DataPoint> dataset;
};

