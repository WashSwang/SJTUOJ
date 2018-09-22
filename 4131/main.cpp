#include <cstdio>
#include <cmath>
using namespace std;
int a,b,k[510000],jump[510000],to[510000],n,m,p,q,ans[100001],s,l[510000];//jump代表跳出块需要的次数 to代表跳出块以后下一个块的坐标
inline void upgrade(int x)
{
    if (k[x]+x>=l[x]+b||k[x]+x>=n) {
        jump[x] = 1;
        to[x]=k[x]+x;
    }
    else{
        jump[x]=jump[k[x]+x]+1;
        to[x]=to[k[x]+x];
    }
}
int main() {
    scanf("%d",&n);
    b=int(sqrt(n));//块的大小
    for (int i=0;i<n;++i) {
        scanf("%d", &k[i]);
        if (p==b) {p=0; q+=b;}
        l[i]=q;
        p++;
    }
    for (int i=n-1;i>=0;--i)
        upgrade(i);
    scanf("%d",&m);
    for (int i=0;i<m;++i)
    {
        scanf("%d",&a);
        if (a==1)
        {
            scanf("%d",&p);
            for (int j=p;j<n;j=to[j])
                ans[s]+=jump[j];
            s++;
        }
        if (a==2)
        {
            scanf("%d%d",&p,&q);
            k[p]=q;
            for (int j=p;j>=l[p];j--)
                upgrade(j);
        }
    }
    for (int i=0;i<s;++i)
        printf("%d\n",ans[i]);
    return 0;
}