#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

void rollDices(int& number1, int& number2);
void rollProb(int matrix[][6], int numberOfRolls);

int main() {
	srand(time(NULL));
	int probabilityDices[6][6] = {0};
	rollProb(probabilityDices,1000);
	
}

void rollDices(int& number1,int&number2) {
	number1 = rand() % 6 + 1;
	number2 = rand() % 6 + 1;
}

void rollProb(int matrix[][6],int numberOfRolls) {
	int number1=0, number2=0;
	for (int i = 0; i < numberOfRolls; i++) {
		rollDices(number1, number2);
		matrix[number1 - 1][number2 - 1]++;
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cout << "The probablity to get " << i+1 << " " << j+1 << " = " << double(matrix[i][j]) / numberOfRolls << endl;
		}
	}
}
