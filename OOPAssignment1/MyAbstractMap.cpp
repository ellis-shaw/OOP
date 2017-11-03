#include "stdafx.h"
#include "MyAbstractMap.h"

// This method adds a new element to the map
// Returns BOOL for success
bool MyAbstractMap::Add(int pKey, char pValue)
{
    // IF an item wth this key does not exist
    if (!FindByKey(pKey)) // THEN we can add the new item to the map
    {
        kvdata.push_back(KeyValuePair{ pKey, pValue }); //TODO - should not be using push back!
        cout << "Successfully added: " << pKey << ", " << pValue << endl;
        return true;
    }
    else // TODO - should this be in an else block? or can i assume it will hit if the IF-condition fails
    {
        cout << "Error: Key already exists!" << endl;
        return false;
    }
}

// This method deletes an element from the map by key
// Returns BOOL for success
bool MyAbstractMap::Delete(int pKey)
{
    // IF the map is empty then a deletion cannot occur.
    if (!IsEmpty())
    {
        // IF the key exists in the map
        if (FindByKey(pKey)) // THEN delete the item from the map.
        {
            if (kvdataIterator->key == pKey) // TODO - does this check even need to occur? or is it bad practice to assume the iterator will be right ??
            {
                kvdataIterator = kvdata.erase(kvdataIterator);
                cout << "Sucessfully deleted: " << pKey << endl;
                return true;
            }
        }
    }
    return false;
}

// This method updates the value of an element in the map using the key
// Returns BOOL for success
bool MyAbstractMap::Update(int pKey, char pValue)
{
    // IF the map is empty then a search cannot occur.
    if (!IsEmpty())
    {
        // IF the key exists in the map
        if (FindByKey(pKey)) // THEN delete the item from the map.
        {
            if (kvdataIterator->key == pKey) // TODO - does this check even need to occur? or is it bad practice to assume the iterator will be right ??
            {
                cout << "Sucessfully updated: " << pKey << " from: " << kvdataIterator->value << " ...to... " << pValue << endl;
                kvdataIterator->value = pValue;
                return true;
            }
        }
    }
    return false;
}

int MyAbstractMap::Current_Size()
{
    return kvdata.size(); // TODO - should not be using STL
}

bool MyAbstractMap::IsEmpty()
{
    if (kvdata.empty()) // TODO - should not be using STL
    {
        cout << "Error: map is empty!" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

// This method takes a key and returns true if the key exists in the map.
// NOTE: The method leaves the map's iterator pointing at the element being searched for.
bool MyAbstractMap::FindByKey(int pKey)
{
    for (kvdataIterator = kvdata.begin(); kvdataIterator != kvdata.end(); kvdataIterator++)
    {
        if (kvdataIterator->key == pKey)
        {
            return true;
        }
    }
    return false;
}

MyAbstractMap::MyAbstractMap()
{
    cout << "Created map class." << endl;
}

MyAbstractMap::MyAbstractMap(MyAbstractMap & OtherMap)
{
    // Iterate through the OtherMap
    for (OtherMap.kvdataIterator = OtherMap.kvdata.begin(); OtherMap.kvdataIterator != OtherMap.kvdata.end(); OtherMap.kvdataIterator++)
    {
        kvdata.push_back(KeyValuePair{OtherMap.kvdataIterator->key, OtherMap.kvdataIterator->value});
    }
}

MyAbstractMap::~MyAbstractMap()
{
	// TODO - do not ude STD
	kvdata.std::vector<KeyValuePair>::~vector();
	kvdataIterator.std::vector<KeyValuePair>::iterator::~iterator(); // TODO - Maybe tbis iterator doenst need to be deallocated too, because it is by the previous statement

	cout << "Destroyed map class." << endl;
}
