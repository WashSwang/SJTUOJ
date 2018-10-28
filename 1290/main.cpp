#include <iostream>
using namespace std;
long long T,x[300000],walktime,aktime,ans;
int heap[600000],num,n,t[300000];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void maxheapify(int x){
    int s=x;
    while (true){
        if (ls(x)<=num&&heap[ls(x)]>heap[s]) s=ls(x);
        if (rs(x)<=num&&heap[rs(x)]>heap[s]) s=rs(x);
        if (s!=x){
            swap(heap[s],heap[x]);
            x=s;
        }
        else break;
    }
}
void push(int x){
    heap[++num]=x;
    int now=num;
    while (now>1&&heap[now]>heap[now>>1]){
        swap(heap[now],heap[now>>1]);
        now>>=1;
    }
}
int pop(){
    int ret=heap[1];
    heap[1]=heap[num];
    num--;
    maxheapify(1);
    return ret;
}
void qsort(int l,int r){
    if (l+1>=r) return;
    int i=l,j=r-1,keyt=t[l];long long keyx=x[l];
    while (i<j){
        while (i<j&&x[j]>=keyx) --j;
        if (i<j){swap(x[i],x[j]);swap(t[i],t[j]);++i;}
        while (i<j&&x[i]<=keyx) ++i;
        if (i<j){swap(x[i],x[j]);swap(t[i],t[j]);--j;}
    }
    x[i]=keyx;
    t[i]=keyt;
    qsort(l,i);
    qsort(i+1,r);
}
int main() {
    scanf("%d%lld",&n,&T);
    for (int i=0;i<n;++i)
        scanf("%lld%d",&x[i],&t[i]);
    qsort(0,n);
    for (int i=0;i<n;++i) {
        walktime = x[i];
        while (num > 0 && walktime + aktime + t[i] > T && heap[1]>t[i]) aktime -= pop();
        if (aktime + walktime + t[i] <= T) {
            aktime += t[i];
            push(t[i]);
            if (num > ans) ans = num;
        }
    }
    printf("%lld",ans);
    return 0;
}