#include <iostream>
#include <cstdio>
using namespace std;
int total,fa[300000],son[300000],n,x,y;
char c;
bool die[300000];
int main() {
    fa[1]=0;
    die[0]=true;
    total=1;
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        c=0;
       while (c!='B'&&c!='D') c=getchar();
       if (c=='B'){
           scanf("%d%d",&x,&y);
           fa[y]=x;
           son[x]++;
       }
       if (c=='D'){
           scanf("%d",&x);
           die[x]=true;
           if (die[fa[x]])
               total+=son[x]-1;
           else {
               son[fa[x]]-=1;
               total += son[x];
           }
           son[x]=0;
           printf("%d\n",total);
       }
    }
    return 0;
}