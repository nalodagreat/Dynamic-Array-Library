#pragma once
#pragma once
#include <iostream>
#include <string>
#include <stack>
 
using namespace std;
class StackUndoRedo
{
	stack <string> redoList;
	stack <string> undoList;
	string value;
public:
	string getValue()
	{
		return value;
		
	}
	void setValue(string value)
	{
		undoList.push(this->value);
		this->value = value;
	}
	//undo
	void undo()
	{
		//set(1) UNDO[""]  redo[1] | set(1),set(2)	UNDO[1,""] REDO[2,1]| set(1) set(2) set(3) UNDO[2,1,""] REDO[3,2,1]
		if (!undoList.empty())     	
		{
			redoList.push(value);
			value = undoList.top();
			undoList.pop();
		}
	}
	//redo
	void redo()
	{
		if (!redoList.empty())     //redo=[3,2,1]  	
		{
			undoList.push(value);
			value = redoList.top();
			redoList.pop();
		}

	}
};

