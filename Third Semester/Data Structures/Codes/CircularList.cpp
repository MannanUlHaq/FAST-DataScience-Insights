#include <iostream>
using namespace std;

class CDNode
{
private:
    int data;
    CDNode* next, * prev;

    friend class CircularDoublyLinkedList;
};

class CircularDoublyLinkedList
{
private:
    CDNode* head;

public:
    CircularDoublyLinkedList()
    {
        head = nullptr;
    }

    bool insertAtHead(int value)
    {
        CDNode* newNode = new CDNode;
        newNode->data = value;
        newNode->next = head;
        newNode->prev = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        }
        else
        {
            CDNode* lastNode = head->prev;
            newNode->next = head;
            newNode->prev = lastNode;
            head->prev = newNode;
            lastNode->next = newNode;
            head = newNode;
        }

        return true;
    }

    bool insertAtEnd(int value)
    {
        CDNode* newNode = new CDNode;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            CDNode* lastNode = head->prev;
            newNode->next = head;
            newNode->prev = lastNode;
            head->prev = newNode;
            lastNode->next = newNode;
        }

        return true;
    }

    void Print()
    {
        if (head == nullptr)
        {
            cout << "List is Empty!" << endl;
        }
        else
        {
            CDNode* curr = head;

            do
            {
                cout << curr->data << " ";
                curr = curr->next;
            } while (curr != head);

            cout << endl;
        }
    }

    bool Search(int value)
    {
        if (head == nullptr)
        {
            return false;
        }

        CDNode* curr = head;
        do
        {
            if (curr->data == value)
            {
                return true;
            }
            curr = curr->next;
        } while (curr != head);

        return false;
    }

    bool Erase(int value)
    {
        if (head != nullptr)
        {
            CDNode* curr = head;
            do
            {
                if (curr->data == value)
                {
                    if (curr == head)
                    {
                        head = head->next;
                    }
                    CDNode* prevNode = curr->prev;
                    CDNode* nextNode = curr->next;
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                    delete curr;

                    return true;
                }
                curr = curr->next;

            } while (curr != head);
        }

        return false;
    }

    void circleGame(int n, int k)
    {
        int i = 1;
        CDNode* curr = head;
        while (n != 1)
        {
            if (i % k == 0)
            {
                if (curr == head)
                {
                    head = head->next;
                }
                CDNode* prevNode = curr->prev;
                CDNode* nextNode = curr->next;
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                delete curr;
                n--;
            }
            i++;
            curr = curr->next;
        }
    }

    void printBack()
    {
        if (head == nullptr)
        {
            cout << "List is Empty!" << endl;
        }
        else
        {
            CDNode* curr = head->prev;

            do
            {
                cout << curr->data << " ";
                curr = curr->prev;
            } while (curr != head->prev);

            cout << endl;
        }
    }

    bool insertAfter(int key, int value)
    {
        if (head != nullptr)
        {
            CDNode* curr = head;

            do
            {
                if (curr->data == key)
                {
                    CDNode* newNode = new CDNode;
                    newNode->data = value;
                    newNode->next = curr->next;
                    newNode->prev = curr;
                    curr->next->prev = newNode;
                    curr->next = newNode;

                    return true;
                }
                curr = curr->next;

            } while (curr != head);
        }

        return false;
    }

    int Size()
    {
        if (head == nullptr)
        {
            return 0;
        }

        int count = 0;
        CDNode* current = head;
        do {
            count++;
            current = current->next;
        } while (current != head);

        return count;
    }

    int CompleteTour()
    {
        CDNode* Curr1 = head;
        int i = 0;
        do
        {
            CDNode* Curr2 = Curr1;
            int j = 1;

            int Truck_Petrol = 0;
            int Next_Distance = 0;

            do
            {
                Truck_Petrol += Curr2->Petrol;
                Next_Distance = Curr2->Distance;

                if (Truck_Petrol < Next_Distance)
                {
                    break;
                }
                else
                {
                    Truck_Petrol -= Next_Distance;
                    j++;
                }

                Curr2 = Curr2->next;

            } while (Curr2 != Curr1);

            if (j == Size())
            {
                return i;
            }

            i++;

            Curr1 = Curr1->next;

        } while (Curr1 != head);

        return -1;
    }

    ~CircularDoublyLinkedList()
    {
        if (head == nullptr)
        {
            return;
        }

        CDNode* current = head;
        CDNode* nextNode;

        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);

        head = nullptr;
    }
};