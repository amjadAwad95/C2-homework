#include<iostream>

using namespace std;

void inputArrayElement(int* number, int size);
bool checkElementInArray(int* number, int size, int element);

int main() {
	int number[5];
	inputArrayElement(number, 5);
	int element;
	cout << "Enter an integer to search for: ";
	cin >> element;
	if (checkElementInArray(number, 5, element)) {
		cout<<element<<" is in the array of numbers";
	}
	else {
		cout << element << " is not in the array of numbers";
	}
}

void inputArrayElement(int* number, int size) {
	cout << "welcome to input array element" << endl;
	for (int i = 0; i < size; i++) {
		cout << "Enter number " << i + 1 << endl;
		cin >> number[i];
	}
}

bool checkElementInArray(int* number, int size, int element) {
	for (int i = 0; i < size; i++) {
		if (number[i] == element) {
			return true;
		}
	}
	return false;
}