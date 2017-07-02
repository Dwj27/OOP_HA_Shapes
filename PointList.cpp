#include "..\Iterator-Operatoren-Übung\DummyList.h"
#include "..\Iterator-Operatoren-Übung\DummyList.h"
#include "..\Iterator-Operatoren-Übung\DummyList.h"
#include "PointList.h"
#include <iostream>

PointList::PointList() : pFirst(nullptr), pLast(nullptr)
{
}

PointList::~PointList()
{
	PointListElement * tmp;
	tmp = this->pFirst->PNext;
	
	while ( tmp != nullptr) {
		delete pFirst;
		pFirst = tmp;
		tmp = tmp->PNext;
	}
}

bool PointList::addPoint(int x, int y)
{
	bool done = false;

	if (this->pFirst == nullptr)
	{
		this->pFirst = new PointListElement;
		this->pLast = this->pFirst;
		this->pFirst->PNext = nullptr;
		this->pFirst->x = x;
		this->pLast->y = y;
		done = true;
	}
	else {
		this->pLast->PNext = new PointListElement;
		this->pLast = this->pLast->PNext;
		this->pLast->PNext = nullptr;
		this->pLast->x = x;
		this->pLast->y = y;
		done = true;
	}
	
	return done;
}

PointListElement * PointList::getPoint(bool first) const
{
	PointListElement * result = nullptr;

	if (first) {
		result = this->pFirst;
	}
	else {
		result = this->pLast;
	}

	return result;
}

PointListElement * PointList::getPoint(int x, int y) const
{
	PointListElement * tmp = this->pFirst;
	
	while (tmp != nullptr)
	{
		if (tmp->x == x && tmp->y == y) {
			break;
		}
		else {
			tmp = tmp->PNext;
		}
	}

	return tmp;
}

bool PointList::getPoints() const
{
	PointListElement * tmp = this->pFirst;

	while (tmp != nullptr) {
		std::cout << "(" << tmp->x << " ; " << tmp->y << ") ";
		tmp = tmp->PNext;
	}
	
	return true;
}

PointList::Iterator PointList::begin()
{
	return Iterator(*this);
}

// ITERATOR

PointList::Iterator::Iterator(PointList& list) : pElement(list.pFirst), pFirstElement(list.pFirst)
{
}

PointListElement * PointList::Iterator::getPointer() const
{
	return this->pElement;
}

DummyList::Iterator::Iterator(DummyList & list)
{
}

PointList::Iterator & PointList::Iterator::operator++()
{
	if (this->pElement = this->pElement->PNext) {
		return *this;
	}
	else {
		return *this;
	}
}

Iterator & DummyList::Iterator::operator--()
{
	// TODO: hier Rückgabeanweisung eingeben
}

DummyListElement DummyList::Iterator::operator*()
{
	return DummyListElement();
}

/*bool PointList::Iterator::incr()
{
	if (this->pElement = this->pElement->PNext) {
		return true;
	}
	else {
		return false;
	}
}*/

bool PointList::Iterator::reset()
{
	this->pElement = this->pFirstElement;
	return true;
}

//ITERATOR_END