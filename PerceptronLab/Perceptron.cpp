#include "Perceptron.h"
// Constructor.
Perceptron::Perceptron(double initialC1,double initialC2,double initialC3,double initialLearningRate)
{
	c1 = initialC1;
	c2 = initialC2;
	c3 = initialC3;
	learningRate = initialLearningRate;
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


	while (getline(myFile, line)) { // while myFile is open and there is lines to read we assign that line to line.
		stringstream linestream(line); // create stringstream object called linestream where we pass the while loop myFile line as the variable to initialize it. 
		string cell;
		int x, y, truth;

		getline(linestream, cell, ','); // getline(stringstream object, var cell, delimiter)
		x = stoi(cell);

		getline(linestream, cell, ',');
		y = stoi(cell);

		getline(linestream, cell, ',');
		truth = stoi(cell);

		dataset.push_back(DataPoint(x, y, truth)); // adds a DataPoint object to the dataset vector.
	}
	myFile.close();
	cout << "Loaded " << dataset.size() << " data points from " << filename << endl;
}

int Perceptron::modelFunction(int x, int y)
{
	int sum = c1 + (x * c2) + (y * c3); // Model function of (c1)1 + (c2)x + (c3y
	return sum >= 0 ? 1: -1; // Cool syntax, if condition is either or use THIS : THAT. ie if (sum >= 0) is true we return 1(THIS), else -1(THAT)
}

void Perceptron::trainPerceptron()
{
	cout << "Training perceptron..." << endl;

	int epochs = 0; // Count how many iterations.
	const int MAX_EPOCHS = 1000; // Boundary for iterations.
	bool isTrainingComplete = false; // loop conditional to keep it running.

	while (!isTrainingComplete && epochs < MAX_EPOCHS) { // while isTrainingComplete is not true and epochs is less than MAX_EPOCHS
		isTrainingComplete = true;

		for (size_t i = 0; i < dataset.size(); ++i) {
			const DataPoint& dataPoint = dataset[i];                 // initialize a dataPoint object with the contents of dataset[i];
			int predicted = modelFunction(dataPoint.x, dataPoint.y); // Predicted number is the result of modelFunction, we pass in the modelFunction and the dataPoint structs values of x and y.
			int error = dataPoint.truth - predicted;                 // Generate the error variable needed for training perceptron.

			if (error != 0) {
				c1 += learningRate * error;               // c1 is the bias weight, it's updated with just the error
				c2 += learningRate * error * dataPoint.x; // c2 is the x weight, take the error and interation of X we are on with our dataPoint database.
				c3 += learningRate * error * dataPoint.y; // c3 is the x weight, take the error and interation of X we are on with our dataPoint database.
				isTrainingComplete = false;               // keep loop alive.
			}
		}
		cout << "Epoch " << epochs << ": c1 = " << c1 << ", c2 = " << c2 << ", c3 = " << c3 << endl; // output our current epoch, and the weighted coefficient values during this iteration.
		epochs++; // add 1 to our epoch counter.
	}
	// Output of perceptron training finished because it satisifed its goal, or else it ran into max epochs.
	if (epochs == MAX_EPOCHS) {
		cout << "Training stopped after reaching the maximum number of epochs." << endl;
	}
	else {
		cout << "Training complete." << endl;
	}

	// Print the final line of weighted coefficients as the values that are the trained perceptron returns.
	printResults();
}

void Perceptron::printResults()
{
	cout << "Weights: c1 = " << c1 << ", c2 = " << c2 << ", c3 = " << c3 << endl << endl;
}

int Perceptron::test(int gradeNum, int gradeDen)
{
	int result = modelFunction(gradeNum, gradeDen);
	return result;
}
