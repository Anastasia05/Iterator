#include <iostream>
#include <fstream>
using namespace std;

template <typename myTip>
class Stack
{
	int size;
	struct ElementStack
	{
		myTip znach;
		ElementStack* pred;
	} *top;
public:
	void push(myTip x)  // Положить элемент в стек
	{
		if (top == NULL)
		{
			top = new ElementStack;
			top->znach = x;
			size = 1;
			top->pred = NULL;
			return;
		}
		ElementStack* p = new ElementStack;
		p->pred = top;
		p->znach = x;
		size++;
		top = p;
	}

	myTip pull()  // Вытащить элемент из стека
	{
		if (size == 0)
		{
			cout << "Стек пуст!\n";
			return 0;
		}
		myTip x = top->znach;
		ElementStack* p = top;
		top = top->pred;
		delete p;
		size = size - 1;
		return x;
	}
	void del()  //Очистка стека
	{
		if (size != 0)
		{
			ElementStack* p;
			while (top != 0)
			{
				p = top;
				top = top->pred;
				delete p;
			}
			size = 0;
			top = NULL;
		}
	}
	void show()
	{
		ElementStack *p = top;
		while (p)
		{
			cout << p->znach << " ";
			p = p->pred;
		}
		cout << endl;
	}
	int getSize()        // Какой размер?
	{
		return size;
	}
	Stack(myTip x)    // Конструктор
	{
		top = new ElementStack;
		top->znach = x;
		size = 1;
		top->pred = NULL;
	}
	~Stack()           // Деструктор
	{
		del();
	}
};

////////////////////

template <typename myTip>
class Queue
{
	int size;
	struct ElementQueue
	{
		myTip znach;
		ElementQueue* pred;
		ElementQueue* sled;
	} *nach, *kon;
public:
	void push(myTip x)  // Положить элемент в очередь
	{
		if (nach == NULL)
		{
			nach = new ElementQueue;
			nach->pred = NULL;
			nach->sled = NULL;
			nach->znach = x;
			kon = nach;
			size = 1;
			return;
		}
		ElementQueue* p = new ElementQueue;
		p->pred = nach;
		nach->sled = p;
		p->sled = NULL;
		p->znach = x;
		nach = p;
		size++;
	}
	myTip pull()   // Вытащить элемент
	{
		if (!size)
		{
			cout << "Очередь пуста!\n";
			return NULL;
		}
		myTip x = kon->znach;
		ElementQueue* p = kon;
		if (kon->sled)
			(kon->sled)->pred = NULL;
		kon = kon->sled;
		if (size == 1)
		{
			delete p;
			nach = NULL;
		}
		else
			delete p;
		size--;
		return x;
	}
	void show()
	{
		ElementQueue *p = nach;
		while (p)
		{
			cout << p->znach << " ";
			p = p->pred;
		}
		cout << endl;
	}
	void del()      // Очистка очереди
	{
		if (size)
		{
			ElementQueue* p;
			while (nach)
			{
				p = nach;
				nach = nach->pred;
				delete p;
			}
			size = 0;
			nach = NULL;
		}
	}
	int Size()
	{
		return size;
	}
	bool pust()      // Пуст ли?
	{
		if (size == 0)
			return true;
		return false;
	}
	Queue(myTip x)
	{
		nach = new ElementQueue;
		nach->pred = NULL;
		nach->sled = NULL;
		nach->znach = x;
		kon = nach;
		size = 1;
	}
	~Queue()
	{
		del();
	}
};

////////////////

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
	setlocale(0, "");
	Queue<char> bukva('\0');
	Queue<char> cifra('\0');
	Queue<char> znak('\0');
	bool Z1 = false, Z2 = false, Z3 = false;
	ifstream fin("file.txt");
	while (!fin.eof())
	{
		char x = fin.get();
		if (((x >= -64) && (x <= -1)) || (x == -88) || (x == -72) || ((x >= 65) && (x <= 90)) || ((x >= 95) && (x <= 122)))
		{
			if (Z1 == false)
			{
				bukva.del();
				Z1 = true;
			}
			bukva.push(x);
		}
		if ((x >= 48) && (x <= 57))
		{
			if (Z2 == false)
			{
				cifra.del();
				Z2 = true;
			}
			cifra.push(x);
		}
		if (((x >= 33) && (x <= 47)) || ((x >= 58) && (x <= 64)) || ((x >= 91) && (x <= 96)) || ((x >= 123) && (x <= 126)) || (x == -106))
		{
			if (Z3 == false)
			{
				znak.del();
				Z3 = true;
			}
			znak.push(x);
		}
	}
	fin.close();
	while (bukva.pust() == false)
	{
		if (bukva.Size() == 1)
		{
			bukva.pull();
			break;
		}
		cout << bukva.pull();
	}
	while (cifra.pust() == false)
		cout << cifra.pull();
	while (znak.pust() == false)
		cout << znak.pull();
	return 0;

}