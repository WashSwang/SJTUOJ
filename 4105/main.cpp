#include <iostream>
#include <algorithm>
using namespace std;
struct btype{
    int v;
    int ind;
} b[200001];
bool cmp(btype x,btype y){
    return x.v<y.v;
}
int a[200001],m,n,l,r,mid,ans[200001],minn;
int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;++i) scanf("%d",&a[i]);
    sort(a,a+n);
    for (int i=0;i<m;++i) {scanf("%d",&b[i].v);b[i].ind=i;}
    sort(b,b+m,cmp);
    l=0;
    for (int i=0;i<m;++i){
        r=n-1;
        while (l<=r){
            mid=(l+r)/2;
            if (a[mid]<b[i].v) l=mid+1;
            else if (a[mid]>b[i].v) r=mid-1;
            else {
                l=mid;
                break;
            }
        }
        minn=2000000001;
        if (l<n) minn=min(minn,abs(a[l]-b[i].v));
        if (l>=1) minn=min(minn,abs(a[l-1]-b[i].v));
        ans[b[i].ind]=minn;
    }
    for (int i=0;i<m;++i)
        printf("%d\n",ans[i]);
    return 0;
}