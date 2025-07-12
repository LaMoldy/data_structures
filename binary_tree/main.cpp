#include <iostream>
#include <queue>

using namespace std;

struct Node
{
     int data;
     Node* left;
     Node* right;   

     Node (int data)
     {
          this->data = data;
          this->left = nullptr;
          this->right = nullptr;
     }
};

// DFS: Depth-First Search
// Visits left subree, then node, then right
void inOrderDFS (Node* node)
{
     if (node == nullptr) return;

     inOrderDFS(node->left);
     cout << node->data << " ";
     inOrderDFS(node->right);
}

// Visits the node first, then left subtree, then right subtree
void preOrderDFS(Node* node)
{
     if (node == nullptr) return;

     cout << node->data << " ";
     preOrderDFS(node->left);
     preOrderDFS(node->right);
}

// Visits left subtree, right subtree, then the node
void postOrderDFS(Node* node)
{
     if (node == nullptr) return;

     postOrderDFS(node->left);
     postOrderDFS(node->right);
     cout << node->data << " ";
}

// BFS: Breadth-First Search
// Explores all nodes at present depth before moving to next depth level
void BFS (Node* root)
{
     if (root == nullptr) return;
     queue<Node*> q;
     q.push(root);

     while (!q.empty())
     {
          Node* node = q.front();
          q.pop();
          cout << node->data << " ";
          if (node->left != nullptr) q.push(node->left);
          if (node->right != nullptr) q.push(node->right);
     }
}

// Returns height which is the number of edges along
// the longest path from the root node down to the
// farthest leaf node
int height (Node* root)
{
     if (root == nullptr) return -1;

     int leftHeight = height(root->left);
     int rightHeight = height(root->right);

     return max(leftHeight, rightHeight) + 1;
}

Node* insert_node (Node* root, int data)
{
     if (root == nullptr)
     {
          root = new Node(data);
          return root;
     }

     queue<Node*> queue;
     queue.push(root);

     while (!queue.empty())
     {
          Node* current = queue.front();
          queue.pop();

          if (current->left != nullptr)
          {
               queue.push(current->left);
          }
          else
          {
               current->left = new Node(data);
               return root;
          }

          if (current->right != nullptr)
          {
               queue.push(current->right);
          }
          else
          {
               current->right = new Node(data);
               return root;
          }
     }

     return root;
}

void deleteDeepest (Node* root, Node* dNode)
{
     queue<Node*> queue;
     queue.push(root);

     Node* current;
     while (!queue.empty())
     {
          current = queue.front();
          queue.pop();

          // Delete if current is deepest node
          if (current == dNode)
          {
               current = nullptr;
               delete dNode;
               return;
          }

          // Check the right child
          if (current->right)
          {
               // If deepest delete it
               if (current->right == dNode)
               {
                    current->right = nullptr;
                    delete dNode;
                    return;
               }

               queue.push(current->right);
          }

          // Check the left tree
          if (current->left)
          {
               // If deepest delete it
               if (current->left == dNode)
               {
                    current->left = nullptr;
                    delete dNode;
                    return;
               }
               queue.push(current->left);
          }
     }
}

Node* deletion (Node* root, int key)
{
     if (root == nullptr) return nullptr;

     if (root->left == nullptr && root->right == nullptr)
     {
          if (root->data == key) return nullptr;
          return root;
     }

     queue<Node*> queue;
     queue.push(root);

     Node* current;
     Node* keyNode = nullptr;

     // Loop to find deepest node and key node
     while (!queue.empty())
     {
          current = queue.front();
          queue.pop();

          if (current->data == key)
          {
               keyNode = current;
          }

          if (current->left)
          {
               queue.push(current->left);
          }

          if (current->right)
          {
               queue.push(current->right);
          }
     }

     // If key node is found replace data with deepest node
     if (keyNode != nullptr)
     {
          int temp = current->data;
          keyNode->data = temp;
          deleteDeepest(root, current);
     }

     return root;
}

int main (void)
{
     // Representation of the input tree:
     //      12
     //     /  \
     //    8   18
     //   /  \
     //  5   11
     
     Node* root = new Node(12);
     root->left = new Node(8);
     root->right = new Node(18);
     root->left->left = new Node(5);
     root->left->right = new Node(11);

     cout << "In-order DFS: ";
     inOrderDFS(root);

     cout << "\nPre-order DFS: ";
     preOrderDFS(root);

     cout << "\nPost-order DFS: ";
     postOrderDFS(root);

     cout << "\nLevel order: ";
     BFS(root);

     cout << "\nHeight: " << height(root);

     int insertKey = 15;
     root = insert_node(root, insertKey);

     cout << "\nLevel order: ";
     BFS(root);
          
     int deleteKey = 15;
     root = deletion(root, deleteKey);

     cout << "\nLevel order: ";
     BFS(root);
     return 0;
}
