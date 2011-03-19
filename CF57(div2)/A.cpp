#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char cs1[110],cs2[110];
int main()
{
    char ret[110];
    int top=0;
    scanf("%s%s",cs1,cs2);
    int len=strlen(cs1);
    for(int i=0;i<len;i++)
    {
        if(cs1[i]==cs2[i]) ret[i]='0';
        else ret[i]='1';
    }
    ret[len]=0;
    printf("%s\n",ret);
    return 0;
}
