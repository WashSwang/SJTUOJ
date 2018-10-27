#include <iostream>
using namespace std;
char map[1500][1500];
int m,n,d,ans,h[1500],l[1500],r[1500],curl,curr;
int main(){
    ios::sync_with_stdio(false);
    cin>>m>>n;
    for (int i=0;i<m;++i)
        for (int j=0;j<n;++j)
            cin>>map[i][j];
    for (int i=0;i<n;++i) r[i]=n-1;
    for (int i=0;i<m;++i){
        for (int j=0;j<n;++j)
            if (map[i][j]=='-') h[j]++;
            else h[j]=0;
        curl=0;
        for (int j=0;j<n;++j)
            if (map[i][j]=='-') l[j]=max(curl,l[j]);
            else {l[j]=0; curl=j+1;}
        curr=n-1;
        for (int j=n-1;j>=0;--j) {
            if (map[i][j] == '-') r[j] = min(curr, r[j]);
            else {r[j] = n-1; curr=j-1;}
            d=min((r[j]-l[j]+1)/2,h[j]);
            if (2*d*d>ans) ans=2*d*d;
        }
    }
    cout<<ans;
}