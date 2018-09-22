#include <cstdio>
using namespace std;
int p[200000],fa[200000],num[200000],n,m,x,y;
int root(int x)//并查集 路径压缩
{
    if (fa[x]==0) return x;
    else return fa[x]=root(fa[x]);
}
void unionset(int x,int y){
    int s=root(x),t=root(y);
    if (s!=t)
    {
        fa[s]=t;
        num[t]+=num[s];//两个集合合并 数量相加
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i){num[i]=1;}
    for (int i=0;i<m;++i)
    {
        scanf("%d%d",&x,&y);
        unionset(x,y);
        p[x]++;
        p[y]++;
    }
    for (int i=1;i<=n;++i)
    {
        if (p[i]!=num[root(i)]-1)
            {
                printf("NO");
                return 0;
            }
    }
    printf("YES");
    return 0;
}