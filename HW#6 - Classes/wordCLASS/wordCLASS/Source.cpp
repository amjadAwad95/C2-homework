#include<iostream>
#include<fstream>
#define MAX_WORDS 50
using namespace std;

class WordList {
private:
	char  language[100];
	int size;
	int Max_Words;
	char word[MAX_WORDS][MAX_WORDS];
public:
	WordList(int max) {
		this->Max_Words = max;
		size = 0;
	}
	WordList() {
		this->Max_Words = 10;
		size = 0;
	}
	WordList(const WordList& obj) {
		strcpy_s(this->language, 50, obj.language);
		this->size = obj.size;
		this->Max_Words = obj.Max_Words;
		for (int i = 0; i < obj.size; i++) {
			strcpy_s(this->word[i], 50, obj.word[i]);
		}
	}
	void Load_Word_List(ifstream& file) {
		file.open("word.txt");
		if (!file) {
			cout << "error" << endl;
			return;
		}
		char str[100];
		file >> str;
		int numberOfWord = 0;
		while (file >> str) {
			numberOfWord++;
		}
		file.close();
		if (numberOfWord > Max_Words) {
			cout << "its max bro" << endl;
			return;
		}
		file.open("word.txt");
		if (!file) {
			cout << "error" << endl;
			return;
		}
		file >> language;
		for (int i = 0; i < numberOfWord; i++) {
			file >> word[i];
			size++;
		}
	}
	void Add_Word(char* w) {
		if (size >= Max_Words) {
			cout << "error" << endl;
			return;
		}
		if (Contains(w)) {
			return;
		}
		strcpy_s(word[size], 50, w);
		size++;
	}
	bool Contains(char* w) {
		for (int i = 0; i < size; i++) {
			if (strcmp(word[i], w) == 0) {
				return true;
			}
		}
		return false;
	}
	void Display_Word_List() {
		for (int i = 0; i < size; i++) {
			cout << word[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	ifstream file;
	WordList obj(20);
	obj.Load_Word_List(file);
	obj.Display_Word_List();
}