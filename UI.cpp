#include "UI.h"
#include "RepoFile.h"
#include "RepoT.h"
#include "Service.h"
#include <iostream>
#include <fstream>

UI::UI(){}
UI::~UI(){}

void UI::addItem(int cod, int pret, string nume)
{
    cout << "cod : ";
    cin >> cod;
    cout << "pret : ";
    cin >> pret;
    cout << "nume : ";
    cin >> nume;
    Tonomat t(cod, pret, nume);
    s.addItem(t);
}

void UI::deleteItem(int cod, int pret, string nume)
{
    cout << "Introduceti urmatoarele infornatii pe care doriti sa le stergeti\n";
    cout << "cod : ";
    cin >> cod;
    cout << "pret : ";
    cin >> pret;
    cout << "nume : ";
    cin >> nume;
    Tonomat t(cod, pret, nume);
    s.deleteItem(t);
}

void UI::updateItem()
{
    cout << "introduceti codul produsului :";
    int cod;
    cin >> cod;
    int pret;
    cout << " introduceti noul pret  :";
    cin >> pret;
    string nume;
    cout << "introduceti noul nume  : ";
    cin >> nume;
    this->updateNume(cod,nume);
    this->updatePret(cod, pret);
}
void UI::updatePret(int cod, int modif)
{
    Tonomat t;
    t.setCod(cod);
    t.setPret(modif);
    for (int i = 0; i < s.getSize(); i++)
    {
        if (s.getAll().getPoz()[i].getCod() == cod)

        {
            t.setNume(s.getAll().getPoz()[i].getNume());
            s.updateI(i, t);
            break;

        }
    }
}
void UI::updateNume(int cod, string modif)
{
    Tonomat t;
    t.setCod(cod);
    t.setNume(modif);
    for (int i = 0; i < s.getSize(); i++)
    {
        if (cod == s.getAll().getPoz()[i].getCod())
        {
            t.setPret(s.getAll().getPoz()[i].getPret());
            this->s.updateI(i, t);
            break;

        }
    }
}

int UI::getPret(int cod)
{

    for (int i = 0; i < s.getSize(); i++)
    {
        if (cod == s.getAll().getPoz()[i].getCod())
        {
            return s.getAll().getPoz()[i].getPret();
        }
    }
    return -1;

}

int UI::findItem(int cod)
{
    for (int i = 0; i < s.getSize(); i++)
    {
        if (cod == s.getAll().getPoz()[i].getCod())
        {
            return i;
        }
    }
    return -1;
}

void UI::transaction()
{
    cout << "Introduceti codul produsului pe care il doriti :  ";
    int cod;
    cin >> cod;
    int pret = this->getPret(cod);
    int find = this->findItem(cod);
    cout << "Produsului costa " << pret << " lei " << endl;
    cout << "Introduceti monedele : ";
    int monezi;
    int suma_in_tonomat = 100;
    cin >> monezi;
    if (monezi < pret)
    {
        cout << endl;
        cout << "Insuficienti bani!!! " << endl;
    }
    else if (monezi == pret)
    {
        cout << endl;
        cout << "Tranzactie reusita !!! " << endl;
    }
    else
    {
        cout << endl;
        cout << "Asteptati restul ... " << endl;
        int cincizeci;
        this->rest(monezi, pret, cincizeci);
        if (suma_in_tonomat > cincizeci) {
            cout << "Restul  : \n";
            cout << cincizeci << " monede de 50 de bani" << endl;
        }
        else
            cout << "Tonomatul nu are sa va dea rest" << endl;
    }
        
}


void UI::rest(int suma, int pret, int& cincizeci)
{
    int rest;
    rest = suma - pret;
    rest = rest * 10;
    cincizeci = rest / 5;
}


int UI::Meniu() {
    int cod = 0;
    int pret = 0;
    string nume = " ";
    vector<Tonomat> aux;
    int optiune;
    do
    {
        cout << "\nMENIU :\n";
        cout << "1. Adaugare \n";
        cout << "2. Afisare \n";
        cout << "3. Stergere \n";
        cout << "4. Modificare \n";
        cout << "5. Cumparare\n";
        cout << "Alegeti o optiune : ";
        cin >> optiune;
        switch (optiune) {
        case 1: {
            cout << "Introduceti urmatoarele infornatii pe care doriti sa le adaugati\n ";
            addItem(cod, pret, nume);
            break; }
        case 2: {
            cout << endl;
            cout << "Produsele sunt: " << endl;
            for (int i = 0; i < this->s.getSize(); i++) {
                cout << s.getAll().getPoz()[i] << "\n";
            }
            std::ifstream f("Tonomat.txt");
            if (f.is_open())
                std::cout << f.rdbuf() << endl;

            break; }

        case 3: {
            deleteItem(cod, pret, nume);
            break;
        }
        case 4: {
            updateItem();
            break;
        }
        case 5: {
            transaction();
            break;
        }
        case 0: {
            cout << "Programul se inchide\n";
            break; }
        }
    } while (optiune != 0);
    return 0;
}
