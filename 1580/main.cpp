#include <iostream>
#include <cstdio>
using namespace std;
int n,st[1100000],a[1000001],top,l,r,m;
int main() {
    scanf("%d",&n);
    for (int i=0;i<n;++i)
        scanf("%d",&a[i]);
    st[0]=-1;
    for (int i=0;i<n;++i){
        if (a[i]>st[top]) st[++top]=a[i];
        else{
            l=1;
            r=top;
            while (l<=r){
                m=(l+r)/2;
                if (st[m]<=a[i]) l=m+1;
                else r=m-1;
            }
            if (st[l-1]!=a[i]) st[l]=a[i];
        }
    }
    printf("%d",top);
    return 0;
}