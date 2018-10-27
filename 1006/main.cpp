#include <cstdio>
#include <iostream>
using namespace std;
int last,cur,now=-500,maxn,n;
int main() {
    scanf("%d%d",&n,&last);
    for (int i=1;i<n;++i)
    {
        scanf("%d",&cur);
        now=max(cur+now,cur+last);
        last=cur;
        if (now>maxn) maxn=now;
    }
    if (maxn) cout<<maxn<<endl;
    else cout<<"Game Over"<<endl;
    return 0;
}