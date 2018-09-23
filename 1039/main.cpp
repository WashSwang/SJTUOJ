#include <iostream>
using namespace std;
int n,root,postn,seq[30001],post[30001],ls[30001],rs[30001],x,y,z;
void dfs(int x)
{
    if (ls[x]!=-1) {
        seq[ls[x]]=2*seq[x];
        dfs(ls[x]);
    }
    if (rs[x]!=-1){
        seq[rs[x]]=2*seq[x]+1;
        dfs(rs[x]);
    }
    post[++postn]=x;
}
int main() {
    cin>>n;
    for (int i=0;i<n;++i){
        cin>>x>>y>>z;
        if (i==0) root=x;
        ls[x]=y;
        rs[x]=z;
    }
    seq[root]=1;
    dfs(root);
    for (int i=1;i<=n;++i)
        cout<<seq[i]<<" ";
    cout<<endl;
    for (int i=1;i<=n;++i)
        cout<<post[i]<<" ";
    return 0;
}