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

Node* insert_at_head (Node* head, int data)
{
    Node* new_head = new Node(data);
    new_head ->next = head;
    return new_head;
}

int main ()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    display_list(head);

    bool success = search_list(head, 30);
    bool fail = search_list(head, 50);

    cout << "Search: " << success << endl;
    cout << "Search: " << fail << endl;

    int list_size = size(head);
    cout << "Size: " << list_size << endl;

    head = insert_at_head(head, 5);
    display_list(head);
    return 0;
}
