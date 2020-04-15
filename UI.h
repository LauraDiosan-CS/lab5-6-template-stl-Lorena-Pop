#pragma once
#include "Service.h"

class UI {
private:
	Service s;
public:
	UI();
	void addItem(int cod, int pret, string nume);
	void deleteItem(int cod, int pret, string nume);
	void updateItem();
	void rest(int suma, int pret, int& cincizeci);
	void updatePret(int cod, int modif);
	void updateNume(int cod, string modif);
	int findItem(int cod);
	int getPret(int cod);
	void transaction();
	int Meniu();
	~UI();
};