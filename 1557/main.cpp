#include <iostream>
#include <cstdio>
void qsort(int *s,int *t,int *p,int *q){
    if (t-s<=1) return;
    int i=0,j=int(t-s)-1,x=s[0],y=p[0];
    while (i<j){
        while (i<j&&s[j]>=x) j--;
        if (i<j) {s[i]=s[j]; p[i++]=p[j];}
        while (i<j&&s[i]<=x) i++;
        if (i<j) {s[j]=s[i]; p[j--]=p[i];}
    }
    s[j]=x;
    p[j]=y;
    qsort(s,s+j,p,p+j);
    qsort(s+j+1,t,p+j+1,q);
}
int ans,p,x[100000],n,d,head,tail,h[100000],a[100000],lmax[100000],rmax[100000],bx[100000];
int main() {
    scanf("%d%d",&n,&d);
    for (int i=0;i<n;++i) scanf("%d%d",&x[i],&h[i]);
    qsort(x,x+n,h,h+n);
    head=0;
    tail=0;
    for (;x[p]<=d&&p<n;++p){
        while (head>0&&h[a[head-1]]<=h[p]) head--;
        a[head++]=p;
        lmax[p]=h[a[tail]];
    }
    for (;p<n;++p){
        while (tail<head&&x[a[tail]]+d<x[p]) tail++;
        while (head>tail&&h[a[head-1]]<=h[p]) head--;
        a[head++]=p;
        lmax[p]=h[a[tail]];
    }
    head=0;
    tail=0;
    for (p=n-1;x[p]>=x[n-1]-d;--p){
        while (head>0&&h[a[head-1]]<=h[p]) head--;
        a[head++]=p;
        rmax[p]=h[a[tail]];
    }
    for (;p>=0;--p){
        while (tail<head&&x[a[tail]]-d>x[p]) tail++;
        while (head>tail&&h[a[head-1]]<=h[p]) head--;
        a[head++]=p;
        rmax[p]=h[a[tail]];
    }
    for (int i=0;i<n;++i)
        if (2 * h[i] <= lmax[i] && 2 * h[i] <= rmax[i]) ans++;
    printf("%d",ans);
    return 0;
}