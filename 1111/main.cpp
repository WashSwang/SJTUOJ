#include <iostream>
#include <cstring>
using namespace std;
char pre[100],in[100],ans[2000];
int maxn;
void dfs(int ps,int pe,int is,int it,int p)
{
    int root,leftlen,rightlen;
    for (root=is;root<it;++root){
        if (in[root]==pre[ps])
            break;
    }
    ans[p]=in[root];
    if (p>maxn) maxn=p;
    leftlen=root-is;
    if (leftlen>0) dfs(ps+1,ps+leftlen,is,root,p*2);
    rightlen=it-root-1;
    if (rightlen>0) dfs(ps+leftlen+1,pe,root+1,it,p*2+1);
}
int main() {
    cin>>pre;
    cin>>in;
    dfs(0,strlen(pre),0,strlen(in),1);
    for (int i=1;i<=maxn;++i)
        if (ans[i]) cout<<ans[i]<<" ";
        else cout<<"NULL ";
    return 0;
}