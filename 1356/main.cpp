#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int x,y,n,r,q,num=1,last[300000],to[300000],ne[300000],maxson[300000];
bool vis[300000];
void add(int u,int v){
    to[num]=v;
    ne[num]=last[u];
    last[u]=num;
    num++;
}
void find(int x){
    vis[x]=true;
    for (int i=last[x];i;i=ne[i])
        if (!vis[to[i]]){
            find(to[i]);
            maxson[x]=max(maxson[x],to[i]);
        }
}
int main() {
    memset(maxson,-1,sizeof(maxson));
    scanf("%d%d",&n,&r);
    for (int i=0;i<n-1;++i){
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    find(r);
    scanf("%d",&q);
    for (int i=0;i<q;++i)
    {
        scanf("%d",&x);
        printf("%d\n",maxson[x]);
    }
    return 0;
}