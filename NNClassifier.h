#ifndef NNCLASSIFIER_H
#define NNCLASSIFIER_H
#include <string>
#include <vector>
#include "thing.h"

using namespace std;

class NN : protected thing {
public:
	NN();
	NN* thingToNN(thing*);
	vector<string> train(string);
	void printToFile(string, NN*);
};
#endif