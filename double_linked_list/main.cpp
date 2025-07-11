#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node (int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;        
    }
};

void traverse_forwards (Node* head)
{
    int index = 1;

    while (head != nullptr)
    {
        cout << index << ": " << head->data << endl;
        head = head->next;
        index++;
    }
}

void traverse_backwards (Node* head)
{
    int index = 1;

    while (head != nullptr)
    {
        cout << index << ": " << head->data << endl;
        head = head->prev;
        index++;
    }
}

int size (Node* head)
{
    int size = 0;

    while (head != nullptr)
    {
        size++;
        head = head->next;
    }

    return size;
}

int main (void)
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(40);
    head->next->next->next->prev = head->next->next;

    cout << "Traverse Forwards:" << endl;
    traverse_forwards(head);

    cout << endl << "Traverese Backwards:" << endl;
    traverse_backwards(head->next->next->next);

    cout << endl << "Size: " << size(head) << endl;

    return 0;
}
