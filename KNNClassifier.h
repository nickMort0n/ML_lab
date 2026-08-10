#ifndef KNNCLASSIFIER_H
#define KNNCLASSIFIER_H
#include <string>

using namespace std;

class KNN {
public:
	double distance();
	string classify();
	void sort();
};
#endif