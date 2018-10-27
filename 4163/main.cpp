#include <iostream>
#include <cstdio>
using namespace std;
int n,m,a[100001],l,r,mid,ans,cnt,cur;
bool flag;
int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;++i)
        scanf("%d",&a[i]);
    l=0;
    r=1000000000;
    while (l<=r){
        mid=(l+r)/2;
        cnt=0;
        cur=0;
        flag=true;
        for (int i=0;i<n;++i){
            if (a[i]>mid){
                flag=false;
                break;
            }
            if (cur+a[i]>mid){
                cur=0;
                cnt++;
            }
            if (cnt==m){
                flag=false;
                break;
            }
            cur+=a[i];
        }
        if (flag){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    printf("%d",ans);
    return 0;
}