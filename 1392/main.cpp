#include <iostream>
using namespace std;
double sum;
long long l[10001];
int num,n,nxt[10001],last[10001],to[10001],root,f,v;
void add(int x,int y,int v){
    num++;
    nxt[num]=last[x];
    last[x]=num;
    to[num]=y;
    l[num]=v;
}
int dfs(int x){
    int son=1,tmp;
    for (int i=last[x];i!=0;i=nxt[i]){
        tmp=dfs(to[i]);
        son+=tmp;
        sum+=(n-tmp)*tmp*l[i];
    }
    return son;
}
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d%d",&f,&v);
        if (f==0) root=i;
        else add(f,i,v);
    }
    dfs(root);
    printf("%.2f",sum/(n*(n-1)/2));
    return 0;
}