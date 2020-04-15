#include "Tonomat.h"

Tonomat::Tonomat()
{
	this->cod = 0;
	this->pret = 0;
	this->nume = " ";
}

Tonomat::~Tonomat()
{
}

Tonomat::Tonomat(int cod, int pret, string nume) {
	this->cod = cod;
	this->pret = pret;
	this->nume = nume;
}

Tonomat::Tonomat(const Tonomat& t) {
	this->cod = t.cod;
	this->pret = t.pret;
	this->nume = t.nume;
}

void Tonomat::setCod(int cod) {
	this->cod = cod;
}

void Tonomat::setPret(int pret) {
	this->pret = pret;
}

void Tonomat::setNume(string nume) {
	this->nume = nume;
}

int Tonomat::getCod() {
	return this->cod;
}

int Tonomat::getPret() {
	return this->pret;
}

string Tonomat::getNume() {
	return this->nume;
}

Tonomat& Tonomat::operator=(const Tonomat& t)
{
	this->setCod(t.cod);
	this->setPret(t.pret);
	this->setNume(t.nume);
	return *this;
}

bool Tonomat::operator==(const Tonomat& t) {
	return (this->cod == t.cod) && (this->pret = t.pret);
}

ostream& operator<<(ostream& os, const Tonomat& t)
{
	os << t.cod << " " << t.pret << " " << t.nume;
	return os;
}