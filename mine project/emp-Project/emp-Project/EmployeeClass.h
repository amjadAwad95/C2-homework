#pragma once
#include<iostream>
#include<string>
#include<cmath>
#include<fstream>

using namespace std;

class Employee {
protected:
	string name;
	int hireYear;
public:
	Employee(string name = "empty", int hireYear = 0) {
		this->name = name;
		this->hireYear = hireYear;
	}
	void setName(string name) {
		this->name = name;
	}
	void setHireYear(int hireYear) {
		this->hireYear = hireYear;
	}
	string getName() const{
		return this->name;
	}
	int setHireYear() const{
		return this->hireYear;
	}
	virtual double monthlyPay() const{
		return 0;
	}
	virtual double annualPay() const{
		return 0;
	}
	virtual void toFile(ofstream& fileOutput)const {
		fileOutput << name << " " << "Monthly Pay:" << monthlyPay() << " " << "Annual Pay: " << annualPay() << endl;
	}
	virtual void printInfo() const{
		cout << name<<" " << "Monthly Pay:" <<monthlyPay() << " "<<"Annual Pay: " << annualPay() << endl;
	}
	virtual string toSring()const {
		string str = name + " ";
		str += "Monthly Pay: ";
		str += to_string(monthlyPay())+" ";
		str += "Annual Pay: ";
		str += to_string(annualPay());
		return str;
	}
};
class SalariedEmployee :public Employee {
protected:
	int annualSalary;
public:
	SalariedEmployee(string name, int hireYear, int annualSalary = 0) :Employee(name, hireYear) {
		this->annualSalary = annualSalary;
	}
	void setAnnualSalary(int annualSalary) {
		this->annualSalary = annualSalary;
	}
	int getAnnualSalary()const {
		return this->annualSalary;
	}
	double monthlyPay()const {
		return this->annualSalary / 12.0;
	}
	virtual void printInfo() const {
		cout << name << " " << "Monthly Pay:" << monthlyPay() << " " << "Annual Pay: " << annualPay() << endl;
	}
	virtual void toFile(ofstream& fileOutput)const {
		fileOutput << name << " " << "Monthly Pay:" << monthlyPay() << " " << "Annual Pay: " << annualPay() << endl;
	}
	virtual string toSring()const {
		string str = name + " ";
		str += "Monthly Pay: ";
		str += to_string(monthlyPay()) + " ";
		str += "Annual Pay: ";
		str += to_string(annualPay());
		return str;
	}
};
class HourlyEmployee :public Employee {
protected:
	int HoursPerWeek;
	double hourlyWage;
public:
	HourlyEmployee(string name, int hireYear, int HoursPerWeek,double hourlyWage) :Employee(name, hireYear) {
		this->HoursPerWeek = HoursPerWeek;
		this->hourlyWage = hourlyWage;
	}
	void setHoursPerWeek(int HoursPerWeek) {
		this->HoursPerWeek = HoursPerWeek;
	}
	void sethourlyWage(double hourlyWage) {
		this->hourlyWage = hourlyWage;
	}
	int getHoursPerWeek() const{
		return this->HoursPerWeek;
	}
	double gethourlyWage() const{
		return this->hourlyWage;
	}
	double monthlyPay() const {
		return this->HoursPerWeek * 4.0 * this->hourlyWage;
	}
	virtual void printInfo() const {
		cout << name << " " << "Monthly Pay:" << monthlyPay() << " " << "Annual Pay: " << annualPay() << endl;
	}
	virtual void toFile(ofstream& fileOutput)const {
		fileOutput << name << " " << "Monthly Pay:" << monthlyPay() << " " << "Annual Pay: " << annualPay() << endl;
	}
	virtual string toSring()const {
		string str = name + " ";
		str += "Monthly Pay: ";
		str += to_string(monthlyPay()) + " ";
		str += "Annual Pay: ";
		str += to_string(annualPay());
		return str;
	}
};
class Manager :public SalariedEmployee {
public:
	Manager(string name, int hireYear, int annualSalary = 0) :SalariedEmployee(name,hireYear,annualSalary) {
	}
	double annualPay() const {
		return this->annualSalary + (this->annualSalary * 0.10);
	}
	virtual void printInfo() const {
		cout << name << " " << "Monthly Pay:" << monthlyPay() << " " << "Annual Pay: " << annualPay() << endl;
	}
	virtual void toFile(ofstream& fileOutput)const {
		fileOutput << name << " " << "Monthly Pay:" << monthlyPay() << " " << "Annual Pay: " << annualPay() << endl;
	}
	virtual string toSring()const {
		string str = name + " ";
		str += "Monthly Pay: ";
		str += to_string(monthlyPay()) + " ";
		str += "Annual Pay: ";
		str += to_string(annualPay());
		return str;
	}
};
class Staff :public SalariedEmployee {
public:
	Staff(string name, int hireYear, int annualSalary = 0) :SalariedEmployee(name, hireYear, annualSalary ) {
	}
	double annualPay() const {
		time_t currentTime;
		time(&currentTime);
		tm currentTm;
		localtime_s(&currentTm, &currentTime);

		// Extract the year from the calendar time
		int currentYear = currentTm.tm_year + 1900;
		if ((currentYear) - hireYear >= 5)
		{
			return annualSalary + (10 / annualSalary * 100);
		}
		else if ((currentYear) - hireYear == 4)
		{
			return annualSalary + (8 / annualSalary * 100);
		}
		else if ((currentYear) - hireYear == 3)
		{
			return annualSalary + (6 / annualSalary * 100);
		}
		else if ((currentYear) - hireYear == 2)
		{
			return annualSalary + (4 / annualSalary * 100);
		}
		else if ((currentYear) - hireYear == 1)
		{
			return annualSalary + (2 / annualSalary * 100);
		}
		else
		{
			return annualSalary;
		}
	}
	virtual void printInfo() const {
		cout << name << " " << "Monthly Pay:" << monthlyPay() << " " << "Annual Pay: " << annualPay() << endl;
	}
	virtual void toFile(ofstream& fileOutput)const {
		fileOutput << name << " " << "Monthly Pay:" << monthlyPay() << " " << "Annual Pay: " << annualPay() << endl;
	}
	virtual string toSring()const {
		string str = name + " ";
		str += "Monthly Pay: ";
		str += to_string(monthlyPay()) + " ";
		str += "Annual Pay: ";
		str += to_string(annualPay());
		return str;
	}
};
class FullTime :public HourlyEmployee {
public:
	FullTime(string name, int hireYear, int HoursPerWeek = 0, double hourlyWage = 0) :
		HourlyEmployee(name, hireYear, HoursPerWeek, hourlyWage) {

	}
	double annualPay() const {
		return (50*this->hourlyWage) + (2 * this->hourlyWage);
	}
	virtual void printInfo() const {
		cout << name << " " << "Monthly Pay:" << monthlyPay() << " " << "Annual Pay: " << annualPay() << endl;
	}
	virtual void toFile(ofstream& fileOutput)const {
		fileOutput << name << " " << "Monthly Pay:" << monthlyPay() << " " << "Annual Pay: " << annualPay() << endl;
	}
	virtual string toSring()const {
		string str = name + " ";
		str += "Monthly Pay: ";
		str += to_string(monthlyPay()) + " ";
		str += "Annual Pay: ";
		str += to_string(annualPay());
		return str;
	}
};
class PartTime :public HourlyEmployee  {
public:
	PartTime(string name, int hireYear, int HoursPerWeek = 0, double hourlyWage = 0) :
		HourlyEmployee(name, hireYear, HoursPerWeek, hourlyWage) {

	}
	double annualPay() const {
		return (50*this->HoursPerWeek);
	}
	virtual void printInfo() const {
		cout << name << " " << "Monthly Pay:" << monthlyPay() << " " << "Annual Pay: " << annualPay() << endl;
	}
	virtual void toFile(ofstream& fileOutput)const {
		fileOutput << name << " " << "Monthly Pay:" << monthlyPay() << " " << "Annual Pay: " << annualPay() << endl;
	}
	virtual string toSring()const {
		string str = name + " ";
		str += "Monthly Pay: ";
		str += to_string(monthlyPay()) + " ";
		str += "Annual Pay: ";
		str += to_string(annualPay());
		return str;
	}
};