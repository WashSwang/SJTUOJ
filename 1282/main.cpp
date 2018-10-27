#include <iostream>
#include <cstring>
using namespace std;
int n,h[3000],o[3000];
long long dps[2001][2001],dpt[2001][2001],mins,mint;
void qsort(int *s,int *t){
    if (s+1>=t) return;
    int i=0,j=int(t-s)-1,x=s[0];
    while (i<j){
        while (i<j&&s[j]>=x) j--;
        if (i<j) s[i++]=s[j];
        while (i<j&&s[i]<=x) i++;
        if (i<j) s[j--]=s[i];
    }
    s[i]=x;
    qsort(s,s+i);
    qsort(s+i+1,t);
}
int main() {
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>h[i];
        o[i]=h[i];
    }
    qsort(o+1,o+n+1);
    for (int i=1;i<=n;++i) {
        mins=1e12;
        for (int j = 1; j <= n; ++j){
            if (dps[i-1][j]<mins) mins=dps[i-1][j];
            dps[i][j]=mins+abs(h[i]-o[j]);
        }
        mint=1e12;
        for (int j = n; j>=1;--j){
            if (dpt[i-1][j]<mint) mint=dpt[i-1][j];
            dpt[i][j]=mint+abs(h[i]-o[j]);
        }
    }
    mins=1e12;
    mint=1e12;
    for (int i=1;i<=n;++i)
    {
        mins=min(dps[n][i],mins);
        mint=min(dpt[n][i],mint);
    }
    cout<<min(mins,mint);
    return 0;
}