def exgcd(a, b):
    if b==0:
        return 1,0,a
    x,y,d=exgcd(b,a%b)
    return y,x-y*(a/b),d
a,b,c=map(int, raw_input().split() )
x,y,d=exgcd(a,b)
if c%d !=0 :
    print -1
else:
    x,y=-x*c/d,-y*c/d
    print x,y
    