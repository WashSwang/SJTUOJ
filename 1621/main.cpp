#include <iostream>
using namespace std;
int n,sorted[1001],pre[1001],cur,ans;
char mat[1001][1001];
void qsort(int l,int r){
    if (l+1>=r) return;
    int i=l,j=r-1,k=sorted[l];
    while (i<j){
        while (i<j&&sorted[j]<=k) j--;
        if (i<j) sorted[i++]=sorted[j];
        while (i<j&&sorted[i]>=k) i++;
        if (i<j) sorted[j--]=sorted[i];
    }
    sorted[i]=k;
    qsort(l,i);
    qsort(i+1,r);
}
int main() {
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>mat[i];
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
            if (mat[j][i]!='1')
                sorted[j]=pre[j]=0;
            else sorted[j]=pre[j]=pre[j]+1;
        qsort(0,n);
        cur=sorted[0];
        for (int j=0;j<n;++j){
            cur=min(cur,sorted[j]);
            ans=max(ans,cur*(j+1));
        }
    }
    cout<<ans;
    return 0;
}