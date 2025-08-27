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

    void resize(int newLength)
    {
        if (newLength < 0)
            newLength = 0;

        T* tempArr = (newLength > 0) ? new T[newLength] : nullptr;
        int elementsToCopy = (newLength < _size) ? newLength : _size;

        for (int i = 0; i < elementsToCopy; i++)
            tempArr[i] = arr[i];

        delete[] arr;
        arr = tempArr;
        _size = newLength;
    }

    T getItem(int index)
    {
        if (index < 0 || index >= _size)
            throw out_of_range("Index out of range");
        return arr[index];
    }
    void reverse()
    {
        for (int i = 0; i < _size / 2; i++)
            swap(arr[i], arr[_size - 1 - i]);
    }

    void clear()
    {
        delete[] arr;
        arr = nullptr;
        _size = 0;
    }
    bool deletItem(int index)
    {

        if (index < 0 || index >= _size)
        {
            return false;
        }
        T* tempArr = (_size > 1) ? new T[_size-1] : nullptr;
        for (int i = 0, j = 0; i < _size; i++)
        {
            if (i == index) continue; 
            tempArr[j] = arr[i];
            j++;
        }

        delete[] arr;
        arr = tempArr;
        _size--;
        return trtue;
    }
    void deletFirstItem()
    {
        deletItem(0);
    }
    bool deletLasttItem()
    {
        deletItem(_size-1);
    }
};
