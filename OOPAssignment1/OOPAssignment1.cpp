// OOPAssignment1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyAbstractMap.h"

#include <iostream>

using namespace std;

int main()
{
    MyAbstractMap myMap = MyAbstractMap();
    myMap.Add(1, 'A');
	myMap.Add(2, 'B');
	myMap.Add(2, 'B');
    myMap.Add(3, 'C');
    myMap.Add(4, 'D');
    myMap.Delete(3);
	myMap.Update(4, 'C');

	MyAbstractMap mySecondMap = MyAbstractMap(myMap);
	myMap.~MyAbstractMap();


    int exit;
    cin >> exit;
    return 0;
}

