/* 
 * CC150 Q8.8  Eight Queuens
 */
 
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define N 8 

void print_matrix(int m[N][N])
{
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      if(m[i][j] == 2) cout << "x ";
      else cout << "0 ";
    }
    cout << endl;
  }
}

int sum(int m[N][N])
{
  int temp = 0;
  
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      temp += m[i][j];
    }
  }
  return temp;
}

void eight_queuen(int x, int y, int count, int m[N][N])
{
  int i, j;

  m[x][y] = 2;
//  print_matrix(m);
  if(count == N)
  {
    print_matrix(m);
    cout << endl << "cout = " << count << endl; 
    return;
  }

  for(i = 0; i < N; i++)
  {
    for(j = 0; j < N; j++)
    {
      if(x == i && y == j) continue;
      if(i == x || j == y || abs(i-x) == abs(j-y))
      {
        m[i][j] = 0; 
      }
    }
  }
  for(i = 0; i < N; i++)
  {
    for(j = 0; j < N; j++)
    {
      if(x == i && y == j) continue;
      if(m[i][j] == 1) eight_queuen(i, j, count+1, m); 
    }
  }
  return;
}
void reset_matrix(int m[N][N])
{
  int i,j;

  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++) {
      m[i][j] = 1;
    }
  }

}
int main()
{
  cout << " CC150 Q8.8 " << endl;
  
  int i, j;
  int matrix[N][N];
  

  for(i = 0; i < N; i++)
  {
      cout << "i = " << i << endl; 
      reset_matrix(matrix);
      eight_queuen(i, 0, 1, matrix);
  } 
//  eight_queuen(0, 0, 0, matrix);  
  return 0;
}

/*
 * Gotchas:
 * 1. arrays are passed as pointers and can't be passed by value. So after each recursion return, you need to reset the array
 * 2. avoiding infinite loop in recursion.  
 *    - the coordinates shouldn't be picked up again in current loop. 
 *    - especially pay attention that coordinates shouldn't be picked up again in deeper loops or shallower loops
*  3. 2d array is simple and use different integer value to indicate different status 
*/
