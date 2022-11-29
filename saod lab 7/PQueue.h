#pragma once
#include "Heap.h"
template <class T>
class PQueue
{
private:
	// ��������, � ������� ��������� �������
	Heap<T>* ptrHeap;
public:
	// �����������
	PQueue(int sz) {
		ptrHeap = new Heap(sz);
	}

	// �������� ����������� ������� �����������
	void PQInsert(const& T item) {
		ptrHeap->insert(item);
	}

	T PQDelete() {
		return ptrHeap->Delete();
	}

	void ClearPQ() {
		ptrHeap->clearList();
	}

	// ������ ������ ��������� ������� �����������
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

