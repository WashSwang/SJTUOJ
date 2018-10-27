#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int x,y,n,num=1,ans,ansset[300000],last[300000],to[300000],ne[300000],son[300000];
bool vis[300000];
void add(int u,int v){
    to[num]=v;
    ne[num]=last[u];
    last[u]=num;
    num++;
}
void find(int x){
    bool fea=true;
    vis[x]=true;
    for (int i=last[x];i;i=ne[i])
        if (!vis[to[i]]){
            find(to[i]);
            if (son[to[i]]>n/2) fea=false;
            son[x]+=son[to[i]];
        }
    if (n-son[x]>n/2) fea=false;
    if (fea) ansset[ans++]=x;
}
int main() {
    scanf("%d",&n);
    for (int i=0;i<n-1;++i){
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    for (int i=1;i<=n;++i) son[i]=1;
    find(1);
    sort(ansset,ansset+ans);
    for (int i=0;i<ans;++i)
        printf("%d\n",ansset[i]);
    return 0;
}