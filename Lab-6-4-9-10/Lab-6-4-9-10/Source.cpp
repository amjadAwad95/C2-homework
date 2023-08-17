#include<iostream>
#include<fstream>

using namespace std;

struct Student {
	int studentNumber;
	char name[100];
	int studentMark[5];
};

void printStudent(Student*& student, int size);
int numberOfStudentFailed(Student*& student, int size);
Student* studentsFailed(Student*& student, int size);

int main() {
	fstream studentFile;
	studentFile.open("student.txt",ios::in);
	if (!studentFile.is_open()) {
		cout << "error in file" << endl;
		return 1;
	}
	Student* student=new Student[25];
	for (int i = 0; i < 25; i++) {
		studentFile >> student[i].studentNumber;
		studentFile >> student[i].name;
		for (int j = 0; j < 5; j++) {
			studentFile >> student[i].studentMark[j];
		}
	}
	int numberFailed = numberOfStudentFailed(student,25);
	Student* failed = studentsFailed(student, 25);
	printStudent(failed, numberFailed);
	studentFile.close();
	delete[] student;
	delete[] failed;
}

void printStudent(Student*& student, int size) {
	for (int i = 0; i < size; i++) {
		cout << student[i].studentNumber << " ";
		cout << student[i].name << " ";
		for (int j = 0; j < 5; j++) {
			cout << student[i].studentMark[j] << " ";
		}
		cout << endl;
	}
}

int numberOfStudentFailed(Student*& student, int size) {
	int numberFailed = 0;
	for (int i = 0; i < size; i++) {
		int count = 0;
		for (int j = 0; j < 5; j++) {
			if (student[i].studentMark[j] < 60) {
				count++;
			}
		}
		if (count >= 2) {
			numberFailed++;
		}
	}
	return numberFailed;
}

Student* studentsFailed(Student*& student, int size) {
	int numberFailde=numberOfStudentFailed(student,size);
	Student* failed = new Student[numberFailde];
	for (int i = 0,k=0; i < size; i++) {
		int count = 0;
		for (int j = 0; j < 5; j++) {
			if (student[i].studentMark[j] < 60) {
				count++;
			}
		}
		if (count >= 2) {
			failed[k] = student[i];
			k++;
		}
	}
	return failed;
}