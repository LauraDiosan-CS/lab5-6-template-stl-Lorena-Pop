#include "Service.h"

Service::Service()
{

}

Service::~Service()
{

}

Service::Service(RepoT<Tonomat>& t)
{
	this->s = t;
}

RepoT<Tonomat> Service::getAll()
{
	return this->s;
}

void Service::addItem(Tonomat& t)
{
	s.addItem(t);
}

void Service::deleteItem(Tonomat& t)
{
	s.deleteItem(t);
}

void Service::updateI(int t,Tonomat & nou)
{
	this->s.updateItem(t, nou);
}

int Service::getSize()
{
	return s.getSize();
}
