#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define ALPHABET_SIZE 26

class TrieNode
{
  public:
    char c ;
    TrieNode* childs[ALPHABET_SIZE];
    bool is_end ;
    TrieNode(){
      c = ' ';
      memset(childs, 0, sizeof(TrieNode*) * ALPHABET_SIZE);
      is_end = false;
    }
};

class Trie
{
  public:
    TrieNode* root = 0;
    Trie(){
      root = new TrieNode();
    }

    void insert(string &s)
    {
      TrieNode * t = root;
      for(auto c :s)
      {
        if (t->childs[c-'a']==0)
        {
           t->childs[c-'a'] = new TrieNode();
           t->childs[c-'a']->c = c;
        }
        t = t->childs[c-'a'];
      }
      t->is_end = true;
    }

    void dfs(TrieNode * t, int & cnt)
    {
      if (t==0)
        return;
      for (int i =0;i< ALPHABET_SIZE;i++)
      {
         if (t->childs[i] !=0)
         {
            if (t == root)
              cnt = cnt + 1;
            cnt = cnt + 1;
            dfs(t->childs[i], cnt);
         }
      }
    }

    int get_branch_total_len()
    {
      int cnt = 0;
      dfs(this->root, cnt);
      return cnt;
    }
};

int main()
{
  vector<string> v = {"emit", "em", "lleb"};
  Trie t;
  for (auto c : v)
    t.insert(c);

  cout << t.get_branch_total_len() << endl;
  return 0;

}
