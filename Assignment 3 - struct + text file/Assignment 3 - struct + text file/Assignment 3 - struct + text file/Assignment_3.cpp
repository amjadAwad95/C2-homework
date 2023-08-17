#include<iostream>
#include<fstream>

#define MAXSIZE 1000

using namespace std;

struct Car {
	char id[20];
	char make[20];
	char model[20];
	int year;
	char color[20];
	int engine;
	int price;
};

void printTheMenu();
void printCarInfo(Car& car);
void getCarDataFromFile(fstream& carFile, Car*& car, int size);
bool foundById(Car*& car, int size, char* ID);
int foundLocationById(Car*& car, int size, char* ID);
void updateRec(Car*& car, int size);
void addRecord(Car*& car, int& size);
void deleteRecord(Car*& car, int& size);
void display(Car*& car, int size);
void displayByPrice(Car*& car, int size);
void displayByMake(Car*& car, int size);
void displayByYear(Car*& car, int size);
void displaySortedPrice(Car* car, int size);
void displaySortedYear(Car* car, int size);
void saveDataInFile(fstream& file, Car*& car, int size);

int main() {
	fstream carFile;
	carFile.open("cars.txt",ios::in);
	if (!carFile.is_open()) {
		cout << "You have an error in the file" << endl;
		return 1;
	}
	int numberOfTheCar;
	carFile >> numberOfTheCar;
	Car* car = new Car[MAXSIZE];
	getCarDataFromFile(carFile, car, numberOfTheCar);
	printTheMenu();
	int choose;
	while (cin >> choose) {
		if (choose == 10) {
			break;
		}
		switch (choose) {
		case 1:
			addRecord(car, numberOfTheCar);
			break;
		case 2:
			deleteRecord(car, numberOfTheCar);
			break;
		case 3:
			updateRec(car, numberOfTheCar);
			break;
		case 4:
			display(car, numberOfTheCar);
			break;
		case 5:
			displayByPrice(car, numberOfTheCar);
			break;
		case 6:
			displayByMake(car, numberOfTheCar);
			break;
		case 7:
			displaySortedPrice(car, numberOfTheCar);
			break;
		case 8:
			displaySortedYear(car, numberOfTheCar);
			break;
		case 9:
			carFile.close();
			carFile.open("cars.txt", ios::out);
			saveDataInFile(carFile, car, numberOfTheCar);
			break;

		}
		cout << "-----------------------------------" << endl;
		printTheMenu();
	}
	carFile.close();
	delete[] car;
}
void printTheMenu() {
	cout << "1) Add a car record" << endl;
	cout << "2) Delete a car record" << endl;
	cout << "3) Update a car record" << endl;
	cout << "4) view all car records" << endl;
	cout << "5) view cars with price less than value" << endl;
	cout << "6) view cars by  car make" << endl;
	cout << "7) view all cars sorted by price" << endl;
	cout << "8) view all cars sorted by year" << endl;
	cout << "9) save" << endl;
	cout << "10) quit" << endl;
}
void printCarInfo(Car& car) {
	
		cout << car.id << "\t" << car.make << " \t" << car.model << "\t" << car.year
			<< "\t" << car.color << "\t" << car.engine << "\t" << car.price << endl;
	
}
void display(Car*& car, int size) {
	cout << "-----------------------------------" << endl;
	for (int i = 0; i < size; i++) {
		cout << car[i].id << "\t" << car[i].make << "\t" << car[i].model << "\t" << car[i].year
			<< "\t" << car[i].color << "\t" << car[i].engine << "\t" << car[i].price << endl;
	}
}
void getCarDataFromFile(fstream& carFile, Car*& car, int size) {
	for (int i = 0; i < size; i++) {
		carFile >> car[i].id;
		carFile >> car[i].make;
		carFile >> car[i].model;
		carFile >> car[i].year;
		carFile >> car[i].color;
		carFile >> car[i].engine;
		carFile >> car[i].price;
	}
}

bool foundById(Car*& car, int size,char* ID) {
	for (int i = 0; i < size; i++) {
		if (strcmp(ID, car[i].id) == 0) {
			return true;
		}
	}
	return false;
}
int foundLocationById(Car*& car, int size, char* ID) {
	for (int i = 0; i < size; i++) {
		if (strcmp(ID, car[i].id) == 0) {
			return i;
		}
	}
	return -1;
}

void updateRec(Car*& car, int size) {
	cout << "Enter the ID you are looking for" << endl;
	char ID[20];
	cin >> ID;
	bool found = foundById(car,size,ID);
	int idLocation=foundLocationById(car, size, ID);
	if (found == false) {
		cout << "The car id not found" << endl;
		return;
	}
	Car tempCar;
	cout << "-----------------------------------" << endl;
	cout << "Enter car id" << endl;
	cin >> tempCar.id;
	cout << "Enter car make" << endl;
	cin >> tempCar.make;
	cout << "Enter car model" << endl;
	cin >> tempCar.model;
	cout << "Enter car year" << endl;
	cin >> tempCar.year;
	cout << "Enter car color" << endl;
	cin >> tempCar.color;
	cout << "Enter car engine" << endl;
	cin >> tempCar.engine;
	cout << "Enter car price" << endl;
	cin >> tempCar.price;
	cout << "-----------------------------------" << endl;
	printCarInfo(tempCar);
	cout << "-----------------------------------" << endl;
	cout << "do you want to update the data if yes press 1 if n press 2" << endl;
	int choose;
	cin >> choose;
	if (choose == 1) {
		car[idLocation] = tempCar;
	}
}

void addRecord(Car*& car, int& size) {
	if (size > MAXSIZE) {
		return;
	}
	size++;
	Car tempCar;
	cout << "-----------------------------------" << endl;
	cout << "Enter car id" << endl;
	cin >> tempCar.id;
	cout << "Enter car make" << endl;
	cin >> tempCar.make;
	cout << "Enter car model" << endl;
	cin >> tempCar.model;
	cout << "Enter car year" << endl;
	cin >> tempCar.year;
	cout << "Enter car color" << endl;
	cin >> tempCar.color;
	cout << "Enter car engine" << endl;
	cin >> tempCar.engine;
	cout << "Enter car price" << endl;
	cin >> tempCar.price;
	cout << "-----------------------------------" << endl;
	printCarInfo(tempCar);
	cout << "-----------------------------------" << endl;
	cout << "do you want to update the data if yes press 1 if no press 2" << endl;
	int choose;
	cin >> choose;
	if (choose == 1) {
		car[size-1] = tempCar;
	}
}

void deleteRecord(Car*& car, int &size) {
	char ID[20];
	cout << "Enter the ID to be deleted" << endl;
	cin >> ID;
	bool found = foundById(car, size, ID);
	if (!found) {
		cout << "The id not found" << endl;
		return;
	}
	int location = foundLocationById(car, size, ID);
	Car* tempCar = new Car[size - 1];
	for (int i = 0,k=0; i < size;i++) {
		if (i != location) {
			tempCar[k] = car[i];
			k++;
		}
	}
	cout << "-----------------------------------" << endl;
	printCarInfo(car[location]);
	cout << "-----------------------------------" << endl;
	cout << "Do you want to delete this id if yes press 1 if no press 2" << endl;
	int choose;
	cin >> choose;
	if (choose == 1) {
		cout << "Delete done" << endl;
		delete[] car;
		car = tempCar;
		size--;
	}
}

void displayByPrice(Car*& car, int size) {
	int price;
	cout << "Enter the peice" << endl;
	cin >> price;
	cout << "-----------------------------------" << endl;
	for (int i = 0; i < size; i++) {
		if (car[i].price < price) {
			printCarInfo(car[i]);
		}
	}
}

void displayByMake(Car*& car, int size) {
	char make[20];
	cout << "Enter car make" << endl;
	cin >> make;
	cout << "-----------------------------------" << endl;
	for (int i = 0; i < size; i++) {
		if (strcmp(car[i].make,make)==0) {
			printCarInfo(car[i]);
		}
	}
}

void displayByYear(Car*& car, int size) {
	int year;
	cout << "Enter the year" << endl;
	cin >> year;
	cout << "-----------------------------------" << endl;
	for (int i = 0; i < size; i++) {
		if (car[i].year == year) {
			printCarInfo(car[i]);
		}
	}
}

void displaySortedPrice(Car* car, int size) {
	Car* car1=new Car[size];
	for (int j = 0; j < size; j++) {
		strcpy_s(car1[j].id, car[j].id);
		strcpy_s(car1[j].model, car[j].model);
		strcpy_s(car1[j].make, car[j].make);
		car1[j].year = car[j].year;
		strcpy_s(car1[j].color, car[j].color);
		car1[j].price = car[j].price;
		car1[j].engine = car[j].engine;
	}
	for (int i = 0; i < size; i++) {
		int sort = 0;
		for (int j = 0; j < (size - i - 1); j++) {
			if (car1[j].price > car1[j + 1].price) {
				Car temp = car1[j];
				strcpy_s(car1[j].id, car1[j + 1].id);
				strcpy_s(car1[j].model, car1[j + 1].model);
				strcpy_s(car1[j].make, car1[j + 1].make);
				car1[j].year = car1[j + 1].year;
				strcpy_s(car1[j].color, car1[j + 1].color);
				car1[j].price = car1[j + 1].price;
				car1[j].engine = car1[j + 1].engine;
				//--------------------------------------
				strcpy_s(car1[j+1].id, temp.id);
				strcpy_s(car1[j+1].model, temp.model);
				strcpy_s(car1[j+1].make, temp.make);
				car1[j+1].year = temp.year;
				strcpy_s(car1[j+1].color, temp.color);
				car1[j+1].price = temp.price;
				car1[j+1].engine = temp.engine;
				sort = 1;
			}
		}
		if (sort == 0) {
			break;
		}
	}
	cout << "-----------------------------------" << endl;
	display(car1, size);
	delete[]car1;
}
void displaySortedYear(Car* car, int size) {
	Car* car1 = new Car[size];
	for (int j = 0; j < size; j++) {
		strcpy_s(car1[j].id, car[j].id);
		strcpy_s(car1[j].model, car[j].model);
		strcpy_s(car1[j].make, car[j].make);
		car1[j].year = car[j].year;
		strcpy_s(car1[j].color, car[j].color);
		car1[j].price = car[j].price;
		car1[j].engine = car[j].engine;
	}
	for (int i = 0; i < size; i++) {
		int sort = 0;
		for (int j = 0; j < (size - i - 1); j++) {
			if (car1[j].year > car1[j + 1].year) {
				Car temp = car1[j];
				strcpy_s(car1[j].id, car1[j + 1].id);
				strcpy_s(car1[j].model, car1[j + 1].model);
				strcpy_s(car1[j].make, car1[j + 1].make);
				car1[j].year = car1[j + 1].year;
				strcpy_s(car1[j].color, car1[j + 1].color);
				car1[j].price = car1[j + 1].price;
				car1[j].engine = car1[j + 1].engine;
				//--------------------------------------
				strcpy_s(car1[j + 1].id, temp.id);
				strcpy_s(car1[j + 1].model, temp.model);
				strcpy_s(car1[j + 1].make, temp.make);
				car1[j + 1].year = temp.year;
				strcpy_s(car1[j + 1].color, temp.color);
				car1[j + 1].price = temp.price;
				car1[j + 1].engine = temp.engine;
				sort = 1;
			}
		}
		if (sort == 0) {
			break;
		}
	}
	cout << "-----------------------------------" << endl;
	display(car1, size);
	delete[]car1;
}

void saveDataInFile(fstream& file, Car*& car, int size) {
	file << size << endl;
	for (int i = 0; i < size; i++) {
		file << car[i].id << " " << car[i].make << " " << car[i].model << " " << car[i].year
			<< " " << car[i].color << " " << car[i].engine << " " << car[i].price << endl;
	}
}
/*5 
1	honda civic 2002 red 1400 70000 
2	ford torus 2005 white 1800 60000 
3	honda accord 2001 black 1600 60000 
4	kia forte 2001 blue 1800 45000 
5	kia sorato 2001 silver 1600 42000 
*/