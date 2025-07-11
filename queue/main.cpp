#include <iostream>
#include <vector>

using namespace std;

class QueueItem
{
     private:
          int data;

     public:
          QueueItem (int data)
          {
               this->data = data;
          }

          int get_data ()
          {
               return this->data;
          }
};

class Queue
{
     private:
          vector<QueueItem>* queue;                    
          
     public:
          Queue ()
          {
               this->queue = new vector<QueueItem>;
          }

          void push (int data)
          {
               this->queue->insert(this->queue->end(), data);
          }

          void pop ()
          {
               this->queue->erase(this->queue->begin());
          }
          
          void display ()
          {
               cout << endl << "Data:" << endl;

               for (QueueItem item : *queue)
               {
                    cout << item.get_data() << endl;
               }
          }

          bool is_empty ()
          {
               return this->queue->size() == 0;
          }
          
          int peek ()
          {
               return this->queue->front().get_data();
          }
          
          int size ()
          {
               return this->queue->size();
          }

          ~Queue ()
          {
               delete this->queue;
          }
};

int main (void)
{
     Queue* queue = new Queue();

     if (queue->is_empty())
     {
          cout << "Empty" << endl;
     }

     queue->push(1);

     int peeked = queue->peek();
     cout << "Peaked: " << peeked << endl;

     cout << "Size: " << queue->size() << endl;
     
     queue->push(2);
     queue->push(3);
     queue->display();
     queue->pop();
     queue->display();

     if (!queue->is_empty())
     {
          cout << "Not empty" << endl;
     }

     
     return 0;
}
