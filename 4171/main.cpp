#include <iostream>
#include <cstring>
using namespace std;
int n,heap[2000000],p[2000000],len,a[1000000],b[1000000],q[1000000];
void minheapify(int x){
    int smallest=x,l,r;
    while (true) {
        l=x<<1;
        r=l+1;
        if (l <= len && heap[l] < heap[x]) smallest = l;
        if (r <= len && heap[r] < heap[smallest]) smallest = r;
        if (smallest != x) {
            swap(heap[smallest],heap[x]);
            swap(p[smallest],p[x]);
            x = smallest;
        }
        else break;
    }
}
int pop(){
    int ret=heap[1];
    q[p[1]]++;
    heap[1]=a[p[1]]+b[q[p[1]]];
    minheapify(1);
    return ret;
}
void qsort(int l,int r){
    if (l+1>=r) return;
    int i=l,j=r-1,key=b[l];
    while (i<j){
        while (i<j&&b[j]>=key) j--;
        if (i<j) b[i++]=b[j];
        while (i<j&&b[i]<=key) i++;
        if (i<j) b[j--]=b[i];
    }
    b[i]=key;
    qsort(l,i);
    qsort(i+1,r);
}
int main() {
    scanf("%d",&n);
    for (int i=0;i<n;++i) scanf("%d",&a[i]);
    for (int i=0;i<n;++i) scanf("%d",&b[i]);
    qsort(0,n);
    len=n;
    for (int i=1;i<=n;++i)
    {
        heap[i]=a[i-1]+b[0];
        p[i]=i-1;
        q[i]=0;
    }
    for (int i=n>>1;i>=1;--i) minheapify(i);
    for (int i=0;i<n;++i)
        printf("%d ",pop());
    return 0;
}