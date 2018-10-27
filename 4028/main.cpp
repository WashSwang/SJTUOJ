#include <iostream>
#include <cstdio>
using namespace std;
int rmargin,lmargin,dmargin,m,n,p,q,t,x,sx,sy,patx[1000001],paty[1000001],map[1001][1001],num,pnum;
bool flag;
int main() {
    scanf("%d",&t);
    for (int i=0;i<t;++i){
        flag=true;
        num=0;
        lmargin=0;
        rmargin=0;
        dmargin=0;
        pnum=0;
        scanf("%d%d%d%d",&m,&n,&p,&q);
        for (int j=0;j<m;++j)
            for (int k=0;k<n;++k) {
                scanf("%d", &map[j][k]);
                if (map[j][k]) pnum++;
            }
        for (int j=0;j<p;++j)
            for (int k=0;k<q;++k)
            {
               scanf("%d",&x);
               if (x){
                   if (num==0) {
                       sx=j;
                       sy=k;
                       num++;
                   }
                   else{
                       patx[num]=j-sx;
                       paty[num]=k-sy;
                       if (paty[num]<0)
                           lmargin=max(lmargin,paty[num]);
                       rmargin=max(rmargin,paty[num]);
                       dmargin=max(dmargin,patx[num]);
                       num++;
                   }
               }
            }
        for (int j=0;j<m-dmargin;++j){
            for (int k=lmargin;k<n-rmargin;++k)
                if (map[j][k]){
                    map[j][k]=0;
                    for (int l=1;l<num;++l)
                        if (!map[j+patx[l]][k+paty[l]]) {
                            flag = false;
                            break;
                        }
                        else
                            map[j+patx[l]][k+paty[l]]=0;
                    if (!flag) break;
                    pnum-=num;
                    if (!pnum) break;
                }
            if (!flag) break;
            if (!pnum) break;
        }
        if (!flag) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}