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

int main (void)
{
     Node* root = new Node(2);
     root->left = new Node(3);
     root->right = new Node(4);
     root->left->left = new Node(5);

     cout << "In-order DFS: ";
     inOrderDFS(root);

     cout << "\nPre-order DFS: ";
     preOrderDFS(root);

     cout << "\nPost-order DFS: ";
     postOrderDFS(root);

     cout << "\nLevel order: ";
     BFS(root);
          
     return 0;
}
