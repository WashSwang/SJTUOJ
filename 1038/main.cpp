#include <iostream>
using namespace std;
int k[30000],t,f[30000];
int main() {
    cin>>t;
    f[1]=0;
    for (int i=0;i<t-1;++i) cin>>k[i];
    for (int i=2;i<=t;++i)
        f[i]=(f[i-1]+k[t-i])%i;
    cout<<f[t]+1;
}