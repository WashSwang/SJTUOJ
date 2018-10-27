#include <iostream>
#include <cstdio>
using namespace std;
int a[300000],queue[300000],head,tail=-1,n,k;
int main() {
    scanf("%d%d",&k,&n);
    for (int i=0;i<n;++i) scanf("%d",&a[i]);
    for (int i=0;i<k-1;++i)
    {
        while (a[i]>=a[queue[tail]]&&tail>=0) tail--;
        queue[++tail]=i;
    }
    for (int i=k-1;i<n;++i){
        while (queue[head]<=i-k) head++;
        while (a[i]>=a[queue[tail]]&&tail>=head) tail--;
        queue[++tail]=i;
        printf("%d ",a[queue[head]]);
    }
    return 0;
}