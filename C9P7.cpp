/*
 *  C9P7 Circus Human Tower
 */
 
// Problem: A circus is designing a tower routine consisting of people standing atop one // another’s shoulders. For practical and aesthetic reasons, each person must be both 
// shorter and lighter than the person below him or her. Given the heights and weights of 
// each person in the circus, write a method to compute the largest possible number of 
// people in such a tower. 
// EXAMPLE: Input (ht, wt): (65, 100) (70, 150) (56, 90) (75, 190) (60, 95) (68, 110) 
// Output: The longest tower is length 6 and includes from top to bottom: 
// (56, 90) (60,95) (65,100) (68,110) (70,150) (75,190) 

// Basic algroitm
// Sort based on one preference first and then calculate the longest increasing subseuquence. 

#include <iostream>
#include <vector>    // for vector
#include <algorithm> // for sort

using namespace std;

struct person {
    int height;
    int weight;
};
// Longest increasing (non-decreasing) subsequence
// input: a sequence, 
// length of LIS for the input sequence
int lis(vector<int> &seq)
{
    int i, j;
    int max = 0;
    vector<int>  lisAt;
    
    for(int i = 0; i < seq.size(); i++) lisAt.push_back(1);
    
    for(i = 0; i < seq.size(); i++)
    { // walks through all elements 
        for(j = 0; j < i; j++)
        { // walks through previous elements
            if(seq[j] < seq[i] && lisAt[j] > max) max = lisAt[j];
        }
        lisAt[i] = max + 1;
        max = 0;  // needs to reset max otherwise current max can be the largest forever
//        cout << "listAt[" << i << "] " << lisAt[i] << endl;  
    }
    max = 0;
    for(i = 0; i < lisAt.size(); i++)
    {
        if(lisAt[i] > max) max = lisAt[i];
    }
    return max; 
}

int lis(vector<person*> &seq)
{
    int i, j;
    int max = 0;
    vector<int>  lisAt;
    
    for(int i = 0; i < seq.size(); i++) lisAt.push_back(1);
    
    for(i = 0; i < seq.size(); i++)
    { // walks through all elements 
        for(j = 0; j < i; j++)
        { // walks through previous elements
            if(seq[j]->weight < seq[i]->weight && lisAt[j] > max) max = lisAt[j];
        }
        lisAt[i] = max + 1;
        max = 0;  // needs to reset max otherwise current max can be the largest forever
//        cout << "listAt[" << i << "] " << lisAt[i] << endl;  
    }
    max = 0;
    for(i = 0; i < lisAt.size(); i++)
    {
        if(lisAt[i] > max) max = lisAt[i];
    }
    return max; 
}

// if return true, a preceeds b
// Return true if a should come before b
bool myfunction (person *a,person *b) { return (a->height < b->height); }


int main()
{
    vector<person*> everyone; 
    vector<int> weights = {5, 6, 3, 4, 1, 2};
    vector<int> heights = {6, 5, 4, 3, 2, 1};
 
    
    cout << "LIS = " << lis(weights) << endl; 
    cout << "LIS = " << lis(heights) << endl;
    
    person *p;
    int i;
    for(i = 0; i < weights.size(); i++)
    {
        p = new person;
        p->height = heights[i];
        p->weight = weights[i];
        everyone.push_back(p);
    }
    
    // sort the group according to height
    std::sort(everyone.begin(), everyone.end(), myfunction);
    for(i = 0; i < everyone.size(); i++) cout << everyone[i]->height << " "; 
    cout << endl; 
    for(i = 0; i < everyone.size(); i++) cout << everyone[i]->weight << " "; 
    cout << endl;
    
    cout << "LIS = " << lis(everyone) << endl; 
    

    std::vector<person*>::iterator iter = everyone.begin();
    for (; iter != everyone.end(); ++iter)
    {
        delete *iter;   // its *iter  is still a pointer
    }
    everyone.clear();
    // for(i = 0; i = everyone.size(); i++) delete everyone[i];
    
    return 0;
}
