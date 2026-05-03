struct BIT{
  int n;
  vector<ll> t;
  BIT(int n){
    this->n = n;
    t.assign(n+1, 0);
  }

  ll query(int i) {
    ll res = 0;
    for (; i>0; i-=(i & -i))
      res += t[i];
    return res;
  }

  void update(int i, ll x=1){
    for (; i<=n; i +=(i&-i))
      t[i] += x;
  }
  // Finds the smallest index where the prefix sum is >= w
  int lower_bound(ll w){
    int x = 0;
    int k = 1;
    while (k*2 <= n)
      k *=2;
    for (; k > 0; k >>= 1)
      if (x+k <= n && t[x+k] < w){
        w -= t[x+k];
        x += k;
      }
    return x+1;
  }
};
