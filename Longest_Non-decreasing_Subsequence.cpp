/*
 *  DP: longest non-decreasing sub-sequence
 */
 
// I found that I was trapped by previous memeories as well
// Now I can get to know that how can I stuck with working with old problem solutions. 
// If there is change and you have not reached the level of understanding the variations and clear understand the minor differences among similar problems, you gonna waste a lot of time trying to walk the distance in the wrong shoes/direction. 


#include <iostream>
#include <vector>

using namespace std;

// Longest increasing (non-decreasing) subsequence
// input: a sequence, 
// length of LIS for the input sequence
int lis(vector<char> seq, vector<int> &lisAt)
{
    int i, j;
    int max = 0;
    
    for(i = 0; i < seq.size(); i++)
    { // walks through all elements 
        for(j = 0; j < i; j++)
        { // walks through previous elements
            if(seq[j] < seq[i] && lisAt[j] > max) max = lisAt[j];
        }
        lisAt[i] = max + 1; 
    }
    max = 0;
    for(i = 0; i < lisAt.size(); i++)
    {
        if(lisAt[i] > max) max = lisAt[i];
    }
    return max; 
}

int main()
{
    vector<char> seq = {'6', '5', '4', '3', '2','1'};
    vector<int>  lisAt;
    
    for(int i = 0; i < seq.size(); i++) lisAt.push_back(1);
    
    cout << "LIS = " << lis(seq, lisAt) << endl; 
    
    return 0;
}
