#include <iostream>
using namespace std;
int sum,n,m,a[600000],l,r,mid,ans=500000;
bool test(int x){
    sum=0;
    for (int i=0;i<n;++i)
        sum+=(a[i]-1)/x+1;
    return sum<=m;
}
int main() {
    cin>>n>>m;
    for (int i=0;i<n;++i) cin>>a[i];
    l=0;
    r=500000;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (test(mid)){
            if (mid<ans) ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans;
    return 0;
}