#include<iostream>
#include<stack>
using namespace std;

class Node
{
	int data;
	Node* next;

	friend class LinkedList;
};

class LinkedList
{
	Node* head;

public:
	LinkedList()
	{
		head = nullptr;
	}

	bool insertAtStart(int val)
	{
		Node* newNode = new Node;
		newNode->data = val;
		newNode->next = head;
		head = newNode;
		return true;
	}

	bool deleteFromStart()
	{
		if (head == nullptr)
		{
			return false;
		}
		else
		{
			Node* Start = head;
			head = head->next;
			delete Start;
			return true;
		}
	}

	bool insertAtEnd(int val)
	{
		Node* newNode = new Node;
		newNode->data = val;
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			return true;
		}
		else
		{
			Node* Curr = head;
			while (Curr->next != nullptr)
			{
				Curr = Curr->next;
			}

			Curr->next = newNode;
			return true;
		}
	}

	bool deleteFromEnd()
	{
		if (head == nullptr)
		{
			return false;
		}
		else
		{
			Node* Curr = head, * Prev = nullptr;
			while (Curr->next != nullptr)
			{
				Prev = Curr;
				Curr = Curr->next;
			}

			if (Prev == nullptr)
			{
				head = nullptr;
			}
			else
			{
				Prev->next = nullptr;
			}

			delete Curr;
			Curr = nullptr;
			return true;
		}
	}

	bool insertAfterSpecificValue(int Sval, int Nval)
	{
		Node* newNode = new Node;
		newNode->data = Nval;
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			return true;
		}

		else
		{
			Node* Curr = head;
			while (Curr != nullptr)
			{
				if (Curr->data == Sval)
				{
					newNode->next = Curr->next;
					Curr->next = newNode;
					return true;
				}
			}
			return false;
		}
	}

	bool ReverseList()
	{
		if (head == nullptr)
		{
			return false;
		}
		else if (head->next == nullptr)
		{
			return true;
		}
		else
		{
			Node* Curr = head, * Next = nullptr, * Prev = nullptr;
			while (Curr != nullptr)
			{
				Next = Curr->next;
				Curr->next = Prev;
				Prev = Curr;
				Curr = Next;
			}

			head = Prev;
			return true;
		}
	}

	bool SortList()
	{
		if (head == nullptr)
		{
			return false;
		}
		else if (head->next == nullptr)
		{
			return true;
		}
		else
		{
			Node* Curr = head;
			while (Curr->next != nullptr)
			{
				Node* Next = Curr->next;
				while (Next != nullptr)
				{
					if (Next->data < Curr->data)
					{
						swap(Next->data, Curr->data);
					}
					Next = Next->next;
				}
				Curr = Curr->next;
			}
		}
	}

	void MergeLists(LinkedList* L2)
	{
		if (head == nullptr || L2->head == nullptr)
			return;

		Node* Curr1 = head;

		while (Curr1->next != nullptr)
			Curr1 = Curr1->next;

		Curr1->next = L2->head;
		L2->head = nullptr;
	}

	bool RemoveDuplicates()
	{
		if (head == nullptr)
			return false;

		Node* Curr1 = head;
		while (Curr1 != nullptr)
		{
			Node* Prev = Curr1;
			Node* Curr2 = Curr1->next;

			while (Curr2 != nullptr)
			{
				if (Curr2->data == Curr1->data)
				{
					Prev->next = Curr2->next;
					delete Curr2;
					Curr2 = Prev;
				}

				Prev = Curr2;
				Curr2 = Curr2->next;
			}

			Curr1 = Curr1->next;
		}

		return true;
	}

	void Display()
	{
		if (head == nullptr)
		{
			cout << "List is Empty!" << endl;
		}
		else
		{
			Node* Curr = head;
			while (Curr != nullptr)
			{
				cout << Curr->data << " ";
				Curr = Curr->next;
			}
			cout << endl;
		}
	}

	bool DeleteLastOccurence(int Value)
	{
		if (head == nullptr)
			return false;
		else
		{
			stack<int> s;
			int i = 0;

			Node* Curr = head;
			while (Curr != nullptr)
			{
				if (Curr->data == Value)
					s.push(i);

				i++;
				Curr = Curr->next;
			}

			if (s.empty())
				return false;
			else
			{
				int Index = s.top();

				Node* Curr = head;
				Node* Prev = nullptr;
				for (int i = 0; i < Index; i++)
				{
					Prev = Curr;
					Curr = Curr->next;
				}

				if (Prev == nullptr)
				{
					delete Curr;
					Curr = nullptr;
					return true;
				}
				else
				{
					Prev->next = Curr->next;
					delete Curr;
					Curr = nullptr;

					return true;
				}
			}
		}
	}

	bool Equalize_Ocurrences(int Key, int Max_Count)
	{
		if (head == nullptr)
			return false;

		Node* Curr1 = head;
		while (Curr1 != nullptr)
		{
			if (Curr1->data == Key)
			{
				Node* Curr2 = Curr1->next;
				Node* Prev = Curr1;
				for (int i = 1; i < Max_Count; i++)
				{
					if (Curr2->data != Key)
					{
						Node* newNode = new Node;
						newNode->data = Key;
						newNode->next = Curr2;
						Prev->next = newNode;
						Curr2 = newNode;
					}

					Curr1 = Curr2;
					Curr2 = Curr2->next;
				}

				while (Curr2 != nullptr && Curr2->data == Key)
				{
					Node* Temp = Curr2;
					Curr2 = Curr2->next;
					Curr1->next = Curr2;
					delete Temp;
				}
			}

			Curr1 = Curr1->next;
		}

		return true;
	}

	~LinkedList()
	{
		while (head != nullptr)
		{
			Node* Curr = head;
			head = head->next;
			delete Curr;
		}
	}
};

void main()
{
	LinkedList List1;
	List1.insertAtEnd(1);
	List1.insertAtEnd(2);
	List1.insertAtEnd(3);
	List1.insertAtEnd(4);
	List1.insertAtEnd(3);
	List1.insertAtEnd(4);
	List1.insertAtEnd(3);

	List1.Display();
}