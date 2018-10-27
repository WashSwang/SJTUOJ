#include <iostream>
#include <cstdio>
using namespace std;
const int mxn=1000000;
int n,m;
int f[mxn],v[mxn],ch[mxn][2],dis[mxn],root[mxn],opt,x,y;
int merge(int x,int y){
    if (x==0||y==0)
        return x+y;
    if (v[x]>v[y]||(v[x]==v[y]&&x>y))
        swap(x,y);
    ch[x][1]=merge(ch[x][1],y);
    f[ch[x][1]]=x;
    if (dis[ch[x][0]]<dis[ch[x][1]])
        swap(ch[x][1],ch[x][0]);
    dis[x]=dis[ch[x][1]]+1;
    return x;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&v[i]);
        root[i]=i;
    }
    v[0]=-1;
    for(int i=0;i<m;i++){
        scanf("%d",&opt);
        if (opt==0){
            scanf("%d%d",&x,&y);
            root[x+1]=merge(root[x+1],root[y+1]);
            if (!root[y+1]) root[y+1]=-1;
        }
        if (opt==1){
            scanf("%d",&x);
            printf("%d\n",v[root[x+1]]);
            if (v[root[x+1]]!=-1) {
                v[root[x + 1]] = -1;
                if (ch[root[x + 1]][0]||ch[root[x+1]][1])
                    root[x + 1] = merge(ch[root[x + 1]][0], ch[root[x + 1]][1]);
                else root[x+1]=0;
            }
        }
        if (opt==2){
            scanf("%d%d",&x,&y);
            n++;
            root[n]=n;
            v[n]=y;
            root[x+1]=merge(root[x+1],root[n]);
        }
    }
}