#pragma once

template<class T>
class DataNode
{
public:
	T data;
	int index;
	int active;

	friend int operator <= (const DataNode<T>& x, const DataNode<T>& y) {
		return (bool)(x <= y);
	}
};

