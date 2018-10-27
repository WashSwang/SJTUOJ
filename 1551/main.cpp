#include <iostream>
#include <cstdio>
using namespace std;
int vnow=0x3f3f3f3f,n,ans,p;
int main() {
    int *v;
    scanf("%d",&n);
    v=new int[n];
    for (int i=0;i<n;++i)
        scanf("%d %d",&p,&v[i]);
    for (int i=n-1;i>=0;--i)
        if (v[i]<=vnow){
            ans++;
            vnow=v[i];
        }
    printf("%d",ans);
    return 0;
}