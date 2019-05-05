#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAXN 256

int ranks[MAXN];
int groups[MAXN];

void init()
{
  for(int i=0;i<MAXN;i++)
  {
    ranks[i] = 0;
    groups[i] = i;
  }
}

int get_group(int x)
{
  if(x == groups[x])
    return x;
  groups[x] = get_group(groups[x]);
  return groups[x];
  //int t = x;
  //while (x != groups[x])
  //{
  //  x = groups[x];
  //}
  //groups[t] = x;
  //return x;
}

int union_group(int x1, int x2)
{
  int gx1 = get_group(x1);
  int gx2 = get_group(x2);
  if (gx1 == gx2)
    return gx1;
  int rank1 = ranks[x1];
  int rank2 = ranks[x2];
  if (rank1 < rank2)
  {
    groups[gx1] = gx2; 
    return gx2;
  }
  else if (rank1 > rank2)
  {
    groups[gx2] = gx1;
    return gx1;
  }
  else
  {
    groups[gx2] = gx1;
    ranks[x1] ++;
    return gx1;
  }

}

void print_vec()
{
  for(int i=0;i<5;i++)
    cout << groups[i] << "\t";
  cout << endl;
}

bool equationsPossible(vector<string>& equations) {
  init();
  for(auto s :equations)
  {
    if (s[1] == '=')
    {
      int g = union_group(s[0]-'a', s[3]-'a');
      cout << s[0] << "\t" << s[3] << "\t" << g << "\n";
      print_vec();
    }
  }
  for(auto s:equations)
  {
    if (s[1]=='!')
    {
      int g0 = get_group(s[0]-'a');
      int g1 = get_group(s[3]-'a');
      cout <<"query:" << s[0] << "\t" << g0 << "\t" << s[3] << "\t" << g1 << endl;
      if (g0 == g1)
        return false;
    }
  }
  return true;
}

int main()
{
  //vector<string> v = {"a==b","b!=c","c==a"};
  vector<string> v = {"a==b","e==c","b==c","a!=e"};
  cout << equationsPossible(v);
  return 0;
}
