#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void qsort(int *s,int *t)
{
    if (s+1>=t) return;
    int i=0,j=int(t-s)-1,v;
    swap(s[0],s[rand()%j]);
    v=s[0];
    while (i<j)
    {
        while (i<j&&s[j]>=v) j--;
        if (i<j) s[i++]=s[j];
        while (i<j&&s[i]<=v) i++;
        if (i<j) s[j--]=s[i];
    }
    s[i]=v;
    qsort(s,s+i);
    qsort(s+i+1,t);
}

struct btype{
    int v;
    int ind;
} b[200001];
void qsort(btype *s,btype *t)
{
    if (s+1>=t) return;
    int i=0,j=int(t-s)-1;
    swap(s[0],s[rand()%j]);
    btype v=s[0];
    while (i<j)
    {
        while (i<j&&s[j].v>=v.v) j--;
        if (i<j) s[i++]=s[j];
        while (i<j&&s[i].v<=v.v) i++;
        if (i<j) s[j--]=s[i];
    }
    s[i]=v;
    qsort(s,s+i);
    qsort(s+i+1,t);
}
int a[200001],m,n,l,r,mid,ans[200001],minn;
int main() {
    srand(time(NULL));
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;++i) scanf("%d",&a[i]);
    qsort(a,a+n);
    for (int i=0;i<m;++i) {scanf("%d",&b[i].v);b[i].ind=i;}
    qsort(b,b+m);
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