import sys
n=input()
if n==2:
    print '-1'
else:
    ret=[6,10,15]
    ad=[30*(i+1) for i in xrange(0,n-3)]
    ret+=ad
    for v in ret:
        print v