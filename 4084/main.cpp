#include <iostream>
#include <cstdio>
using namespace std;
int num,maxl,x,y,last[510000],nxt[1010000],to[1010000],son[510000],n,k;
bool vis[510000];
void add(int x,int y){
    to[++num]=y;
    nxt[num]=last[x];
    last[x]=num;
}
void dfs(int x){
    int y;
    vis[x]=true;
    for (int i=last[x];i!=0;i=nxt[i])
    {
        y=to[i];
        if (vis[y]) continue;
        dfs(y);
        son[x]+=son[y];
    }
    maxl+=min(son[x],2*k-son[x]);//需要“流向”该点父亲的边的数量
}
int main() {
    scanf("%d%d",&n,&k);
    for (int i=0;i<2*k;++i)
    {
        scanf("%d",&x);
        son[x]=1;
    }
    for (int i=0;i<n-1;++i)
    {
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs(1);
    printf("%d",maxl);
    return 0;
}