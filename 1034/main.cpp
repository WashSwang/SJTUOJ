#include <iostream>
#include <cstdio>
using namespace std;
int a[300000],rp[300000],n,k,head,tail,minrp=0x3f3f3f3f;
int main() {
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;++i)
        scanf("%d",&rp[i]);
    for (int i=0;i<k;++i){
        while (head>0&&rp[a[head-1]]<=rp[i]) head--;
        a[head++]=i;
    }
    if (rp[a[tail]]<minrp) minrp=rp[a[tail]];
    for (int i=k;i<n;++i){
        while (head>tail&&a[tail]<=i-k) tail++;
        while (head>tail&&rp[a[head-1]]<=rp[i]) head--;
        a[head++]=i;
        if (rp[a[tail]]<minrp) minrp=rp[a[tail]];
    }
    for (int i=0;i<k-1;++i){
        while (head>tail&&(a[tail]>i&&a[tail]<=i-k+n)) tail++;
        while (head>tail&&rp[a[head-1]]<=rp[i]) head--;
        a[head++]=i;
        if (rp[a[tail]]<minrp) minrp=rp[a[tail]];
    }
    printf("%d",minrp);
    return 0;
}