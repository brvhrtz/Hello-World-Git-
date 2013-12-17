/*
 * C4P4 Given a binary search tree
 * Creates a linked list of all the nodes at each depth 
 * (i.e., if you have a tree with depth D, you’ll have D linked lists). 
 */

#include <iostream>
#include <queue>
#include "math.h"

using namespace std;

struct lnode
{
    int key_value;
    lnode *next;
};

class llist
{
    public:
      llist();
      ~llist();
      bool add(int key_value);
      void print();      
      
    private:
      lnode *head;
};

llist::llist()
{
    head = NULL;
}

llist::~llist()
{
    lnode *cur, *target;
    
    cur = head;
    while(cur != NULL)
    {
        target = cur;
        cur = cur->next;
        if(target) delete target;
    }
    cout << " list deleted" << endl;
    return;
}

bool llist::add(int value)
{
    lnode *temp;
    
    if(!head) 
    {
//        cout << " init head " << endl;
        head = new lnode;
        head->key_value = value;
        head->next = NULL;
    } 
    else 
    {
//        cout << " add nodes " <<  value << endl;        
        temp = new lnode;
        temp->key_value = value;
        temp->next = head; 
        head = temp;
 
 } 
    return true;
}

void llist::print()
{
    lnode *cur;
    
    cur = head;
    while(cur != NULL)
    {
        cout << cur->key_value << " ";
        cur = cur->next;
    }
    cout << endl;
}

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
        void make_list();

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
        cout << "Destroy BST" << leaf->key_value << endl;
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

void btree::make_list()
{
    if(!root) return;
    
  
    node *cur;
    llist mylists[height];
    int idx=0;
    
    cout << "tree height is " << height << endl;
    queue <node*> nq;
    nq.push(root);
    nq.push(NULL);
    while(nq.size())
    {    
        cout << "size = " << nq.size() << endl;
        cur = nq.front();
        nq.pop();
        if(cur == NULL) 
        { 
            cout << " this is a null" << endl; 
            cout << "last list constructed: "; 
            mylists[idx].print();
            idx++;           
            nq.push(NULL);            
            cur = nq.front(); // renew cur
            nq.pop();
        }
           
        if(cur) 
        {
          if(cur->left) nq.push(cur->left);
          if(cur->right) nq.push(cur->right);
          cout << cur->key_value << endl;
          mylists[idx].add(cur->key_value);
        }          
    } 
  
}

int main()
{
   cout << "Hello World" << endl;   
   
   int i = 0;
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
   btree mytree;
   
   // init mytree
   //for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) mytree.insert(arr[i]);
   mytree.minBST(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
   mytree.print_tree();
   mytree.make_list();
 
      // destroy tree, 
    // mytree.destroy_tree(); // wrong, never call dtor explicitly
   
   // init linked list
   llist mylist;
   for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)      mylist.add(arr[i]);
   mylist.print();
   

   return 0;
}

