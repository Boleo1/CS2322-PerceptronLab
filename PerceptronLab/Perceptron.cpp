#include "Perceptron.h"

Perceptron::Perceptron()
{
	int x = 0;
	int y = 0;
	int truth = 0;
}

void Perceptron::loadData(string filename)
{
	string line;
	string filePassedIn = filename;

	ifstream myFile;
	myFile.open(filePassedIn);

	if (myFile.fail()) {
		cout << "Failed to open file: " << filePassedIn << endl;
	}

	// Takes the first row of data since this will be an excel made CSV.
	string header;
	getline(myFile, header);
	cout << "This is the top row of data." << header << endl;

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

		cout << "X: " << x << ", Y: " << y << ", Truth: " << truth << endl;
	}
	myFile.close();

}

void Perceptron::trainPerceptron()
{
	cout << "This is trainPerceptron()" << endl;
}

void Perceptron::printResults()
{
	cout << "This is printResults()" << endl;
}
