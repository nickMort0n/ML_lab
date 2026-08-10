#include <iostream>
#include <cstdlib>
#include "base.cpp"
#include "This_Has_Data.cpp"

using namespace std;

int main() {
	thing* head = (thing*)malloc(sizeof(thing));
	
	vector<string> list = train();
	transform(list, head);
	
	return 0;
}