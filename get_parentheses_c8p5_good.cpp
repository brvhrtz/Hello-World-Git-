#include <iostream>
#include <vector>

using namespace std;

// print all valid combinations of n-pairs of parentheses
// input : n & 2d vec to record combinations
// output: void  

/*
 * Basic algorithms is to push adding new '(' or ')' and recursively test/expand it 
 * until a decison moment is reached, 
 * e.g. num of parentheses exceeds N, has more right parentheses
*/

void get_paren_combs(int n, int lp, int rp, vector<char> &cur, vector< vector<char> > &combs) 
{ 
  vector<char> temp = cur;
  
  if (temp.size() > n || lp < rp)
      return;
  else if (temp.size() == n && lp != rp) 
      return;
  else if (temp.size()==n && lp == rp)
  {
      combs.push_back(temp);
      return;
  }
  else
  {
      temp.push_back('(');
      get_paren_combs(n, lp+1, rp, temp, combs);
      temp.back() = (')');
      get_paren_combs(n, lp, rp+1, temp, combs);
  }
  return; 
}


int main()
{
  cout << "CC150-8.5 parentheses" << endl;
  
  vector< vector<char> > allcombs;
  vector<char> myvec;
  get_paren_combs(6, 0, 0, myvec, allcombs);
  int i,j;
  for(i = 0; i < allcombs.size(); i++)
  {
      for(j = 0; j < allcombs[i].size(); j++)
      {
          cout << allcombs[i][j] << "";
      }
      cout << endl; 
  }

  return 0;
}

