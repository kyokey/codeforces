s=raw_input()
n=len([c for c in s if c.isupper()])
print s.upper() if 2*n>len(s) else s.lower()