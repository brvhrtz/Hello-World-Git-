/*
 *  String permutation algorithm
 *  C8P4
 */
 
#include <iostream>
#include <vector>

using namespace std;

// char swap 
void swap(char *x, char *y)
{
    char *temp;
    *temp = *x;    *x = *y;    *y = *temp;
}

// use an array to represetn string 
void get_all_permutations(char *arr, int l, int r)
{
    int i;
    
    if(l == r) 
    {
        printf("%s \n", arr);
        return;       
    }
    else
    {        
      for(i = l; i <= r; i++)
      {
          if(i == l || arr[i] != arr[l])
          {
            swap(arr[l], arr[i]);
            get_all_permutations(arr, l+1, r);
            swap(arr[l], arr[i]);
          }
      }
    }
}
    
int main()
{
    cout << " CC150 C8P4 String Permutation " << endl;
    
    int  n;
//    int  tester = 0x1; // bit based is only suitable for subsets type of calculation 
    char a[] = "aac";
//    char a[] = {'a', 'b', 'c', 'd', 'e'};
    
    n = sizeof(a)/sizeof('a') - 1;  // not counting '\0'
    cout << "sizeof array: " << n << endl;
    
    get_all_permutations(a, 0, n-1);
    
    return 0;
}
