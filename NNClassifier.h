#pragma once
#include <string>
#include <vector>
#include "This_Has_Data.cpp"

using namespace std;

class NNClassifier {
public:
	NNClassifier();
	~NNClassifier();

	vector<string> train(string);
	void transform(vector<string>, thing*);
	void printToFile(string, thing*);
};