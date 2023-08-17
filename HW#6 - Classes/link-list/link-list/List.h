#pragma once
#include<iostream>
#include"Node.h"

using namespace std;

template<typename T>

class List {
private:
	Node<T>* head;
public:
	List() {
		head = nullptr;
	}
	void append(T data) {
		Node<T>* newNode = new Node<T>(data);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		Node<T>* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
	void insert(int index,T data) {
		Node<T>* newNode = new Node<T>(data);
		Node<T>* temp = head;
		if (index == 0) {
			newNode->next = head;
			head = newNode;
			return;
		}
		int listSize = 0;
		while (temp->next != nullptr) {
			temp = temp->next;
			listSize++;
		}
		if (index > listSize || index < 0) {
			return;
		}
		temp = head;
		for (int i = 0; i < index-1; i++) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next= newNode;
	}
	int size() {
		Node<T>* temp = head;
		if (head == nullptr) {
			return 0;
		}
		int listSize = 1;
		while (temp->next != nullptr) {
			temp = temp->next;
			listSize++;
		}
		return listSize;
	}
	bool isEqual(List<T>& list) {
		int thisSize = this->size();
		if (thisSize != list.size()) {
			return false;
		}
		for (int i = 0; i < thisSize; i++) {
			int j;
			for (j = 0; j < thisSize; j++) {
				if (this->operator[](i) == list[j]) {
					break;
				}
			}
			if (j == thisSize) {
				return false;
			}
		}
		return true;
	}
	bool operator ==(List<T>& list) {
		if (this->size() != list.size()) {
			return false;
		}
		int thisSize = this->size();
		for (int i = 0; i < thisSize; i++) {
			if (this->operator[](i) != list[i]) {
				return false;
			}
		}
		return true;
	}
	bool  in(T dataIn) {
		Node<T> temp = head;
		while (temp->next) {
			if (temp->data == dataIn) {
				return true;
			}
		}
		return false;
	}
	T operator [](int index) {
		Node<T>* temp = head;
		int listSize = this->size();
		if (index > listSize || index < 0) {
			return NULL;
		}
		temp = head;
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		return temp->data;
	}
	void printList() {
		Node<T>* temp = head;
		cout << "[";
		while (temp->next != nullptr) {
			cout << temp->data;
			temp = temp->next;
			cout << ",";
		}
		cout << temp->data << "]" << endl;
	}
	friend ostream& operator<<(ostream& out, const List& list) {
		Node<T>* temp = list.head;
		out << "[";
		while (temp->next != nullptr) {
			out << temp->data;
			temp = temp->next;
			out << ",";
		}
		out << temp->data << "]";
		return out;
	}
	void deleteList() {
		Node<T>* temp = nullptr;
		if (head == nullptr) {
			return;
		}
		temp = head;
		while (temp->next != nullptr) {
			temp = head->next;
			delete head;
			head = temp;
		}
		delete head;
		head=nullptr;
	}
	char* toString() {
		int digitNumber = 0;
		int thisSize = this->size();
		for (int i = 0; i < thisSize; i++) {
			int n = this->operator[](i);
			while (n) {
				digitNumber++;
				n /= 10;
			}
		}
		int stringLen = (digitNumber + thisSize - 1) + 3;
		char* str = new char[stringLen] {'\0'};
		str[0] = '[';
		str[stringLen - 2] = ']';
		str[stringLen - 1] = '\0';
		int arrayIndex = 1;
		for (int i = 0; i < thisSize; i++) {
			int n = this->operator[](i);
			int number = 0;
			while (n) {
				number++;
				n /= 10;
			}
			T* temp = new T[number];
			n = this->operator[](i);
			for (int i = 0; n; i++) {
				temp[i] = (n % 10) + '0';
				n /= 10;
			}
			for (int i = number - 1; i >= 0; i--) {
				str[arrayIndex] = temp[i];
				arrayIndex++;

			}
			if (arrayIndex != stringLen - 2) {
				str[arrayIndex] = ',';
				arrayIndex++;
			}
			delete[] temp;
		}
		return str;
	}
	~List() {
		if (head != nullptr) {
			Node<T>* temp = nullptr;
			if (head == nullptr) {
				return;
			}
			temp = head;
			while (temp->next != nullptr) {
				temp = head->next;
				delete head;
				head = temp;
			}
			delete head;
		}
		head = nullptr;
	}
	

};