#pragma once
#include <iostream>
template<class T>
class Heap
{
private:
	T* hlist;
	int inArray;

	int maxheapsize;
	int heapsize;

	void error(char errmsg[]) {
		cerr << "Ошибка: " errmsg;
		exit(1);
	}

	void filterDown(int i) {
		int currentpos, childpos;
		T target;
		currentpos = i;
		target = hlist[i];
		childpos = 2 * i + 1;
		while (childpos < heapsize)
		{
			if ((childpos + 1 < heapsize) && (hlist[childpos + 1] <= hlist[childpos]))
				childpos++;
		
			if (target <= hlist[childpos])
				break;
			else {
				hlist[currentpos] = hlist[childpos];

				currentpos = childpos;
				childpos = 2 * currentpos + 1;

			}
		}
		hlist[currentpos] = target;
	}


	void filterUp(int i) {

		int currentpos, parentpos;
		T target;
		currentpos = i;
		parentpos = (i - 1) / 2;
		target = hlist[i];
		while (currentpos != 0) {
			if (hlist[parentpos] <= target)
				break;
			else
			{
				hlist[currentpos] = hlist[parentpos];
				currentpos = parentpos;
				parentpos = (currentpos - 1) / 2;
			}
		}
		hlist[currentpos] = target;
	}
public:

	Heap(int maxsize) {
		hlist = new T[maxsize];
		maxheapsize = maxsize;
		heapsize = 0;
		inArray = 0;
	}

	Heap(T arr[], int n) {
		int j, currentpos;
		if (n <= 0)
			error("Неправильная размерность массива!");
		maxheapsize = n;
		heapsize = n;
		hlist = arr;
		currentpos = (heapsize - 2) / 2;
		while (currentpos >= 0)
		{
			filterDown(currentpos);
			currentpos--;
		}
		inArray = 1;
	}

	Heap(const Heap<T>& H) {
		this = H;
	}

	~Heap() {
		clearList();
		delete hlist;
	}

	Heap<T> operator= (const Heap<T>& rhs) {
		if(!rhs.listEmpty())
			error("Пустой Heap")
		hlist = rhs.hlist;
		maxheapsize = rhs.maxheapsize;
		heapsize = rhs.heapsize;
		inArray = 1;
	}

	const T& operator[](int i) {
		if (i > heapsize)
			error("Выход за границы массива!");
		else
			return hlist[i];
	}

	int listSize() const {
		return heapsize;
	}

	int listEmpty() const {
		if (heapsize == 0)
			return 1;
		else return 0;
	}

	int listFull() const {
		if (heapsize == maxheapsize)
			return 1;
		else return 0;

	}

	void insert(const T& item) {
		if (heapsize == maxheapsize)
			error("Пирамида заполнена!");
		hlist[heapsize] = item;
		filterUp(heapsize);
		heapsize++;
	}

	T Delete() {
		T tempitem;
		if (heapsize == 0)
			error("Пирамида пуста!");
		tempitem = hlist[0];
		hlist[0] = hlist[heapsize - 1];
		heapsize--;

		filterDown(0);

		return tempitem;
	}

	void clearList() {
		while (!listEmpty())
		{
			Delete();
		}
	}
};

