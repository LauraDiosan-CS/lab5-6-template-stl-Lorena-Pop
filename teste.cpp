#include <iostream>
#include "RepoT.h"
#include "RepoFile.h"
#include "Tonomat.h"
#include "Service.h"
#include <assert.h>
#include <cassert>
#include "UI.h"
using namespace std;

void testeTonomat() {
	Tonomat t(1, 10, "ciocolata");
	assert(t.getCod() == 1);
	assert(t.getPret() == 10);
	assert(t.getNume() == "ciocolata");
	t.setCod(2);
	t.setPret(2);
	t.setNume("croissante");
	assert(t.getCod() == 2 && t.getPret() == 2 && t.getNume() == "croissante");
}

void testeRepoT_addItem() {
	Tonomat t1(5, 5, "ciocolata");
	RepoT<Tonomat> rt;

	rt.addItem(t1);
	assert(rt.getAll()[0].getCod() == 5);
	assert(rt.getAll()[0].getPret() == 5);
	assert(rt.getAll()[0].getNume() == "ciocolata");
	assert(rt.getSize() == 1);
}
void testeRepoT_deleteItem()
{
	Tonomat t2(11, 100, "suc");
	RepoT<Tonomat> rt;

	rt.deleteItem(t2);
	assert(rt.getSize() == 3);
}

void testeService_addItem() {
	Tonomat t1(5, 500, "ciocolata");
	Service s;

	s.addItem(t1);
	assert(s.getSize() == 1);
}
void testeService_deleteItem()
{
	Tonomat t2(11, 100, "suc");
	Service s;

	s.deleteItem(t2);
	assert(s.getSize() == 2);
}

void testeRepoFile_addItem()
{
	Tonomat t1(5, 500, "ciocolata");
	RepoFile<Tonomat> rf;
	rf.loadFromFile("Tonomat.txt");
	rf.addItem(t1);
	assert(rf.getSize() == 2);
}

void testeRepoFile_deleteItem()
{
	Tonomat t2(11, 100, "suc");
	RepoFile<Tonomat> rf;
	rf.loadFromFile("Tonomat.txt");
	rf.deleteItem(t2);
	assert(rf.getSize() == 2);
}

void testeRest()
{
	UI u;
	int cinci;
	u.rest(10, 9, cinci);
	assert(cinci == 2 );

}

void teste() {
	void testeTonomat();
	void testeRepoT_addItem();
	void testeRepoT_deleteItem();
	void testeService_addItem();
	void testeService_deleteItem();
	void testeRepoFile_addItem();
	void testeRepoFile_deleteItem();
	void testeRest();
	cout << "Testare cu succes!";
}