#include <iostream>
#include <cstdlib>
#include "Global_Functions.cpp"
#include "This_Has_Data.cpp"

using namespace std;

int main() {
	thing* head = new thing();
	
	vector<string> list = train();
	transform(list, head);
	
	string thisHoldsStuff;
	thing* data = new thing();

	cout << "Enter the coordinates of the function in the form x,y,z with no spaces: ";
	cin >> thisHoldsStuff;

	vector<string> info;
	info.push_back(thisHoldsStuff);
	transform(info, data); //MUST USE data->next

	thing* holder = head;
	thing* closest = new thing();
	for (int i = 0; i < list.size(); i++) {
		data->getNext()->findDistance(data->getNext(), holder);

		if (i == 0) {
			closest = holder;
		}

		else if (data->getNext()->findDistance(data->getNext(), closest) > data->getNext()->findDistance(data->getNext(), holder)) {
			closest = holder;
		}
	}
	
	data->getNext()->setOrientation(holder->getOrientation());

	whatOrientation(stoi(data->getNext()->getOrientation()));

	return 0;
}