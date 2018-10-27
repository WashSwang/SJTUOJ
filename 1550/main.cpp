#include <iostream>
using namespace std;
int n,x,ans,cur,h[2000],num,lmax[2000],rmax[2000];
char c;
int main() {
    cin>>n;
    while (cin>>c){
        if (c=='[') continue;
        if (c==']') {h[num++]=cur; break;}
        if (c==',') {h[num++]=cur; cur=0;}
        else cur=cur*10+c-48;
    }
    for (int i=1;i<n;++i) lmax[i]=max(lmax[i-1],h[i-1]);
    for (int i=n-2;i>=0;--i) rmax[i]=max(rmax[i+1],h[i+1]);
    for (int i=0;i<n;++i) ans+=max(min(rmax[i],lmax[i]),h[i])-h[i];
    cout<<ans;
    return 0;
}