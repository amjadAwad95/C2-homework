#pragma once
template<typename dataType>
class Node {
public:
	dataType key;
	dataType data;
	Node* next;
	Node() {
		next = nullptr;
	}
	Node(dataType key, dataType data) {
		this->key = key;
		this->data = data;
		this->next = nullptr;
	}
};