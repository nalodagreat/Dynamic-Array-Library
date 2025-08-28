//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#include <iostream>
#include "MyDynamicArray.h"

using namespace std;

int main()
{

    MyDynamicArray <int> MyDynamicArray(5);

    MyDynamicArray.setArray(0, 10);
    MyDynamicArray.setArray(1, 20);
    MyDynamicArray.setArray(2, 30);
    MyDynamicArray.setArray(3, 40);
    MyDynamicArray.setArray(4, 50);

    cout << "\nIs Empty?  " << MyDynamicArray.isEmpty();
    cout << "\nArray size: " << MyDynamicArray.size() << "\n";
    cout << "\nArray Items: \n";

    MyDynamicArray.printArr();

    MyDynamicArray.insertAtbegining(400);
    cout << "\n\nArray after insert 400 at Begining:";
    cout << "\nArray size: " << MyDynamicArray.size() << "\n";
    MyDynamicArray.printArr();

    MyDynamicArray.insertBeforeIndex(2, 500);
    cout << "\n\nArray after insert 500 before index 2:";
    cout << "\nArray size: " << MyDynamicArray.size() << "\n";
    MyDynamicArray.printArr();

    MyDynamicArray.insertAfter(2, 600);
    cout << "\n\nArray after insert 600 after index 2:";
    cout << "\nArray size: " << MyDynamicArray.size() << "\n";
    MyDynamicArray.printArr();


    MyDynamicArray.insertAtEnd(800);
    cout << "\n\nArray after insert 800 at End:";
    cout << "\nArray size: " << MyDynamicArray.size() << "\n";
    MyDynamicArray.printArr();



}