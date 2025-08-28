#pragma once
#include "MyDynamicArray.h"
template <class T>
class MyQueueArr
{
protected:
	MyDynamicArray <T> _list;

public:
	void push(T value)
	{
		_list.insertAtEnd(value);
	}
	void pop()
	{
		_list.deletFirstItem();
	}

	int size()
	{
		return _list.size();
	}
	void print()
	{
		_list.printArr();

	}
	T front()
	{
		return _list.getItem(0);
	}
	T back()
	{
		return _list.getItem(size() - 1);
	}
	bool isEmpty()
	{
		return _list.isEmpty();
	}
	T getItem(int index)
	{
		return _list.getItem(index);
	}
	void reverse()
	{
		_list.reverse();
	}

	void updateItem(int index, T newValue)
	{
		_list.setArray(index, newValue);
	}
	void insertAtbegining(T value)
	{
		_list.insertAtbegining(value);
	}
};