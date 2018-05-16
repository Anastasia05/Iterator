#include <iostream>
#include <fstream>
using namespace std;

template <typename myTip>
class Dek
{
	int size;
	struct ElementDek
	{
		myTip znach;
		ElementDek* pred;
		ElementDek* sled;
	} *nach, *kon;

public:
	class DekIterator
	{
		ElementDek *pointer;

	public:
		DekIterator(ElementDek *el)
		{
			pointer = el;
		}

		void operator--(int)
		{
			pointer = pointer->sled;
		}

		void operator++(int)
		{
			pointer = pointer->pred;
		}

		myTip operator*()
		{
			return pointer->znach;
		}
	};
	DekIterator begin()
	{
		return  *(new DekIterator(nach));
	}
	DekIterator end()
	{
		return *(new DekIterator(kon));
	}
	void Vnach(myTip x) // Положить в начало
	{
		if (!nach)
		{
			nach = new ElementDek;
			nach->pred = NULL;
			nach->sled = NULL;
			nach->znach = x;
			kon = nach;
			size = 1;
			return;
		}
		ElementDek* p = new ElementDek;
		p->pred = nach;
		nach->sled = p;
		p->sled = NULL;
		p->znach = x;
		size++;
		nach = p;
	}
	void Vkon(myTip x)
	{
		if (!nach)
		{
			nach = new ElementDek;
			nach->pred = NULL;
			nach->sled = NULL;
			nach->znach = x;
			kon = nach;
			size = 1;
			return;
		}
		ElementDek* p = new ElementDek;
		p->sled = kon;
		kon->pred = p;
		p->pred = NULL;
		p->znach = x;
		size++;
		kon = p;
	}
	myTip Iznach()
	{
		if (size == 0)
		{
			cout << "Дек пуст!\n";
			return NULL;
		}
		myTip x = nach->znach;
		ElementDek* p = nach;
		if (nach->pred != NULL)
			(nach->pred)->sled = NULL;
		nach = nach->pred;
		if (size == 1)
		{
			delete p;
			nach = NULL;
			kon = NULL;
		}
		else
			delete p;
		size--;
		return x;
	}
	myTip Izkon()
	{
		if (!size)
		{
			cout << "Дек пуст!\n";
			return NULL;
		}
		myTip x = kon->znach;
		ElementDek* p = kon;
		if (kon->sled != NULL)
			(kon->sled)->pred = NULL;
		kon = kon->sled;
		if (size == 1)
		{
			delete p;
			nach = NULL;
			kon = NULL;
		}
		else
			delete p;
		size--;
		return x;
	}
	void show()
	{
		ElementDek *p = nach;
		while (p)
		{
			cout << p->znach << " ";
			p = p->pred;
		}
		cout << endl;
	}
	void del()            // Очистка дека
	{
		if (size != 0)
		{
			ElementDek* p;
			while (nach != NULL)
			{
				p = nach;
				nach = nach->pred;
				delete p;
			}
			size = 0;
		}
	}
	bool pust()
	{
		if (size == 0)
			return true;
		return false;
	}
	Dek(myTip x)
	{
		nach = new ElementDek;
		nach->pred = NULL;
		nach->sled = NULL;
		nach->znach = x;
		kon = nach;
		size = 1;
	}
	~Dek()
	{
		del();
	}
};


int main()
{
	Dek<int> d(5);
	d.Vnach(7);
	Dek<int>::DekIterator iter = d.begin();
	cout << *iter;
	iter++;
	cout << *iter;
	return 0;

}
