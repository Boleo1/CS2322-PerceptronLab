#include "Perceptron.h"
// Constructor.
Perceptron::Perceptron()
{
	c1 = 0;
	c2 = 0;
	c3 = 0;
	learningRate = 0.001;
}


// Method to load data from csv file.
void Perceptron::loadData(const string& filename)
{
	string line;
	ifstream myFile;


	// Opening File.
	myFile.open(filename);

	// Check if file can be opnened or not.
	if (myFile.fail()) {
		cout << "Failed to open file: " << filename << endl;
	}

	// Takes the first row of data since this will be an excel made CSV.
	string header;
	getline(myFile, header);
	cout << "This is the top row of data: " << header << endl;

	// Reads each line from file and assigns each to the dataset vector.
	while (getline(myFile, line)) {
		stringstream linestream(line);
		string cell;
		int x, y, truth;

		getline(linestream, cell, ',');
		x = stoi(cell);

		getline(linestream, cell, ',');
		y = stoi(cell);

		getline(linestream, cell, ',');
		truth = stoi(cell);
		
		dataset.push_back(DataPoint(x, y, truth));
		cout << "X: " << x << ", Y: " << y << ", Truth: " << truth << endl;
	}
	myFile.close();
	cout << "Loaded " << dataset.size() << " data points from " << filename << endl;
}

int Perceptron::modelFunction(int x, int y)
{
	int sum = c1 + (x * c2) + (y * c3);
	return sum >= 0 ? 1: -1;
}

void Perceptron::trainPerceptron()
{
	std::cout << "Training perceptron..." << std::endl;

	int epochs = 0;
	const int MAX_EPOCHS = 1000;
	bool isTrainingComplete = false;

	while (!isTrainingComplete && epochs < MAX_EPOCHS) {
		isTrainingComplete = true;

		for (const auto& dataPoint : dataset) {
			int predicted = modelFunction(dataPoint.x, dataPoint.y);
			int error = dataPoint.truth - predicted;

			if (error != 0) {
				// c1 is the bias weight, it's updated with just the error
				c1 += learningRate * error;
				c2 += learningRate * error * dataPoint.x;
				c3 += learningRate * error * dataPoint.y;
				isTrainingComplete = false;
			}
		}
		std::cout << "Epoch " << epochs << ": c1 = " << c1 << ", c2 = " << c2 << ", c3 = " << c3 << std::endl;
		epochs++;
	}

	if (epochs == MAX_EPOCHS) {
		std::cout << "Training stopped after reaching the maximum number of epochs." << std::endl;
	}
	else {
		std::cout << "Training complete." << std::endl;
	}
	printResults();
}

void Perceptron::printResults()
{
	std::cout << "Weights: c1 = " << c1 << ", c2 = " << c2 << ", c3 = " << c3 << std::endl;
}
