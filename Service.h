#pragma once
#include "Tonomat.h"
#include "RepoT.h"

class Service
{
private:
    RepoT<Tonomat> s;
public:
    Service();
    Service(RepoT<Tonomat>& t);
    void addItem(Tonomat& t);
    void deleteItem(Tonomat& t);
    void updateI(int t,Tonomat & nou);
    RepoT<Tonomat> getAll();
    int getSize();
    ~Service();
};