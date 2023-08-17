#include<iostream>
#include<fstream>
#include<string>
#include"EmployeeClass.h"

using namespace std;

string toLower(string str);

int main() {
	ifstream employeeFile;
	employeeFile.open("EmployeeData.txt");
	if (!employeeFile.is_open()) {
		cout << "Error in a file" << endl;
		return 1;
	}
	int numberOfEmployee = 0;
	string temp;
	while (getline(employeeFile, temp)) {
		numberOfEmployee++;
	}
	employeeFile.close();
	employeeFile.open("EmployeeData.txt");
	if (!employeeFile.is_open()) {
		cout << "Error in a file" << endl;
		return 1;
	}
	Employee **employeeData=new Employee*[numberOfEmployee];
	for (int i = 0; i < numberOfEmployee; i++) {
		employeeFile >> temp;
		if (toLower(temp) == "staff") {
			string name;
			int hireYear;
			int annualSalary;
			employeeFile >> name >> hireYear >> annualSalary;
			employeeData[i] = new Staff(name,hireYear,annualSalary);
		}
		else if (toLower(temp) == "manager") {
			string name;
			int hireYear;
			int annualSalary;
			employeeFile >> name >> hireYear >> annualSalary;
			employeeData[i] = new Manager(name, hireYear, annualSalary);
		}
		else if (toLower(temp) == "parttime") {
			string name;
			int hireYear;
			int HoursPerWeek;
			double hourlyWage;
			employeeFile >> name >> hireYear >> HoursPerWeek >> hourlyWage;
			employeeData[i] = new PartTime(name, hireYear, HoursPerWeek, hourlyWage);
		}
		else if (toLower(temp) == "fulltime") {
			string name;
			int hireYear;
			int HoursPerWeek;
			double hourlyWage;
			employeeFile >> name >> hireYear >> HoursPerWeek >> hourlyWage;
			employeeData[i] = new FullTime(name, hireYear, HoursPerWeek, hourlyWage);
		}
	}
	ofstream fileOutput("EmployeeOutput.txt", ios::app);
	for (int i = 0; i < numberOfEmployee; i++) {
		cout << employeeData[i]->toSring() << endl;;
		employeeData[i]->toFile(fileOutput);
	}
	delete[] employeeData;
	employeeFile.close();
	fileOutput.close();
}
string toLower(string str) {
	string temp = str;
	for (int i = 0; temp[i]; i++) {
		if (temp[i] >= 'A' and temp[i] <= 'Z') {
			temp[i] = temp[i]+32;
		}
	}
	return temp;
}