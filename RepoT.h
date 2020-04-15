#pragma once
#include<vector>
#include "Tonomat.h"
#include <deque>
#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
using namespace std;

template<typename T>

class RepoT {
private:
	vector<T> el;
public:
	RepoT();
	void addItem(T t);
	void deleteItem(T t);
	void updateItem(int t,T n);
	vector<T> getAll();
	vector<T> getPoz();
	int getSize();
	~RepoT();
};

template<class T>
RepoT<T>::RepoT() {

}
template<class T>
RepoT<T>::~RepoT() {

}

template<class T>
int RepoT<T>::getSize()
{
	return this->el.size();
}

template<class T>
void RepoT<T>::addItem(T item)
{
	this->el.push_back(item);
}

template<class T>
void RepoT<T>::deleteItem(T t)
{
	typename vector<T>::iterator it;
	it = find(el.begin(), el.end(), t);
	if (it != el.end()) 
		el.erase(it);
}

template<class T>
void RepoT<T>::updateItem(int t,T n)
{
	for (int i = 0; i < el.size(); i++) {
		if (i == t) {
			el[i] = n;
		}
	}
}

template<class T>
vector<T> RepoT<T>::getAll() {
	return this->el;
}

template <class T>
vector<T> RepoT<T>::getPoz()
{
	return this->el;
}