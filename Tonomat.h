#pragma once
#include <stdlib.h>
#include <iostream>
using namespace std;


class Tonomat {
private:
	int cod;
	int pret;
	string nume;
public:
	Tonomat();
	Tonomat(int cod, int pret, string nume);
	Tonomat(const Tonomat& t);
	~Tonomat();
	int getCod();
	int getPret();
	string getNume();
	void setCod(int cod);
	void setPret(int pret);
	void setNume(string nume);
	Tonomat& operator=(const Tonomat&);
	bool operator==(const Tonomat&);
	friend ostream& operator<<(ostream& os, const Tonomat& t);

};