#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyDynamicArray
{
protected:
    int _size;
public:
    T* arr;

    MyDynamicArray(int size = 0)
    {
        if (size <= 0)
            _size = 0;
        else
            _size = size;

        arr = (_size > 0) ? new T[_size] : nullptr;
    }

    ~MyDynamicArray()
    {
        delete[] arr;
    }

    bool setArray(int index, T value)
    {
        if (index < 0 || index >= _size)
            return false;

        arr[index] = value;
        return true;
    }

    void printArr()
    {
        for (int i = 0; i < _size; i++)
            cout << arr[i] << endl;
    }

    int size()
    {
        return _size;
    }

    bool isEmpty()
    {
        return (_size == 0);
    }

   
};
