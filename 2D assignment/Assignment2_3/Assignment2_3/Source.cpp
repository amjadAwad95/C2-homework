#include<iostream>

using namespace std;

bool cheakIfMagicSquareMatrix(int matrix[][3], int row, int col);
void inputMatrixElement(int matrix[][3], int row, int col);

int main() {
	int matrix[3][3];
	inputMatrixElement(matrix, 3, 3);
	int number = matrix[0][0] + matrix[0][1] + matrix[0][2];
	if (cheakIfMagicSquareMatrix(matrix, 3, 3)) {
		cout << "The matrix is a magic matrix with a magic constant = "<<number << endl;
	}
	else {
		cout << "The matrix is not a magic matrix" << endl;
	}
}
bool cheakIfMagicSquareMatrix(int matrix[][3],int row,int col) {
	int number = matrix[0][0] + matrix[0][1] + matrix[0][2];
	int sum = 0;
	for (int i = 0; i < row; i++) {
		sum = 0;
		for (int j = 0; j < col; j++) {
			sum += matrix[i][j];
		}
		if (sum != number) {
			return false;
		}
	}
	for (int i = 0; i < col; i++) {
		sum = 0;
		for (int j = 0; j < row; j++) {
			sum += matrix[j][i];
		}
		if (sum != number) {
			return false;
		}
	}
	sum = 0;
	for (int i = 0; i < row; i++) {
		sum += matrix[i][i];
	}
	if (sum != number) {
		return false;
	}
	sum = 0;
	int count = col - 1;
	for (int i = 0; i < row; i++) {
		sum += matrix[i][count--];
	}
	if (sum != number) {
		return false;
	}
	return true;
}
void inputMatrixElement(int matrix[][3], int row, int col) {
	for (int i = 0; i < row; i++) {
		cout << "Enter row" << i + 1 << endl;
		for (int j = 0; j < col; j++) {
			cout << "Enter colm" << j + 1<<endl;
			cin>>matrix[i][j];
		}
	}
}