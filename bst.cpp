#include <iostream>
#include <queue>

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
        node *search(int key);
        void destroy_tree();
        void print_tree();
        void breadth_first();
    
    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);
        void print_tree(node *leaf);
        
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
}

node *btree::search(int key, node* leaf)
{
    if(!leaf) 
      return NULL;
    
//    cout << leaf->key_value << "-----" << key << endl;
    if(key == leaf->key_value) 
      return leaf;
    else if(key < leaf->key_value)
      return search(key, leaf->left);
    else if(key > leaf->key_value)
      return search(key, leaf->right);
}

node *btree::search(int key)
{
    return search(key, root);
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

void btree::breadth_first()
{
    if(!root) return;
    
    node *cur;
    queue <node*> nq;   // queue of nodes
    
    cout << root->key_value << endl;
    nq.push(root);
    cout << nq.front()->key_value << endl;
    
    while(nq.size()){
      cur = nq.front();
      nq.pop();
      
      if(cur->left)
      {
          cout << cur->left->key_value << endl;
          nq.push(cur->left);
      }
      if(cur->right)
      {
          cout << cur->right->key_value << endl;
          nq.push(cur->right);
      }
    }
    
    return;
}

int main()
{
   cout << "Hello World" << endl;   
   
   
   int i = 0;
   btree mytree;
   
   mytree.insert(5);
   for (i = 1; i < 10; i++)
   {
       mytree.insert(i);
   }
   
   mytree.print_tree();

   
   node *mynode;   
   mynode = mytree.search(7);
   if(mynode) 
     cout << mynode->key_value << endl;
   else
     cout << "key not found!" << endl;

   mynode = mytree.search(17);
   if(mynode) 
     cout << mynode->key_value << endl;
   else
     cout << "key not found!" << endl;
     
   mytree.breadth_first();
 
   mytree.destroy_tree();
   return 0;
}
