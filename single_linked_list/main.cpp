#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node (int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void display_list (Node* head)
{
    while (head != nullptr)
    {
        cout << "Data: " << head->data << endl;
        head = head->next;
    }
}

bool search_list (Node* head, int data)
{
    while (head != nullptr)
    {
        if (head->data == data)
        {
            return true;
        }

        head = head->next;
    }

    return false;
}

int size (Node* head)
{
    int index_count = 0;

    while (head != nullptr)
    {
        index_count++;
        head = head->next;
    }

    return index_count;
}

int main ()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    return 0;
}
