#include <iostream>
#include <queue>
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

    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        void print_tree(node *leaf);
        int depth(node *leaf);

        
        node *root;
        int  height;
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
    if(root != NULL)
      btree::destroy_tree(root);
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
  height = depth();
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

int btree::depth(node *leaf)
{
    if(!leaf) return 0;
    if(!leaf->left && !leaf->right) return 1;

    int ld = 0;
    int rd = 0;
    
    if(leaf->left) ld = depth(leaf->left);
    if(leaf->right) rd = depth(leaf->right);
    return 1 + (ld > rd ? ld : rd); 
}

int btree::depth()
{
    if(root) 
        return depth(root);
    else
        return 0;
}


int main()
{
   cout << "Hello World" << endl;   
   
   int i = 0;
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
   btree mytree;
   
   // init mytree
   mytree.minBST(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
   mytree.print_tree();
 

   return 0;
}

