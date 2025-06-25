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

Node* insert_at_tail (Node* head, int data)
{
    Node* new_node = new Node(data);

    if (head == nullptr)
    {
        return new_node;
    }

    Node* last = head;

    while (last->next != nullptr)
    {
        last = last->next;
    }

    last->next = new_node;

    return head;
}

Node* insert_at (Node* head, int data, int index)
{
    if (index < 1)
    {
        return head;
    }

    if (index == 1)
    {
        Node* new_node = new Node(data);
        new_node->next = head;
        return new_node;
    }

    Node *current_head = head;

    for (int i = 1; i < index - 1 && current_head != nullptr; i++)
    {
        current_head = current_head->next;
    }

    if (current_head == nullptr)
    {
        return head;
    }

    Node* new_node = new Node(data);

    new_node->next = current_head->next;
    current_head->next = new_node;
    
    return head;
}

Node* delete_at_start (Node* head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}

Node* delete_at_end (Node* head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node* second_last = head;
    while (second_last->next->next != nullptr)
    {
        second_last= second_last->next;
    }

    delete (second_last->next);
    second_last->next = nullptr;

    return head;
}

Node* delete_at (Node* head, int index)
{
    Node* prev;
    Node* temp = head;
    
    if (temp == NULL)
    {
        return nullptr;
    }

    if (index == 1)
    {
        head = temp->next;
        free(temp);
        return head;
    }

    for (int i = 1; i != index; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL)
    {
        prev->next = temp->next;
        free(temp);
    }

    return head;
}

Node* modify (Node* head, int data, int index)
{
    
    if (index < 1)
    {
        head->data = data;
        return head;
    }

    Node *current_head = head;

    for (int i = 1; i < index - 1 && current_head != nullptr; i++)
    {
        current_head = current_head->next;
    }

    if (current_head == nullptr)
    {
        return head;
    }

    current_head->data = data;
    return head;
}
int main ()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Display Normal:" << endl;
    display_list(head);

    cout << endl << "Searching:" << endl;
    bool success = search_list(head, 30);
    bool fail = search_list(head, 50);

    cout << "Search: " << success << endl;
    cout << "Search: " << fail << endl;

    int list_size = size(head);
    cout << endl << "Size: " << list_size << endl;

    cout << endl << "Insert at front:" << endl;
    head = insert_at_head(head, 5);
    display_list(head);

    cout << endl << "Insert at end:" << endl;
    head = insert_at_tail(head, 50);
    display_list(head);

    cout << endl << "Insert at index 4:" << endl;
    head = insert_at(head, 25, 4);
    display_list(head);

    cout << endl << "Delete at start:" << endl;
    head = delete_at_start(head);
    display_list(head);

    cout << endl << "Delete at end:" << endl;
    head = delete_at_end(head);
    display_list(head);
    
    cout << endl << "Delete at index 4:" << endl;
    head = delete_at(head, 4);
    display_list(head);

    cout << endl << "Modify at index 4:" << endl;
    head = modify(head, 4, 3);
    display_list(head);

    
    return 0;
}
