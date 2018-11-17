#include <iostream>
using namespace std;
int dp[301][30001],power[301],ti[301],n,m,nxt[1000],last[1000],to[1000],num,p,ans;
void add(int u,int v){
    ++num;
    nxt[num]=last[u];
    last[u]=num;
    to[num]=v;
}
void dfs(int x,int v){
    if (v<0) return;
    for (int i=last[x];i;i=nxt[i]){
        int t=to[i];
        for (int j=0;j<=v;++j) dp[t][j]=dp[x][j];
        dfs(t,v-ti[t]);
        for (int j=ti[t];j<=v;++j) dp[x][j]=max(dp[x][j],dp[t][j-ti[t]]+power[t]);
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i) {
        scanf("%d%d%d", &ti[i], &power[i], &p);
        add(p,i);
    }
    dfs(0,n);
    for (int i=0;i<=n;++i)
        if (ans<dp[0][i]) ans=dp[0][i];
    printf("%d",ans);
    return 0;
}