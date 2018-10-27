#include <iostream>
using namespace std;
int x,y,v,n,m,dis[101][101];
int main() {
    cin>>n;
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            dis[i][j]=0x3f3f3f3f;
    for (int i=0;i<n-1;++i){
        cin>>x>>y>>v;
        dis[x-1][y-1]=v;
        dis[y-1][x-1]=v;
        dis[i][i]=0;
    }
    for (int k=0;k<n;++k)
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                if (dis[i][k]+dis[k][j]<dis[i][j]) dis[i][j]=dis[i][k]+dis[k][j];
    cin>>m;
    for (int i=0;i<m;++i){
        cin>>x>>y;
        cout<<dis[x-1][y-1]<<endl;
    }
    return 0;
}