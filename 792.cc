#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int numMatchingSubseq(string S, vector<string>& words)
{
  map<int,vector<int> > alpha;
  for(int i =0;i<S.size();i++)
    alpha[S[i]].push_back(i);

  int nums = 0;
  for(auto w:words)
  {
    int x = -1;
    bool found = true;
    for(auto c:w)
    {
      auto it = upper_bound(alpha[c].begin(), alpha[c].end(), x);
      if (it == alpha[c].end())
      {
        found = false;
        break;
      }
      x = *it;
    }
    if (found)
      nums ++;
  }
  return nums;
}

int main()
{
  string S = "abcde";
  vector<string> words = {"a","bb","acd","ace"};
  cout << numMatchingSubseq(S, words) << endl; 
  return 0;
}
