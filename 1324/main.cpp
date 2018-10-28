#include <iostream>
using namespace std;
struct team{
    int p,m,t; //p:power  m:money  t:team number
};
team s[110000],tmp[110000],cold[110000],win[110000],lose[110000];
int a,b,r,n,coldn,winn,losen,ans[110000];
void merge(team *r, team *s, team *t, int l1, int l2){
    int i=0,j=0,index=0;
    while (i<l1&&j<l2){
        if (s[i].m<t[j].m) r[index++]=s[i++];
        else if (s[i].m>t[j].m) r[index++]=t[j++];
        else if (s[i].t<t[j].t) r[index++]=s[i++];
        else r[index++]=t[j++];
    }
    if (i<l1) while (i<l1) r[index++]=s[i++];
    if (j<l2) while (j<l2) r[index++]=t[j++];
}
int main() {
    scanf("%d%d",&n,&r);
    for (int i=0;i<2*n;++i){
        scanf("%d",&s[i].p);
        s[i].t=i;
    }
    for (int i=0;i<r;++i){
        coldn=winn=losen=0;
        for (int j=0;j<n;++j){
            a=j<<1;
            b=a|1;
            if (s[a].p%s[b].p==0||(s[b].p>s[a].p&&s[b].p%s[a].p!=0)){
                if (s[b].t>s[a].t){
                    s[b].m+=1;
                    win[winn++]=s[b];
                    lose[losen++]=s[a];
                }
                else{
                    s[b].m+=2;
                    cold[coldn++]=s[b];
                    lose[losen++]=s[a];
                }
            }
            else{
                if (s[b].t<s[a].t){
                    s[a].m+=1;
                    win[winn++]=s[a];
                    lose[losen++]=s[b];
                }
                else{
                    s[a].m+=2;
                    cold[coldn++]=s[a];
                    lose[losen++]=s[b];
                }
            }
        }
        merge(tmp,win,cold,winn,coldn);
        merge(s,tmp,lose,winn+coldn,losen);
    }
    for (int i=0;i<2*n;++i)
        ans[s[i].t]=s[i].m;
    for (int i=0;i<2*n;++i)
        printf("%d ",ans[i]);
    return 0;
}