/*
 * CC150 C8P7
 * Given an infinite number of quarters/25c, dimes/10c, nickels/5c and pennies/1c
 * Calculate the number of ways of representing n cents. 
 */
 
#include <iostream>
#include <vector>

using namespace std;

void swap(char *x, char *y)
{
    char *temp;
    *temp = *x;    *x = *y;    *y = *temp;
}

int get_sum(vector<int> &vec)
{
    int sum = 0;
    
    for(int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
    }
    return sum;
}

int print_vec(vector<int> &vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        cout <<  vec[i] << " "; 
    }
    cout << endl; 
}
// get representations
// Input: sum, representation vector
// Output: none
void get_combs(int n,  vector<int> &vec)
{ 
    int last; // last element in previous vec
    int sum = get_sum(vec);
//    cout << "n = " << n << " sum = " << sum << endl; 
    if(sum > n) return;
    if(sum == n) 
    {
       print_vec(vec);  
       return;
    }

    if(sum != 0)     last = vec.back();
    vec.push_back(25);
    get_combs(n, vec);
    
    if(last >= 10)
    {
    vec[vec.size()-1] = 10;
    get_combs(n, vec);
    }
    if(last >= 5)
    {
    vec[vec.size()-1] = 5;
    get_combs(n, vec);
    }
    if(last >= 1)
    {
    vec[vec.size()-1] = 1; 
    get_combs(n, vec);
    }
//    vec.erase(vec.end()-1);
    vec.pop_back();  
    return; 
}

int main()
{
    cout << " CC150 C8P7 represent n cents " << endl;
    
    vector<int> vec;
    get_combs(12, vec);
    
    return 0;
}
