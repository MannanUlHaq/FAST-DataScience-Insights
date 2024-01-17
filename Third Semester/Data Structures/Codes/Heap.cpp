#include<iostream>
using namespace std;

class MinHeap
{
private:
	int* h;
	int maxSize;
	int currSize;

	void up_Heap(int Index)
	{
		if (Index == 1)
			return;
		else
		{
			int Parent = Index / 2;

			if (h[Parent] > h[Index])
			{
				swap(h[Parent], h[Index]);
				up_Heap(Parent);
			}
		}
	}

	void down_Heap(int Index)
	{
		int Smallest = Index;
		int Left_Child = 2 * Index;
		int Right_Child = (2 * Index) + 1;

		if (Left_Child < currSize && h[Left_Child] < h[Smallest])
			Smallest = Left_Child;
		if (Right_Child < currSize && h[Right_Child] < h[Smallest])
			Smallest = Right_Child;

		if (Smallest != Index)
		{
			swap(h[Smallest], h[Index]);
			down_Heap(Smallest);
		}
	}

	void removeMin(int& Value)
	{
		if (currSize == 1)
		{
			cout << "Heap is Empty!" << endl;
			return;
		}

		Value = h[1];
		h[1] = h[currSize - 1];
		currSize--;
		down_Heap(1);
	}

	void condition(int currIndex)
	{
		if (currIndex != maxSize)
		{
			int Left_Child = 2 * currIndex;
			int Right_Child = (2 * currIndex) + 1;

			if (h[Left_Child] > h[Right_Child])
			{
				swap(h[Left_Child], h[Right_Child]);
			}

			currIndex++;
			condition(currIndex);
		}
	}

public:
	MinHeap(int Size)
	{
		maxSize = Size;
		h = new int [maxSize];
		currSize = 1;
	}

	void buildHeap(int* arr, int size)
	{
		for (int i = 0; i < size; i++)
		{
			insertSingleValue(arr[i]);
		}
	}

	void insertSingleValue(int Value)
	{
		if (currSize == maxSize)
		{
			cout << "Heap is Full!" << endl;
			return;
		}

		h[currSize] = Value;
		up_Heap(currSize);
		currSize++;
	}

	void printHeap()
	{
		if (currSize == 1)
		{
			cout << "Heap is Empty!" << endl;
			return;
		}

		for (int i = 0; i < currSize; i++)
		{
			cout << h[i] << " ";
		}
		cout << endl;
	}

	friend void BSTtoMinHeap(int* arr, int size);
	friend void AscendingHeapSort(int* arr, int size);
	friend void DecendingHeapSort(int* arr, int size);
};

void BSTtoMinHeap(int* arr, int size)
{
	MinHeap heap(size + 1);
	heap.buildHeap(arr, size);

	//heap.condition(1);

	for (int i = 0; i < size; i++)
	{
		arr[i] = heap.h[i + 1];
	}
}

void AscendingHeapSort(int* arr, int size)
{
	MinHeap heap(size + 1);
	heap.buildHeap(arr, size);

	for (int i = 0; i < size; i++)
	{
		heap.removeMin(arr[i]);
	}
}

void DecendingHeapSort(int* arr, int size)
{
	MinHeap heap(size + 1);
	heap.buildHeap(arr, size);

	for (int i = size - 1; i >= 0; i++)
	{
		heap.removeMin(arr[i]);
	}
}

int main()
{
	int BST[] = {4, 2, 6, 1, 3, 5, 7};
	int size = 7;

	BSTtoMinHeap(BST, size);

	for (int i = 0; i < size; i++)
	{
		cout << BST[i] << " ";
	}
	cout << endl;
	cout << endl;

	int arr[] = { 12, 24, 25, 11, 14, 8 };
	size = 6;

	cout << "Given Array: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << endl;

	AscendingHeapSort(arr, size);

	cout << "After Sorting in Ascending Order: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}