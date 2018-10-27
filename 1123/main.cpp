#include <iostream>
using namespace std;
const int M=100007;
int ftree[262144][11],gtree[262144][11],df[11],dg[11],totalf[11],totalg[11],n,x[100001],y[100001],lastf,lastg,curf,curg,k;
inline int lowbit(int x) {
    return x&-x;
}
int query(int t[262144][11],int x,int k){
    int sum=0;
    while (x>0){
        sum=(sum+t[x][k])%M;
        x-=lowbit(x);
    }
    return sum;
}
void update(int t[262144][11],int x,int k,int d){
    while (x<=100000){
        t[x][k]=(t[x][k]+d)%M;
        x+=lowbit(x);
    }
}
void qsort(int l,int r){
    if (l+1>=r) return;
    int i=l,j=r-1,key=x[l],keyy=y[l];
    while (i<j){
        while (i<j&&x[j]>=key) --j;
        if (i<j){
            x[i]=x[j];
            y[i]=y[j];
            ++i;
        }
        while (i<j&&x[i]<=key) ++i;
        if (i<j){
            x[j]=x[i];
            y[j]=y[i];
            --j;
        }
    }
    x[i]=key;
    y[i]=keyy;
    qsort(l,i);
    qsort(i+1,r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for (int i=0;i<n;++i)
        cin >> x[i] >> y[i];
    qsort(0,n);
    for (int i=0;i<n;++i) {
        lastf=query(ftree,y[i]-1,0);
        lastg=query(gtree,y[i]-1,0);
        for (int j=1;j<=k;++j)
        {
            curf=query(ftree,y[i]-1,j);
            curg=query(gtree,y[i]-1,j);
            df[j]=curf+lastg;
            dg[j]=totalg[j]-curg+totalf[j-1]-lastf;
            if (dg[j]<0) dg[j]+=M;//WTF???? Be Cautious!!!
            update(ftree,y[i],j,df[j]);
            update(gtree,y[i],j,dg[j]);
            lastf=curf;
            lastg=curg;
        }
        update(ftree,y[i],0,1);
        update(gtree,y[i],0,1);
        totalf[0]++;
        totalg[0]++;
        for (int j=1;j<=k;++j){
            totalf[j]=(totalf[j]+df[j])%M;
            totalg[j]=(totalg[j]+dg[j])%M;
        }
    }
    cout<<(totalf[k]+totalg[k])%M;
    return 0;
}