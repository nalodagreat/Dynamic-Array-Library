#pragma once
#include <iostream>
#include <stdexcept>
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
        if (index < 0)
            return false;
        if (index >= _size) {
            resize(index + 1);
        }
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
        arr = new T[0];
        _size = 0;
    }
    bool deleteItem(int index)
    {
        if (index < 0 || index >= _size)
            return false;

        if (_size == 1) {
            delete[] arr;
            arr = nullptr;
            _size = 0;
            return true;
        }

        T* tempArr = new T[_size - 1];
        for (int i = 0, j = 0; i < _size; i++) {
            if (i == index) continue;
            tempArr[j++] = arr[i];
        }

        delete[] arr;
        arr = tempArr;
        _size--;
        return true;
    }

    void deletFirstItem()
    {
        deleteItem(0);
    }
    void deleteLastItem()
    {
        deleteItem(_size - 1);
    }
    int find(T value)
    {
        for (int i = 0;i < _size; i++)
        {
            if (value == getItem(i))
                return i;
        }
        return -1;
    }
    bool deleteItemByValue(int value)
    {
        int index = find(value);
        if (index == -1)
        {
            return false;
        }
        deleteItem(index);
        return true;
    }
    void insertAt(int index, T value)
    {
        //1-2-3-4 |1-2-500-3-4
       
        if (index < 0 || index >= _size) 
              return;
       
        T* tempArr = new T[_size+1];
        for (int i = 0, j = 0; i < _size+1; i++)
        {
            if (i == index+1)
            {
                tempArr[i] = value;

            }
            else
            {
                tempArr[i] = arr[j];
                j++;
            }
        }

        delete[] arr;
        arr = tempArr;
        _size++;
    }
    void insertAtbegining(T value)
    {
        T* tempArr = new T[_size + 1];
        for (int i = 0, j = 0; i < _size + 1; i++)
        {
            if (i == 0)
            {
                tempArr[i] = value;

            }
            else
            {
                tempArr[i] = arr[j];
                j++;
            }
        }

        delete[] arr;
        arr = tempArr;
        _size++;

    }
    void insertBeforeIndex(int index, T value)
    {
        //1-2-3  | 1-500-2-3
        if (index < 0 || index >= _size)
            return;
        if (index <= 1)
            insertAtbegining(value);
        else
            insertAt(index - 2, value);
    }
    void insertAfter(int index, T value)
    {
        //1-2-3  | 1-500-2-3
        if (index < 0 || index >= _size)
            return;
        insertAt(index, value);
    }
    void insertAtEnd(T value)
    {
        if (_size == 0)
            insertAtbegining(value);
        else
            insertAt(_size - 1, value);
    }
    bool isEmpty()
    {
        (_size == 0);
    }
    

};