#include <iostream>
#include <vector>

using namespace std;



// print all valid combinations of n-pairs of parentheses
// input : n & 2d vec to record combinations
// output: void  

/* Basic Algorithm
 * for each of the combinations for n-1 parentheses, 
 * There are 3 variations ()*  (*) *()
 */
// unfortunately, this is not true e.g. for   (())(()) we have at least 5 combinations
//  ()(())(())    (())(())()  ((())(()))  (())()(())    (()()()())
// this method does not work
 
void get_paren_combs(int n, vector< vector<char> > &combs) 
{ 
  vector<char> temp;
  if(n == 1) 
  {
      temp.push_back('('); temp.push_back(')');
      combs.push_back(temp);
  }
  else if(n > 1)
  {
      int i;

      vector< vector<char> > combs2;
      get_paren_combs(n-1, combs2);
      for(i = 0; i < combs2.size(); i++)
      {
        // *()
        temp = combs2[i];
        temp.push_back('('); temp.push_back(')');
        combs.push_back(temp);
        // ()*
        temp.clear(); temp = {'(', ')'};
        temp.insert(temp.end(), combs2[i].begin(), combs2[i].end());
        combs.push_back(temp);
        // ( * )
        temp.clear(); temp = {'('};
        temp.insert(temp.end(), combs2[i].begin(), combs2[i].end());
        temp.push_back(')');
        combs.push_back(temp); 
        
      }
      
  }
}


int main()
{
  cout << "CC150-8.5 parentheses" << endl;
  
  vector< vector<char> > allcombs;
  get_paren_combs(2, allcombs);
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
