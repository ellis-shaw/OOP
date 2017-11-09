#pragma once

#include "stdafx.h"
#include "KeyValuePair.h"
#include "AbstractKeyValuePair.h"

#include <vector>
#include <iostream>

using namespace std;

class MyAbstractMap
{
private:
	std::vector<AbstractKeyValuePair> kvdata;
	std::vector<AbstractKeyValuePair>::iterator kvdataIterator;
public:
	// CORE FUNCTIONS
	bool Add(int pKey, char pValue);
	bool Delete(int pKey);
	bool Update(int pKey, char pValue);
	
	//
	int Max_Size();
	int Current_Size();

	// NON-CORE
	bool IsEmpty();
	bool FindByKey(int);
	void ClearAll();
	bool Swap(MyAbstractMap OtherMap); // Exchange the contents of one map to another
	

	// CONSTRUCTORS
	MyAbstractMap(); // Default - makes a new map
	MyAbstractMap(MyAbstractMap& OtherMap); // Copy constructor
	~MyAbstractMap();
};