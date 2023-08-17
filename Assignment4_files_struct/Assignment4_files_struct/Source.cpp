#include<iostream>
#include<fstream>

using namespace std;

struct Address {
	char* streetName;
	char* cityName;
};

struct Employees
{
	char name[100];
	int ID;
	int age;
	int salary;
	Address empAddress;
};

int numberOfEmployees(char* path);
char* getStreetName(char* fullAddres, char* first);
char* getCityName(char* fullAddres);
bool isFound(Employees* data, int id, int size);
int getIndexById(Employees* data, int id, int size);
void printEmplyees(Employees data);


int main() {
	char path[100];
	cout << "Enter file path" << endl;
	cin >> path;
	ifstream employeesFile;
	employeesFile.open(path);
	if (!employeesFile.is_open()) {
		cout << "FILE NOT OPEN" << endl;
		return 1;
	}
	int employeesCount = numberOfEmployees(path);
	if (employeesCount == 0) {
		cout << "NO EMPLOYEES" << endl;
		return 1;
	}
	Employees* employeesData = new Employees[employeesCount];
	for (int i = 0; i < employeesCount; i++) {
		employeesFile >> employeesData[i].name >> employeesData[i].ID;
		char temp[100];
		char temp2[100];
		employeesFile >> temp>>temp2;
		employeesData[i].empAddress.streetName= getStreetName(temp2,temp);
		employeesData[i].empAddress.cityName= getCityName(temp2);
		employeesFile >> employeesData[i].age >> employeesData[i].salary;
	}
	int id;
	cout << "Enter The id" << endl;
	cin >> id;
	int index = getIndexById(employeesData, id, employeesCount);
	if (index == -1) {
		for (int i = 0; i < employeesCount; i++) {
			delete[] employeesData[i].empAddress.cityName;
			delete[] employeesData[i].empAddress.streetName;
		}
		delete[] employeesData;
		employeesFile.close();
		cout << "EMPLOYEE NOT FOUND" << endl;
		return 1;
	}
	printEmplyees(employeesData[index]);
	for (int i = 0; i < employeesCount; i++) {
		delete[] employeesData[i].empAddress.cityName;
		delete[] employeesData[i].empAddress.streetName;
	}
	employeesFile.close();
}
int numberOfEmployees(char* path) {
	ifstream employeesFile;
	employeesFile.open(path);
	if (!employeesFile.is_open()) {
		employeesFile.close();
		return 0;
	}
	char temp[100];
	int employessCount = 0;
	while (employeesFile.getline(temp, 100)) {
		employessCount++;
	}
	employeesFile.close();
	return employessCount;
}

char* getStreetName(char* fullAddres,char* first) {
	char* address=new char[100];
	int i,j;
	strcpy_s(address, 100, first);
	strcat_s(address, 100, " ");
	j = strlen(first)+1;
	for (i = 0; fullAddres[i] != '-'; i++,j++) {
		address[j] = fullAddres[i];
	}
	address[j] = '\0';
	return address;
}
char* getCityName(char* fullAddres) {
	char* city = new char[100];
	int i,j;
	for (i = 0; fullAddres[i] != '-'; i++);
	i++;
	for (j=0; fullAddres[i]; i++, j++) {
		city[j] = fullAddres[i];
	}	
	city[j] = '\0';
	return city;
}
bool isFound(Employees* data,int id,int size) {
	for (int i = 0; i < size; i++) {
		if (data[i].ID == id) {
			return true;
		}
	}
	return false;
}
int getIndexById(Employees* data, int id, int size) {
	if (isFound(data, id, size)) {
		for (int i = 0; i < size; i++) {
			if (data[i].ID == id) {
				return i;
			}
		}
	}
	return -1;
}
void printEmplyees(Employees data) {
	cout << data.name << " " << data.ID << " " << data.empAddress.streetName << "-" << data.empAddress.cityName << " "
		<< data.age << " " << data.salary << endl;
}