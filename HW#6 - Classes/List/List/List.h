#pragma once
#include"node.h"
#include<iostream>

using namespace std;

class List {
private:
	Node* head;
public:
	List() {
		head = nullptr;
	}
	void append(int data) {
		Node* newNode=new Node(data); 
		if (head == nullptr) {
			head = newNode;
			return;
		}
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
	void append(char data) {
		Node* newNode = new Node(data);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
	void printList() {
		Node* temp = head;
		cout << "[";
		while (temp->next != nullptr) {
			if (temp->intData) {
				cout << temp->dataInt;
				temp = temp->next;
				cout << ",";
			}
			else if (temp->dataChar) {
				cout << temp->dataChar;
				temp = temp->next;
				cout << ",";
			}
		}
		if (temp->intData) {
			cout << temp->dataInt << "]" << endl;
		}
		else if (temp->dataChar) {
			cout << temp->dataChar << "]" << endl;
		}
	}
};