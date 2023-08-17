#pragma once
class Node {
public:
	int dataInt;
	char dataChar;
	Node* next;
	bool intData;
	bool charData;
	Node() {
		next = nullptr;
		intData = false;
		charData = false;
	}
	Node(int data) {
		this->dataInt = data;
		next = nullptr;
		intData = true;
		charData = false;
	}
	Node(char data) {
		this->dataChar = data;
		this->next = nullptr;
		intData = false;
		charData = true;
	}
};
