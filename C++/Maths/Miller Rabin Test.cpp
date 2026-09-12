ll pw(ll x, ll y, ll m) {
  ll res=1; x%=m;
  while(y>0) {
    if(y&1) res=(ll)((__int128)res*x %m);
    x=(ll)((__int128)x*x %m);
    y>>=1;
  }
  return res;
}

bool cmpst(ll n, ll a, ll d, ll s) {
  ll x = pw(a,d,n);
  if (x==1 || x==n-1) return false;
  for (ll r=1; r<s; r++) {
    x = (ll)((__int128)x*x %n);
    if (x==n-1) return false;
  }
  return true;
}

bool mrtest(ll n) {
  if (n<2) return false;
  ll r = 0;
  ll d = n-1;
  while ((d&1)==0) {
    d>>=1; r+=1;
  }
  for (ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
    if (n % a == 0) return n == a;
    if (cmpst(n, a, d, r)) return false;
  }
  return true;
}
