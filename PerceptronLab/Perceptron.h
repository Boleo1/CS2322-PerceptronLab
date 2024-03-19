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

	DataPoint(int x, int y, int truth) : x(x), y(y), truth(truth) {}
};

class Perceptron
{
public:
	Perceptron();
	void loadData(const string& filename);
	int modelFunction(int x, int y);
	void trainPerceptron();
	void printResults();


private:
	double c1, c2, c3;
	double learningRate;
	vector<DataPoint> dataset;
};

