#include<iostream>
#include"List.h"
#include"Node.h"

using namespace std;

int main() {
	List<int> test;
	test.append(10);
	test.append(20);
	test.append(30);
	test.append(40);
	test.append(50);
	test.append(60);
	cout << test.size() << endl;
	cout << test[0] << endl;
	test.printList();
	cout << test << endl;
	test.insert(2,90);
	cout << test << endl;
	List<int> list;
	list.append(20);
	list.append(10);
	list.append(30);
	list.append(40);
	list.append(50);
	list.append(60);
	cout << list.in(60) << endl;
	cout << list.size() << endl;
	cout << list[0] << endl;
	list.printList();
	cout << list << endl;
	list.insert(2, 90);
	cout << list << endl;
	if (test == list) {
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
	if (test.isEqual(list)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	cout << test.toString() << endl;
	cout << list.toString() << endl;
	List<char> list1;
	list1.append('a');
	list1.append('b');
	list1.append('c');
	list1.append('d');
	list1.append('e');
	list1.append('f');
	cout << list1.toString() << endl;
}