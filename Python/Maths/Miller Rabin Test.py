def pw(x,y,m):
  res=1; x%=m
  while(y>0):
    if(y&1): res=res*x %m
    x=x*x %m
    y>>=1
  return res

def cmpst(n, a, d, s):
  x = pw(a,d,n)
  if (x==1 or x==n-1): return False
  for r in range(1,s):
    x = x*x %n
    if (x==n-1): return False
  return True

def mrtest(n):
  if (n<2): return False
  r = 0
  d = n-1
  while ((d&1)==0):
    d>>=1; r+=1
  for a in [2, 325, 9375, 28178, 450775, 9780504, 1795265022]:
    if (n%a==0): return n==a
    if (cmpst(n, a, d, r)): return False
  return True
