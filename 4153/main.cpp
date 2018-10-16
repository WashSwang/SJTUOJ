#include <iostream>
#include <algorithm>
using namespace std;
int l,r,m,n,k,a[200000],mid,ans;
bool test(int x){
    int now=a[0],len=1;
    if (k==1){
        for (int i=1;i<n;++i)
            if (a[i]-now>=x) {
                now=a[i];
                len++;
                if (len>=m) return true;
            }
        return false;
    }
    else{
        int p[200000],q[200000];
        p[0]=1;
        for (int i=1;i<n;++i) {
            if (a[i] - now >= x) {
                now = a[i];
                len++;
                p[i] = len;
            } else p[i] = p[i - 1];
        }
        if (p[n-1]>=m) return true;
        now=a[n-1];
        q[n-1]=1;
        len=1;
        for (int i=n-2;i>=0;--i){
            if (now-a[i]>=x) {
                now=a[i];
                len++;
                q[i]=len;
            }
            else q[i]=q[i+1];
            if (p[i]+q[i+1]>=m) return true;
        }
        if (q[0]>=m) return true;
        return false;
    }
}
int main() {
    cin>>n>>m>>k;
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    l=0;
    r=2000000000;
    while (l<=r)
    {
        mid=(r-l)/2+l;
        if (test(mid)){
            if (mid>ans) ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}