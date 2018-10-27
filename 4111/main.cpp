#include <iostream>
#include <cstdio>
using namespace std;
char map[1005][1005];
int minx[1005][1005],qx[1000011],qy[1000011];
int sx,sy,head,tail,m,n,now,xnow,ynow,ex,ey;
void update(int value,int x,int y)
{
    if (map[x][y]=='#') return;
    if ((map[x][y]=='$'||map[x][y]=='.')&&(minx[x][y]==0)) {
        minx[x][y] = value;
        qx[tail] = x;
        qy[tail] = y;
        tail++;
    }
}
int main() {
    scanf("%d%d",&m,&n);
    for (int i=0;i<m;++i)
    {
        scanf("%s",map[i]);
        for (int j=0;j<n;++j) {
            if (map[i][j] == '@') {
                sx = i;
                sy = j;
            }
            if (map[i][j] == '$'){
                ex = i;
                ey = j;
            }
        }
    }
    qx[0]=sx;
    qy[0]=sy;
    head=0;
    tail=1;
    while (head<tail)
    {
        now=minx[qx[head]][qy[head]];
        xnow=qx[head];
        ynow=qy[head];
        if (xnow>=1) update(now+1,xnow-1,ynow);
        if (ynow>=1) update(now+1,xnow,ynow-1);
        if (xnow<m-1) update(now+1,xnow+1,ynow);
        if (ynow<n-1) update(now+1,xnow,ynow+1);
        head++;
        if (minx[ex][ey]!=0) break;

    }
    if (!minx[ex][ey]) printf("%d",-1);
    else printf("%d",minx[ex][ey]);
    return 0;
}