#include <iostream>
#include <vector>

using namespace std;

class StackItem
{
     private:
          int data;

     public:
          StackItem (int data)
          {
               this->data = data;     
          }
          
          int get_data ()
          {
               return this->data;
          }   
};

class Stack
{
     private:
          vector<StackItem>* stack;

     public:
          Stack ()
          {
               stack = new vector<StackItem>;     
          }
          
          void push (int data)
          {
               this->stack->insert(this->stack->begin(), data);
          }

          void pop ()
          {
               this->stack->erase(this->stack->begin());
          }

          int peek ()
          {
               return this->stack->front().get_data();
          }

          void display ()
          {
               cout << endl << "Display: " << endl;
               for (StackItem item : *stack)
               {
                    cout << item.get_data() << endl;
               }
          }

          int size ()
          {
               return this->stack->size();
          }

          bool is_empty ()
          {
               return this->stack->size() == 0;
          }
          
};

int main (void)
{
     Stack* stack = new Stack();
     
     if (stack->is_empty())
     {
          cout << "Empty" << endl;
     }

     stack->push(1);

     cout << "Size: " << stack->size() << endl;

     stack->push(2);
     
     int peeked = stack->peek();
     cout << "Peaked: " << peeked << endl;
     
     stack->push(3);
     stack->display();
     stack->pop();
     stack->display();

     if (!stack->is_empty())
     {
          cout << "Not empty" << endl;
     }

     return 0;
}
