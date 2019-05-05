#include <vector>
#include <iostream>
#include <map>

using namespace std;

bool dfs(int j, vector<int>& color, map<int,vector<int>> &g)
{
  if (g.find(j) == g.end())
    return true;
  for(auto k : g[j])
  {
    if (color[j] !=-1 && color[j] == color[k] )
      return false;
    if (color[k] ==-1)
    {
      color[k] = 1- color[j];
      bool cur_flag = dfs(k, color, g);
      if (!cur_flag)
        return false;
    }
  }
  return true;
}

bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
  map<int, vector<int>> g;
  for (auto p: dislikes)
  {
    if (g.find(p[0]) == g.end())
      g[p[0]] = vector<int>();

    if (g.find(p[1]) == g.end())
      g[p[1]] = vector<int>();

    g[p[0]].push_back(p[1]);
    g[p[1]].push_back(p[0]);
  }
  // color
  vector<int> color (N+1, -1);
  for(int i=1;i<=N;i++)
  {
    if (color[i] != -1)
      continue;
    color[i] = 0;
    bool flag = dfs(i, color, g);
    if (!flag)
      return false;
  }
  return true;      
}

int main()
{
  vector<vector<int>> dislikes = {{1,2},{1,3},{2,4}};
  //vector<vector<int>> dislikes = {{1,2},{1,3},{2,3}};
  cout << possibleBipartition(3, dislikes);
  return 0;
}

