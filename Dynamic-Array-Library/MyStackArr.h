#pragma once

#include <iostream>
#include "MyQueueArr.h"
using namespace std;
template <class T>

class  MyStackArr :public MyQueueArr<T>
{

public:

	void push(T value)
	{
		this->_list.insertAtbegining(value);
	}

	T Top()
	{
		return this->front();


	}

	T Bottom()
	{
		return MyQueueArr <T>::back();

	}

};