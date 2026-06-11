const int mod = 1e9 +7;
struct Matrix{
  const static int N = 2;
  const static int M = 2;
  ll m[N][M];
  Matrix()  {for(int i=0; i<N; i++) for(int j=0; j<M; j++) m[i][j]=0;}
};

Matrix prod(const Matrix& a, const Matrix& b){
  int n = size(a.m);
  Matrix c;
  for (int i=0; i<n; i++)
    for (int k=0; k<n; k++)
      for (int j=0; j<n; j++)
        c.m[i][j] = (c.m[i][j] + a.m[i][k]*b.m[k][j]) %mod;
  return c;
}

Matrix mpw(Matrix a, ll y){
  int n = size(a.m);
  Matrix res;
  for(int i=0; i<n; i++) res.m[i][i] = 1;
  while (y) {
    if (y&1) res = prod(res, a);
    a = prod(a, a);
    y >>=1;
  }
  return res;
}
