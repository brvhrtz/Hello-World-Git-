/*
 *  C9P6 find elements in row&column sorted matrix
 *
 * Given a matrix in which each row and each column is sorted
 * write a method to find an element in it. 
 */
 
#include <iostream>
#include <vector>
#define N 6

using namespace std;


struct node {
  int x; 
  int y;
  int key_value; 
};

// input: upper-left corner coordinates, bottom-right coordinates, value to be found, matrix
void print_matrix(int a[N][N])
{
  for(int i = 0; i < N; i++)
  {
      for(int j = 0; j < N; j++)
      {
          cout << a[i][j] << "  ";
      }
      cout << endl;
  }
}

node *find_element(int a[N][N], int lx, int ly, int rx, int ry, int key)
{
    int x, y, i, j;
    
    x = (lx + rx)/2;
    y = (ly + ry)/2;
    if(key <= a[x][y]) 
        find_element(a, lx, ly, x, y, key);
        
        find_element(a, lx, y, x, ry, key);
        
        find_element(a, x, ly, rx, y, key);
    
    if(key >= a[x][y]) 
        find_element(a, x, y, rx, ry, key);
    
}

int main()
{ 
    int a[N][N];
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
          a[i][j] = i + j;        
        }
    }
    print_matrix(a);
    
    node *mynode;
    node = find_element(a, 0, 0, N-1, N-1, 7);
    
    if(node) delete node;
    return 0;
}
