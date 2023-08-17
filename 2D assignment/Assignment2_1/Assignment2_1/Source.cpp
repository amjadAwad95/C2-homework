#include<iostream>

using namespace std;

void inputArrayElement(int* number, int size);
int determinTheLowestValue(int* number, int size);
void differenceOfValueFromTheLowestone(int* number, int size, int min);

int main() {
	int number[5];
	inputArrayElement(number, 5);
	int min = determinTheLowestValue(number, 5);
	differenceOfValueFromTheLowestone(number, 5, min);
}

void inputArrayElement(int* number, int size) {
	cout << "welcome to input array element" << endl;
	for (int i = 0; i < size; i++) {
		cout << "Enter number " << i + 1 << endl;
		cin >> number[i];
	}
}

int determinTheLowestValue(int* number, int size) {
	int min=number[0];
	for (int i = 1; i < size; i++) {
		if (min > number[i]) {
			min = number[i];
		}
	}
	return min;
}

void differenceOfValueFromTheLowestone(int* number, int size, int min) {
	for (int i = 0; i < size; i++) {
		if (min != number[i]) {
			cout << "The differnce between " << number[i] << " and " << min << " = " << number[i] - min << endl;
		}
	}
}

