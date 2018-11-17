#include <iostream>
using namespace std;
int a[10000001],n,m,q,x1,x2,y1,y2;
long long map[10000001],ans;
int main() {
    scanf("%d%d%d",&n,&m,&q);
    for (int i=0;i<n*m;++i){
        scanf("%d",&a[i]);
        if (i>=m) map[i]+=map[i-m];
        if (i%m!=0) map[i]+=map[i-1];
        if (i>=m&&i%m!=0) map[i]-=map[i-m-1];
        map[i]+=a[i];
    }
    for (int i=0;i<q;++i){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x1-=1;
        y1-=1;
        x2-=1;
        y2-=1;
        ans=map[x2*m+y2];
        if (y1>0) ans-=map[x2*m+y1-1];
        if (x1>0) ans-=map[(x1-1)*m+y2];
        if (x1>0&&y1>0) ans+=map[(x1-1)*m+y1-1];
        printf("%lld\n",ans);
    }
    return 0;
}