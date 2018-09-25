#include <iostream>
#include <cstdio>
using namespace std;
int tr[2000000],ans[200001],n,m,q,x,y,step,width,p,tmp;//tr代表节点对应区间的LCP
char a[2][200001],ch;
int main() {
    scanf("%d%d",&n,&m);
    scanf("%s",a[0]);
    scanf("%s",a[1]);
    scanf("%d",&q);
    n=min(n,m);
    for (m=1;m<n;m<<=1);
    for (int i=m;i<m+n;++i)
        if (a[0][i-m]==a[1][i-m]) tr[i]=1;
    width=m>>1;
    step=1;
    for (int i=m-1;i>=1;--i)
    {
        if (i<width){step<<=1;width>>=1;}
        if (tr[i<<1]==step) tr[i]=tr[i<<1]+tr[(i<<1)+1];
        else tr[i]=tr[i<<1];
    }
    for (int i=0;i<q;++i)
    {
        scanf("%d%d",&x,&y);
        getchar();
        scanf("%c",&ch);
        a[x][y-1]=ch;
        if (y<=n){
            if (tr[m+y-1]!=(a[0][y-1]==a[1][y-1])) {
                tr[m+y-1]=(a[0][y-1]==a[1][y-1]);
                step = 1;
                p = m + y - 1;
                while ((p >>= 1) > 0) {
                    tmp=tr[p];
                    if (tr[p << 1] == step) tr[p] = tr[p << 1] + tr[(p << 1)|1];
                    else tr[p] = tr[p << 1];
                    if (tr[p]==tmp) break;//若值未更新则不再上溯
                    step <<= 1;
                }
            }
        }
        ans[i]=tr[1];
    }
    for (int i=0;i<q;++i) printf("%d\n",ans[i]);
    return 0;
}