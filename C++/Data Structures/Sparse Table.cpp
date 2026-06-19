template <typename Node>
class Sparse{
public:
  int n, LOG;
  vector<vector<Node>> t;
  vector<int> lg;
 
  Sparse(vector<int> &a){
    int sz = a.size();
    this->n = sz;
    this->LOG = log2(n) +1;
    t = vector<vector<Node>>(LOG, vector<Node>(n));
    for (int i=0; i<n; i++) t[0][i] = a[i];
    lg = vector<int>(n+1, 0);
    build();
  }
 
  void build() {
    for (int i=2; i<=n; i++) lg[i] = lg[i/2] +1;
    for (int j=1; j<LOG; j++){
      int len = (1<<j);
      for (int i=0; i+len<=n; i++)
        t[j][i].merge(t[j-1][i], t[j-1][i +(1<<(j-1))]);
    }
  }
 
  Node query(int l, int r) {
    int x = lg[r-l+1];
    Node ans = Node();
    ans.merge(t[x][l], t[x][r -(1<<x) +1]);
    return ans;
  }
};
 
struct Node{
  int mx = 0;
  int mn = 1e9;
  Node() {}
  Node(int x) : mx(x), mn(x) {}
  void merge(Node& l, Node& r){
    this->mx = max(l.mx, r.mx);
    this->mn = min(l.mn, r.mn);
  }
};
