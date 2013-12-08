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
        node *left_most();
//        void delete(int key);  
        int  depth();  // max depth
        int  min_depth(); // min depth
        bool is_balanced(); 
        
    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);
        void print_tree(node *leaf);
        node *left_most(node *leaf);  
        int depth(node *leaf);
        int min_depth(node *leaf);
        bool is_balanced(node *leaf);
        
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

node *btree::left_most(node *leaf)
{
    if(!leaf->left) return leaf;
    
    node *cur = leaf->left;
    while(cur->left)
    {
        cur = cur->left;
    }
    return cur;
}

node *btree::left_most()
{
    if(!root) return NULL;
    return left_most(root);
}


/*
void btree::delete(int key)
{
    node *target;
    node *temp;
    
    taret = search(key);
    if(!target)
    {
        cout << "Deletion failed: key not found!" << endl;
        return;  
    } 
    else if(target->left && target->right) 
    {  //replace with left-most node of right sub-tree   
        temp = target;
        target = left_most(target->right);
        
        
    }
    else if(target->left && !target->right)
    {  // one child, replace with child
        temp = target;
        target = target->left;
        delete temp;
    }
    else if(!target->left && target->right)
    {  // one child, replace with right child
        temp = target;
        target = target->right;
        delete temp;
    }
    else
    {  // no child, simply delete itself
        delete target;
        target = NULL;
    }
    return;
}
*/

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

int btree::min_depth(node *leaf)
{
    if(!leaf) return 0;
    if(!leaf->left && !leaf->right) return 1;

    int ld = 0;
    int rd = 0;
    
    if(leaf->left) ld = depth(leaf->left);
    if(leaf->right) rd = depth(leaf->right);
    return 1 + (ld < rd ? ld : rd);   
}

int btree::min_depth()
{
    if(root)
       return min_depth(root);
    else
       return 0;
}

bool btree::is_balanced(node *leaf)
{
    if(!leaf) return true;
    
    int ld = 0;
    int rd = 0;
    
    ld = depth(leaf->left);
    rd = depth(leaf->right);
    
    if(is_balanced(leaf->left) && is_balanced(leaf->right) && abs(ld-rd) <=1) 
      return true;
    else 
      return false;
}

bool btree::is_balanced()
{
    return is_balanced(root);
}

int main()
{
   cout << "Hello World" << endl;   
   
   
   int i = 0;
   int arr[] = {1, 2, 1, 3, 6, 5, 7, 4, 4};
   btree mytree;
   
   // init mytree
   for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) mytree.insert(arr[i]);
   mytree.print_tree();

   // search mytree
   node *mynode;   
   mynode = mytree.search(17);
   if(mynode) 
     cout << mynode->key_value << endl;
   else
     cout << "key not found!" << endl;
     
    // breadth first search
    // mytree.breadth_first();
   
   // left most node 
   cout << "leftmost is " << mytree.left_most()->key_value << endl;
   cout << "depth = " << mytree.depth() << endl;
   cout << "min_depth = " << mytree.min_depth() << endl; 
   cout << "tree is " << (mytree.is_balanced()? "":"not ") << "balanced" <<  endl;
   
   // destroy tree
   mytree.destroy_tree();
   return 0;
}
