#pragma once
template<typename T>
class Node {
public:
	T data;
	Node* next;
	Node() {
		data = 0;
		next = nullptr;
	}
	Node(T data) {
		this->data = data;
		this->next = nullptr;
	}
};