#include <cstdio>
#include <cstring>
using namespace std;
int ne[400010],to[400010],last[400010],num,k[400010],tail,head,ans;
int t,m,n,u,v;
void add(int u,int v)
{
    ne[++num]=last[u];
    to[num]=v;
    last[u]=num;
}
int dfs(int x)
{
    for (int i=last[x];i!=0;i=ne[i])
    {
        if (!k[to[i]])
        {
            k[to[i]]=-k[x];
            if (!dfs(to[i])) return 0;
        }
        else
            if (k[to[i]]+k[x]!=0)
                return 0;
    }
    return 1;
}
int main() {
    scanf("%d",&t);
    for (int i=0;i<t;++i) {
        scanf("%d%d", &n, &m);
        num=0;
        memset(last, 0, sizeof(last));
        memset(k, 0, sizeof(k));
        for (int j = 0; j < m; ++j) {
            scanf("%d%d", &u, &v);
            add(u,v);
            add(v,u);
        }
        ans=1;
        for (int j=1;j<=n;++j)
            if (k[j]==0){
                k[j]=1;
                if (!dfs(j))
                {
                    ans=-1;
                    break;
                }
            }
        printf("%d\n",ans);
    }
    return 0;
}