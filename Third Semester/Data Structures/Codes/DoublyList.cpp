#include<iostream>
#include<vector>
using namespace std;

class DoublyLinkedList;

class DNode
{
    int Data;
    DNode* Next, * Prev;

    friend class DoublyLinkedList;
};

class DoublyLinkedList
{
    DNode* Head;

public:
    DoublyLinkedList()
    {
        Head = nullptr;
    }

    bool insertAtStart(int Value)
    {
        DNode* newNode = new DNode;
        newNode->Data = Value;
        newNode->Next = Head;
        newNode->Prev = nullptr;

        if (Head != nullptr)
        {
            Head->Prev = newNode;
        }

        Head = newNode;

        return true;
    }

    bool insertAtEnd(int Value)
    {
        DNode* newNode = new DNode;
        newNode->Data = Value;
        newNode->Next = nullptr;

        if (Head == nullptr)
        {
            newNode->Prev = nullptr;
            Head = newNode;

            return true;
        }
        else
        {
            DNode* Curr = Head;

            while (Curr->Next != nullptr)
            {
                Curr = Curr->Next;
            }

            Curr->Next = newNode;
            newNode->Prev = Curr;


            return true;
        }
    }

    bool sortedInsert(int Value)
    {
        DNode* newNode = new DNode;
        newNode->Data = Value;

        if (Head == nullptr || Value <= Head->Data)
        {
            newNode->Next = Head;
            newNode->Prev = nullptr;

            if (Head != nullptr)
            {
                Head->Prev = newNode;
            }

            Head = newNode;

            return true;
        }
        else
        {
            DNode* Curr = Head;

            while (Curr->Next != nullptr && Curr->Next->Data <= Value)
            {
                Curr = Curr->Next;
            }

            newNode->Next = Curr->Next;
            newNode->Prev = Curr;

            if (Curr->Next != nullptr)
            {
                Curr->Next->Prev = newNode;
            }

            Curr->Next = newNode;

            return true;
        }
    }

    bool deleteFromStart()
    {
        if (Head == nullptr)
        {
            cout << "List is Empty!" << endl;

            return false;
        }
        else
        {
            DNode* Temp = Head;
            Head = Head->Next;

            if (Head != nullptr)
            {
                Head->Prev = nullptr;
            }

            delete Temp;

            return true;
        }
    }

    bool deleteFromEnd()
    {
        if (Head == nullptr)
        {
            cout << "List is Empty!" << endl;
            return false;
        }
        else
        {
            if (Head->Next == nullptr)
            {
                delete Head;
                Head = nullptr;
            }
            else
            {
                DNode* Curr = Head;

                while (Curr->Next != nullptr)
                {
                    Curr = Curr->Next;
                }

                Curr->Prev->Next = nullptr;
                delete Curr;
            }

            return true;
        }
    }

    DNode* Search(int Value)
    {
        DNode* Curr = Head;

        while (Curr != nullptr)
        {
            if (Curr->Data == Value)
            {
                return Curr;
            }

            Curr = Curr->Next;
        }

        return nullptr;
    }

    bool deleteSpecificValue(int Value)
    {
        DNode* Temp = Search(Value);

        if (Temp == nullptr)
        {
            cout << "The Value " << Value << " not found in the List!" << endl;

            return false;
        }

        if (Temp->Prev != nullptr)
        {
            Temp->Prev->Next = Temp->Next;
        }
        else
        {
            Head = Temp->Next;
        }

        if (Temp->Next != nullptr)
        {
            Temp->Next->Prev = Temp->Prev;
        }

        delete Temp;

        return true;
    }

    void Display()
    {
        if (Head == nullptr)
        {
            cout << "List is Empty!" << endl;
        }
        else
        {
            cout << "List: ";

            DNode* Curr = Head;

            while (Curr != nullptr)
            {
                cout << Curr->Data << " ";
                Curr = Curr->Next;
            }
            cout << endl;
        }
    }

    int Size()
    {
        if (Head == nullptr)
            return 0;
        else
        {
            int size = 0;

            DNode* Curr = Head;
            while (Curr != nullptr)
            {
                size++;
                Curr = Curr->Next;
            }

            return size;
        }
    }

    bool movHead(int Position)
    {
        if (Position < 0 || Position >= Size())
            return false;
        if (Position == 0)
            return true;

        DNode* Curr = Head;
        for (int i = 0; i < Position; i++)
            Curr = Curr->Next;

        DNode* Tail = Curr;
        while (Tail->Next != nullptr)
            Tail = Tail->Next;

        Tail->Next = Head;
        Head->Prev = Tail;
        Head = Curr;
        Tail = Head->Prev;
        Tail->Next = nullptr;
        Head->Prev = nullptr;

        return true;
    }

    bool RemoveSubList(DoublyLinkedList* DLL2)
    {
        if (Head == nullptr)
            return false;

        DNode* Curr1 = Head;
        DNode* Curr2 = DLL2->Head;
        int Index1 = 0;
        int Index2 = 0;
        vector<int> v;

        while (Curr1 != nullptr)
        {
            if (Curr1->Data == Curr2->Data)
            {
                v.push_back(Index1);
                Index2++;

                if (Index2 == DLL2->Size())
                    break;

                Curr2 = Curr2->Next;
            }
            else
            {
                Index2 = 0;
                Curr2 = DLL2->Head;

                v.clear();
            }

            Index1++;
            Curr1 = Curr1->Next;
        }

        if (v.empty())
            return false;

        for (int i = v.size() - 1; i >= 0; i--)
        {
            DNode* Curr = Head;
            for (int j = 0; j < v[i]; j++)
            {
                Curr = Curr->Next;
            }

            if (Curr->Prev != nullptr)
                Curr->Prev->Next = Curr->Next;
            if (Curr->Next != nullptr)
                Curr->Next->Prev = Curr->Prev;

            delete Curr;
            Curr = nullptr;
        }

        return true;
    }

    ~DoublyLinkedList()
    {
        while (Head != nullptr)
        {
            DNode* Curr = Head;
            Head = Head->Next;
            delete Curr;
        }
    }
};

void main()
{
    DoublyLinkedList List1;
    List1.insertAtEnd(2);
    List1.insertAtEnd(3);
    List1.insertAtEnd(3);
    List1.insertAtEnd(5);
    List1.insertAtEnd(6);
    List1.insertAtEnd(7);
    List1.insertAtEnd(8);

    List1.Display();
}