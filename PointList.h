#pragma once
#ifndef POINTLIST
#define POINTLIST
struct PointListElement {
	int x, y;
	PointListElement * PNext;
};

class PointList
{
	
public:
	
//ITERATOR
	class Iterator
	{
		friend class PointList;
	public:
		//bool incr();
		PointListElement * getPointer() const;
		Iterator& operator++();
		bool reset();
	private:
		Iterator(PointList& list);
		PointListElement * pElement;
		PointListElement * pFirstElement;
	};
//ITERATOR_END

	PointList();
	~PointList();
	bool addPoint(int x, int y);
	PointListElement * getPoint(bool first) const;
	PointListElement * getPoint(int x, int y) const;
	bool getPoints() const;
	Iterator begin();

private:
	PointListElement * pFirst;
	PointListElement * pLast;
};

#endif // !POINTLIST