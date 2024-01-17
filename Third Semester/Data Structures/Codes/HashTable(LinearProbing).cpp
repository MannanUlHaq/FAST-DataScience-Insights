#include<iostream>
using namespace std;

class HashItem
{
	int Key; // Index
	int Value;
	int Status; // 0: Empty, 1: Deleted, 2: Occupied

	friend class HashTable;
};

class HashTable
{
private:
	HashItem* HashArray;
	int Capacity;
	int currentElements;

	int getNextCandidateIndex(int key, int i)
	{
		return (key + i) % Capacity;
	}

	void doubleCapacity()
	{
		int oldCapacity = Capacity;
		HashItem* oldHashArray = HashArray;

		Capacity *= 2;
		HashArray = new HashItem[Capacity];

		for (int i = 0; i < oldCapacity; i++)
		{
			if (oldHashArray[i].Status == 2)
			{
				int key = oldHashArray[i].Key;
				int index = getNextCandidateIndex(key, 0);

				int i = 1;
				while (HashArray[index].Status == 2)
				{
					index = getNextCandidateIndex(index, i);
					i++;
				}

				HashArray[index].Key = key;
				HashArray[index].Value = oldHashArray[i].Value;
				HashArray[index].Status = 2;
			}
		}

		delete[] oldHashArray;
	}

public:
	HashTable()
	{
		Capacity = 10;
		HashArray = new HashItem[Capacity];
		currentElements = 0;

		for (int i = 0; i < Capacity; i++)
			HashArray[i].Status = 0;
	}

	HashTable(int capacity)
	{
		Capacity = capacity;
		HashArray = new HashItem[Capacity];
		currentElements = 0;

		for (int i = 0; i < Capacity; i++)
			HashArray[i].Status = 0;
	}

	~HashTable()
	{
		delete[] HashArray;
	}

	void insert(int key, int value)
	{
		int index = getNextCandidateIndex(key, 0);

		int i = 1;
		while (HashArray[index].Status == 2)
		{
			index = getNextCandidateIndex(index, i);
			i++;
		}

		HashArray[index].Key = key;
		HashArray[index].Value = value;
		HashArray[index].Status = 2;
		currentElements++;

		if (currentElements >= 0.75 * Capacity)
			doubleCapacity();
	}

	bool deleteKey(int key)
	{
		int index = getNextCandidateIndex(key, 0);

		int i = 1;
		while (HashArray[index].Status != 0 && HashArray[index].Key != key)
		{
			index = getNextCandidateIndex(index, i);
			i++;
		}

		if (HashArray[index].Status == 2 && HashArray[index].Key == key)
		{
			HashArray[index].Status = 1;
			currentElements--;
			return true;
		}

		return false;
	}
};

void main()
{
	HashTable hashtable(6);

	hashtable.insert(3, 1);
	hashtable.insert(5, 2);
	hashtable.insert(15, 3);
}