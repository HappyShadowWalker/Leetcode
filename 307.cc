#include <iostream>
#include <vector>
using namespace std;

class SegmentTree{
  private:
    vector<int> tree;
    vector<int> data;
  public:
    SegmentTree(vector<int> & data)
    {
      this->data = vector<int>(data);
      tree = vector<int>(data.size()*4);
      this->build(1, 0, data.size()-1);
    }

    int build(int j, int l, int r)
    {
      if(l == r)
      {
        this->tree[j] = this->data[l]; 
        return this->tree[j] ;
      }
      int mid = (l+r)/2;
      int left_val = build(j*2, l, mid);
      int right_val = build(j*2+1, mid+1, r);
      this->tree[j] = left_val + right_val;//定义操作
      return this->tree[j];
    }

    int query_imp(int k,int kl, int kr, int i, int j)
    {
      if (i > kr || j< kl)
        return 0;
      if (kl >=i && kr <=j)
        return this->tree[k];
      int mid = (kl + kr) /2;
      int l_val = query_imp(k*2, kl, mid, i, j);
      int r_val = query_imp(k*2+1, mid+1, kr, i, j);
      return l_val + r_val;
      
    }

    int query(int i, int j)
    {
      return query_imp(1, 0, this->data.size()-1, i, j);
    }

    void update_imp(int k, int kl, int kr, int j, int delta)
    {
      if (kl == kr)
      {
        this->tree[k] += delta;
        this->data[j] += delta;
        return ;
      }
      int mid = (kl + kr) /2;
      if (kl <= j && j <= mid)
      {
        update_imp(k*2, kl, mid, j, delta);
      }
      else
      {
        update_imp(k*2+1, mid+1, kr, j, delta);
      }
      this->tree[k] = this->tree[k*2] + this->tree[k*2+1];
    }

    void update(int i, int val)
    {
      int delta = val - this->data[i];
      // for(auto v:tree)
      //   cout << v << "\t";
      // cout << endl;
      update_imp(1,0,this->data.size()-1,i, delta);
      // for(auto v:tree)
      //   cout << v << "\t";
      // cout << endl;
    }
};

int main()
{
  vector<int> data = {-1};
  auto sg = SegmentTree(data);
  cout << sg.query(0,0)<< endl;;
  sg.update(0,1);
  cout << sg.query(0,0) <<endl;
  return 0;
}
