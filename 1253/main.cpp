#include <iostream>
#include <cstdio>
int x[501],y[501],m,n,p,q,k,curx,cury,sum;
int main() {
    scanf("%d%d%d",&m,&n,&k);
    for (int i=1;i<=m;++i)
        for (int j=1;j<=n;++j)
        {
            scanf("%d",&p);
            x[p]=i;
            y[p]=j;
        }
    for (q=500;q>=1;--q)
        if (x[q]>0)
        {
            if (k-2*x[q]-1>=0)
            {
                k-=x[q]+1;
                sum+=q;
                curx=x[q];
                cury=y[q];
            }
            else
            {
                printf("%d",0);
                return 0;
            }
            break;
        }
    for (--q;q>=1;--q)
    {
        if (x[q]>0)
        {
            if (k-abs(curx-x[q])-abs(cury-y[q])-x[q]-1>=0)
            {
                k-=abs(curx-x[q])+abs(cury-y[q])+1;
                sum+=q;
                curx=x[q];
                cury=y[q];
            }
            else
            {
                printf("%d",sum);
                return 0;
            }
        }
    }
    printf("%d",sum);
    return 0;
}