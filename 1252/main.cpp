#include <iostream>
#include <cstdio>
#include <algorithm>
long long s[1001];
int n,m,x,y,ans;
int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;++i)
    {
        scanf("%d%d",&x,&y);
        s[x]+=y;
    }
    for (int i=0;i<1000;++i)
    {
        if (n>s[i]){
            n-=s[i];
            ans+=s[i]*i;
        }
        else
        {
            ans+=n*i;
            break;
        }
    }
    printf("%d",ans);
    return 0;
}