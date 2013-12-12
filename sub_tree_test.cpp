/*
4.7 Subtree tester
*/
#include <iostream>
#include <queue>
#include <vector>
#include "math.h"

using namespace std;

struct node
{
    int key_value;
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
        void minBST(int arr[], int min, int max); //min depth
        int depth(); // get depth
        bool is_subtree(vector <node*> &vec); //subtree test
        void flatten(vector <node*> &vec); //flatten to vector

    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        void print_tree(node *leaf);
        int depth(node *leaf);
        bool is_subtree(node* leaf, vector <node*> &vec);
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
    if(root != NULL) btree::destroy_tree(root);
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
    {
      vec.push_back(leaf);
      flatten(leaf->left, vec);
      flatten(leaf->right, vec);
    } //pre-order push
}

void btree::flatten(vector<node*> &vec)
{
    flatten(root, vec);
}

bool btree::is_subtree(node *leaf, vector<node*> &vec)
{ // this substring type algorithm may not work for all 1s
    int i, min;
    bool tester = true;
    if(!leaf)
      tester = false;
    else if(leaf->key_value == vec[0]->key_value)
    {   // real subtree tester
        vector<node*> myvec;
        flatten(leaf, myvec);
          cout << "myvec: ";
          for(i = 0; i < myvec.size(); i++) 
          cout << myvec[i]->key_value << " ";
          cout << endl; 
          // vec.size() maybe larger than myvec.size()
          min = vec.size() < myvec.size() ? vec.size():myvec.size();
        for(int i=0; i < min; i++)
          {
            if(vec[i]->key_value != myvec[i]->key_value) tester = false;
          }
    }
    else
    {  // with the root tested first, this comprise a pre-order traversal
      bool lb, rb;
      lb = is_subtree(leaf->left, vec);
      rb = is_subtree(leaf->right, vec);
      if(!lb && !rb)
        tester = false;
    }
    return tester;
}

bool btree::is_subtree(vector<node*> &vec)
{
    return is_subtree(root, vec);
}

int main()
{
   cout << "LCA" << endl;
   
   int i = 0;
   int arr[] = { 1, 2, 3, 4, 5, 6, 7,
                 8, 9, 10, 11, 12, 13, 14, 15};
   btree mytree, mytree2;
   
   // init mytree
   mytree.minBST(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
   mytree.print_tree();
   mytree2.minBST(arr, 0, 3); // make sure arr.size > 7
   mytree2.print_tree();
   
   //flatten mytree2 to myvec2
   vector <node*> myvec2;
   mytree2.flatten(myvec2);
  
  cout << "myvec2: ";
  for(i = 0; i < myvec2.size(); i++) 
    cout << myvec2[i]->key_value << " ";
  cout << endl; 
  
   if(mytree.is_subtree(myvec2))
     cout << "mytree2 is a subtree of mytree" << endl;
   else
     cout << "mytree2 is not a subtree of mytree" << endl;
     
   return 0;
}
