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
        node *lca(int key1, int key2);

    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        void print_tree(node *leaf);
        int depth(node *leaf);
        node *lca(node *leaf, int key1, int key2);
        
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

node *btree::lca(node *leaf, int key1, int key2)
{   // assume both nodes exist and no duplicate
    node *ln = NULL;
    node *rn = NULL;
    
    if(leaf == NULL)
      return NULL;
    else if(leaf->key_value == key1 || leaf->key_value == key2)
    {// the other node is either down or on another branch
     // in both cases, return and let the caller decides
      return leaf; 
    }
    else
    {
        if(leaf->left) ln = lca(leaf->left, key1, key2);
        if(leaf->right) rn = lca(leaf->right, key1, key2);
        if(ln && rn) 
          return leaf;
        else if(ln && !rn)  
          return ln; 
        else if(!ln && rn) 
          return rn; 
        else return NULL;
    }
}

node *btree::lca(int key1, int key2)
{   // assume both nodes exist
    return lca(root, key1, key2);
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
   // LCA 
   node *mylca = mytree.lca(8, 15);
   if(mylca)
     cout << "lca is: " << mylca->key_value << endl;
 

   return 0;
}
