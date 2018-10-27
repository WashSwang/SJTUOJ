#include <iostream>
using namespace std;
int map[302][302],dis[302][302][7],minx,m,n,sx,sy;
void dfs(int x,int y,int e,int t)
{
    if (t==0) return;
    if (e>minx) return;
    if (map[x][y]==3&&t>0) {
        minx=min(e,minx);
        return;
    }
    if (map[x][y]==4) t=6;
    if (dis[x][y][t]!=0&&e>=dis[x][y][t]) return;
    dis[x][y][t]=e;
    if (map[x-1][y]) dfs(x-1,y,e+1,t-1);
    if (map[x+1][y]) dfs(x+1,y,e+1,t-1);
    if (map[x][y-1]) dfs(x,y-1,e+1,t-1);
    if (map[x][y+1]) dfs(x,y+1,e+1,t-1);
}
int main() {
    cin>>m>>n;
    for (int i=1;i<=m;++i)
        for (int j=1;j<=n;++j) {
            cin >> map[i][j];
            if (map[i][j]==2){
                sx=i;
                sy=j;
            }
        }
    minx=10000000;
    dfs(sx,sy,0,6);
    if (minx<m*n) cout<<minx;
    else cout<<-1;
    return 0;
}