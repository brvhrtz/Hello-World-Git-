/*
 *  C9P6 find elements in row&column sorted matrix
 *
 * Given a matrix in which each row and each column is sorted
 * write a method to find an element in it. 
 */
 
#include <iostream>
#include <vector>
#define N 25

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
    node *temp;
    node *target = NULL;
    
    cout << "(" << lx <<"," << ly << ")" << " " << "(" << rx << "," << ry <<")"<< endl; 
    if(rx-lx == 1)
    {
        if(a[lx][ly] == key) 
        {
            target = new node;
            target->x = lx; target->y = ly; 
            return target;
        }
        if(a[lx][ry] == key) 
        {
            target = new node;
            target->x = lx; target->y = ry; 
            return target;
        }
        if(a[rx][ly] == key) 
        {
            target = new node;
            target->x = rx; target->y = ly; 
            return target;
        }
        if(a[rx][ry] == key) 
        {
            target = new node;
            target->x = rx; target->y = ry; 
            return target;
        }
        return NULL;
    }
    
    x = (lx + rx)/2;
    y = (ly + ry)/2;
    if((rx-lx)%2 == 0)
    {        
    if(key <= a[x][y] && !target)  target = find_element(a, lx, ly, x, y, key);

    if(!target) target = find_element(a, lx, y, x, ry, key);

    if(!target) target = find_element(a, x, ly, rx, y, key);

    if(key >= a[x][y] && !target)  target = find_element(a, x, y, rx, ry, key);
    } 
    else 
    {
    if(key <= a[x][y] && !target)  target = find_element(a, lx, ly, x, y, key);

    if(!target && y+1 < N) target = find_element(a, lx, y + 1, x, ry, key);

    if(!target && x+1 < N) target = find_element(a, x+1, ly, rx, y, key);
  
    if(key >= a[x][y] && !target && (x+1) < N && (y+1) < N)  
                 target = find_element(a, x+1, y+1, rx, ry, key);
    }
    return target;
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
    
    node *target;
    target = find_element(a, 0, 0, N-1, N-1, 25);
    
    if(target)
    {
        cout << (target->x) << "," << (target->y) << endl; 
        // delete node;
    }
    return 0;
}
