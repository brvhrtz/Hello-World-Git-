/*
 *  C9P2 sort strings anagrams
 *  Write a method to sort an array of strings 
 *  so that all the anagrams are next to each other. 
 */
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Compare two strings
// input 2 cpp strings 
// output true is first string should be first in order
bool str_comp(string a, string b)
{
    int i;
    vector<char> va, vb;
    
    cout << "start comparing" << endl; 
    if(a.size() < b.size()) 
      return true; 
    else if(a.size() > b.size()) 
      return false;
    else
    {
        for(i = 0; i < a.size(); i++)
        {
            va.push_back(a[i]);
            vb.push_back(b[i]);
        }
        std::sort(va.begin(), va.end());
        std::sort(vb.begin(), vb.end());
        for(i = 0; i < va.size(); i++) cout << va[i] << " "; 
        cout << endl; 
        for(i = 0; i < vb.size(); i++) cout << vb[i] << " "; 
        cout << endl; 
        
        for(i = 0; i < a.size(); i++)
        {
            if(va[i] > vb[i]) 
              return false;
            else if(va[i] < vb[i])
              return true;
        }
        return true; // these two are anagrams
    }
}

// anagram_sort
// input an vector of strings 
// output an sorted vector of strings

int main()
{ 
  vector<string> strvec = {"abc", "bcd", "cba", "def", "efg", "gfe", "fed", "edc", "dcb", "cba"};
  
//  string temp;
//  temp = new string(str[i]);

  for(int i = 0; i < strvec.size(); i++) cout << strvec[i] << " "; 
  cout << endl; 
  
  std::sort(strvec.begin(), strvec.end(), str_comp);
  for(int i = 0; i < strvec.size(); i++) cout << strvec[i] << " "; 
  cout << endl; 
  
  return 0;   
}

/*
 *Gotcha:
 * 1 Simple problem but very good for exercising string vector and usage of STL sorting algorithms
 * 2. can consider enhance this exercise by 
     - reading from a file and 
     - use a vector of string pointers
 */
