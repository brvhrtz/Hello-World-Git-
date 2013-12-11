#include <iostream>
#include <queue>
#include <vector>
#include "math.h"

using namespace std;

struct node
{
    int  key_value;
    node *left;
    node *right;
};

class btree
{
    public: 
        btree();
        ~btree();
        
        void insert(int key);
        void destroy_tree();
        void print_tree();
        void minBST(int arr[], int min, int max);  // built BST with min depth
        int  depth();  // max depth
        void flatten(vector <node *> &vec);
         //flatten to a vector

    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        void print_tree(node *leaf);
        int depth(node *leaf);
        void flatten(node *leaf, vector <node *> &vec);
        
        node *root;
};

btree::btree()
{
    root = NULL;
}

btree::~btree() 
{ 
    destroy_tree(); 
}

void btree::destroy_tree(node *leaf)
{
    if(leaf!=NULL)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void btree::destroy_tree()
{
    if(root != NULL)   btree::destroy_tree(root);
}

void btree::insert(int key, node *leaf)
{
    if(key< leaf->key_value)
    {
        if(leaf->left!=NULL)
          insert(key, leaf->left);
        else
        {
          leaf->left=new node;
          leaf->left->key_value = key;
          leaf->left->left = NULL; 
          leaf->left->right = NULL;
        }
    } 
    else if(key >= leaf->key_value) 
    {
        if(leaf->right!=NULL)
          insert(key, leaf->right);
        else
        {
            leaf->right = new node;
            leaf->right->key_value = key;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }
}

void btree::insert(int key)
{
  if(root!=NULL)
    insert(key, root);
  else
  {
      root = new node;
      root->key_value = key;
      root->left = NULL;
      root->right = NULL;
  }
}


void btree::print_tree(node *leaf)
{
  if(!leaf)  
      return;
  else
  {
      if(leaf->left) print_tree(leaf->left);
      if(leaf->right) print_tree(leaf->right);
      cout << leaf->key_value << endl;
  }
}

void btree::print_tree()
{
    btree::print_tree(root);
}

void btree::minBST(int arr[], int min, int max)
{
    if(!arr) return;
    
    int idx = 0;
    if(min == max) 
        insert(arr[min]);
    else if(max-min == 1)
    {
        insert(arr[max]);
        insert(arr[min]);
    }
    else 
    {
        idx = floor((min+max)/2);
        insert(arr[idx]);
        minBST(arr, min, idx-1);
        minBST(arr, idx+1, max);
    }
    return;
}

// in order flatten
void btree::flatten(node *leaf, std::vector<node*> &vec)
{
    if(!leaf) 
      return; 
    else 
    { //in-order 
      flatten(leaf->left, vec);
      vec.push_back(leaf);
      flatten(leaf->right, vec);
    }   
}

void btree::flatten(vector<node*> &vec)
{
    flatten(root, vec);
}

int main()
{
   cout << "LCA" << endl;   
   
   int i = 0;
   int arr[] = { 1,  2,  3,  4,  5,  6,  7, 
                 8,  9, 10, 11, 12, 13, 14, 15};
   btree mytree;
   
   // init mytree
   mytree.minBST(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
   mytree.print_tree();
   
   //flatten
   vector <node*> myvec;
   mytree.flatten(myvec);
   cout << "flattened tree: " << endl;
   for(i = 0; i < myvec.size(); i++)
     cout << myvec[i]->key_value << endl; 
  

   return 0;
}
