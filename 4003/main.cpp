#include <iostream>
using namespace std;
int n,k,one,e,t,m,ans;
int main() {
    cin>>n>>k;
    m=n;
    if (n<k) {cout<<k-n; return 0;}
    for (;m>0;m>>=1)
        if (m&1) one++;
    if (k>=one) {cout<<0; return 0;}
    for (e=1;t<=one-k;n>>=1,e<<=1){
        if (n&1) t+=1;
        else ans+=e;
    }
    cout<<ans+1;
    return 0;
}