#include<iostream>

using namespace std;

void addSalesman(int* id, int* salary, int* phoneNumber, int size, int salary1, int phone);
bool cheakCell(int* id, int size, int& counter);
void deleteSalesman(int* id, int* salary, int* phoneNumber, int size, int cell);
bool search(int* id, int ID, int size);

int main() {
	int cell;
	cout << "Enter cell number" << endl;
	cin >> cell;
	int* id = new int[cell] {11, 12, 13};
	int* salary = new int[cell] {100, 150, 250};
	int* phoneNumber = new int[cell] { 2388888, 2377777, 2355555 };
	int choseNumber;
	int counter = 2;

	do {
		cout << "1. Add a salesman" << endl;
		cout << "2. Delete a salesman" << endl;
		cout << "3. Search for a salesman by his ID" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter number to make a task" << endl;
		cin >> choseNumber;
		cout << "-----------------------------------------------" << endl;
		if (choseNumber < 0 || choseNumber >= 5) {
			cout << "You are enter number out of the range" << endl;
			return 1;
		}
		if (choseNumber == 1) {
			if (cheakCell(id, cell, counter)) {
				int  Salary, phone;
				do {
					cout << "Enter salary of salesman" << endl;
					cin >> Salary;
				} while (Salary <= 0);
				do {
					cout << "Enter phone number for salesman" << endl;
					cin >> phone;
				} while (phone <= 0);
				addSalesman(id, salary, phoneNumber, cell, Salary, phone);
				cout << "-----------------------------------------------" << endl;
			}
			else {
				cout << "Sorry, the company has enough salesmen at the current time, if you want to add a newsalesman, you should delete one first." << endl;
				cout << "-----------------------------------------------" << endl;
			}
		}
		else if (choseNumber == 2) {
			int choseDel;
			cout << "Enter what cell you want delete" << endl;
			cin >> choseDel;
			deleteSalesman(id, salary, phoneNumber, cell, choseDel);
			counter--;
			cout << "-----------------------------------------------" << endl;
		}
		else if (choseNumber == 3) {
			int idSearch;
			cout << "Enter id for Salesman who want search" << endl;
			cin >> idSearch;
			if (search(id, idSearch, cell)) {
				cout << "Found" << endl;
				cout << "-----------------------------------------------" << endl;
			}
			else {
				cout << "Not found" << endl;
				cout << "-----------------------------------------------" << endl;
			}
		}
	} while (choseNumber != 4);
	cout << "--------------------------------------------------------" << endl;
	for (int i = 0; i < counter + 1; i++) {
		cout << "Salesman" << i + 1 << endl;
		cout << id[i] << endl << salary[i] << endl << phoneNumber[i] << endl;
	}
	delete[] id;
	delete[] salary;
	delete[] phoneNumber;

}
bool cheakCell(int* id, int size, int& counter) {

	if (size - 1 > counter) {
		counter++;
		return true;
	}
	return false;
}
void addSalesman(int* id, int* salary, int* phoneNumber, int size, int salary1, int phone) {
	static int id1 = 14;
	for (int i = 0; i < size; i++) {
		if (id[i] == 0) {
			id[i] = id1++;
			salary[i] = salary1;
			phoneNumber[i] = phone;
			return;
		}
	}
}

void deleteSalesman(int* id, int* salary, int* phoneNumber, int size, int cell) {
	int i;
	for (i = cell - 1; i < size; i++) {
		if (i == size - 1) {
			id[i] = 0;
			salary[i] = 0;
			phoneNumber[i] = 0;
		}
		else {
			id[i] = id[i + 1];
			salary[i] = salary[i + 1];
			phoneNumber[i] = phoneNumber[i + 1];
		}
	}

}

bool search(int* id, int ID, int size) {
	for (int i = 0; i < size; i++) {
		if (id[i] == ID) {
			return true;
		}
	}
	return false;
}