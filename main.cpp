#include <iostream>
#include <cstdlib>
#include "NN.cpp"
#include "This_Has_Data.cpp"

using namespace std;

int main() {
	thing* head = new thing(); //head of the list
	string trainingFile = "trainingData.txt";
	vector<string> list = train(trainingFile); //training data used to make a list
	transform(list, head);
	
	string thisHoldsStuff; //just read the variable name.
	thing* data = new thing(); //used to start a new "list"
	int selection;
	
	cout << "Please select a method:\n1. NN\n2. KNN\n3. AnotherClassifier\nPlease make your selection: ";
	cin >> selection;

	if (selection != 1) {
		cout << "This method is not implemented yet.";
		return 0;
	}

	int nSelection;

	cout << "Please select one of the following.\n1. One data point\n2. Multiple data points (requires file)\nMake your choice: ";
	cin >> nSelection;
	
	if (nSelection == 1) {
		cout << "Enter the coordinates in the form x,y,z with no spaces: ";
		cin >> thisHoldsStuff;

		vector<string> info; //new string for new data
		info.push_back(thisHoldsStuff); //adds the user input to the new vector

		transform(info, data); //input turned into a usable object

		thing* nData = data->getNext(); //just so I don't need to constantly use data->getNext()->doSomething()
		delete data; //frees the memory from data bc it's not needed anymore
		
		findOrientation(nData, head);

		cout << nData->whatOrientation(stoi(nData->getOrientation())) << endl; //prints the orientation
	}

	if (nSelection == 2) {
		string fileName;
		cout << "Please enter the name of the current file: ";
		cin >> fileName;

		printToFile(fileName, head); //simplified because I did this on another day and am too lazy to simplify nSelection 1
	}

	return 0;
}