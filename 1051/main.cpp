#include <iostream>
using namespace std;
int ans,n,x,m,nex[20000],v[20000],last;
int main() {
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>v[i];
        nex[i-1]=i;
    }
    cin>>m;
    for (int i=0;i<m;++i)
    {
        cin>>x;
        last=0;
        for (int j=nex[0];j;j=nex[j]){
            ans++;
            if (v[j]==x){
                nex[last]=nex[j];
                nex[j]=nex[0];
                nex[0]=j;
                break;
            }
            last=j;
        }
    }
    cout<<ans;
    return 0;
}