#pragma once
#include "Tonomat.h"
#include <deque>
#include <fstream>
#include <string>
using namespace std;

template <typename T>

class RepoFile {
private:
	vector<T> el;
	string file;
public:
	RepoFile() {};
	void loadFromFile(string fileName);
	void addItem(T t);
	void deleteItem(T t);
	void updateItem(int t, T nou);
	vector<T> getAll();
	int getSize();
	void saveToFile();
	~RepoFile() {};
};

template <class T>
void RepoFile<T>::loadFromFile(string fileName)
{
	el.clear();
	file = fileName;
	ifstream f(fileName);
	int cod;
	int pret;
	string nume;
	while (!f.eof()) {
		f >> cod >> pret >> nume;
		if (cod != 0) {
			T t(cod, pret, nume);
			el.push_back(t);
		}
	}
	f.close();
}

template <class T>
void RepoFile<T>::saveToFile()
{
	ofstream f(file);
	for (size_t i = 0; i < el.size(); i++) {
		f << el[i];
	}
	f.close();
}

template <class T>
void RepoFile<T>::addItem(T t) {
	this->el.push_back(t);
}

template <class T>
void RepoFile<T>::deleteItem(T t) {
	
	vector<Tonomat>::iterator it;
	it = find(el.begin(), el.end(), t);
	if (it != el.end())
		el.erase(it);
}

template <class T>
void RepoFile<T>::updateItem(int t, T nou) {
	for (int i = 0; i < el.size(); i++) {
		if (i == t) {
			el[i] = nou;
		}
	}
}

template <class T>
int RepoFile<T>::getSize() {
	return this->el.size();
}

template <class T>
vector<T> RepoFile<T>::getAll() {
	return this->el;
}
