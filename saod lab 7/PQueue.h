#pragma once
#include "Heap.h"
template <class T>
class PQueue
{
private:
	// пирамида, в которой храниться очередь
	Heap<T>* ptrHeap;
public:
	// конструктор
	PQueue(int sz) {
		ptrHeap = new Heap(sz);
	}

	// операции модификации очереди приоритетов
	void PQInsert(const& T item) {
		ptrHeap->insert(item);
	}

	T PQDelete() {
		return ptrHeap->Delete();
	}

	void ClearPQ() {
		ptrHeap->clearList();
	}

	// методы спроса состояния очереди приоритетов
	int PQEmpty() const {
		return ptrHeap->listEmpty();
	}
	int PQFull() const{
		return ptrHeap->listFull();
	}
	int PQLenght() const {
		return ptrHeap->listSize();
	}

};

