#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll root3(ll x)
{
    ll l=1,r=1000000,m;
    while (l<=r)
    {
        m=(l+r)/2;
        if (m*m*m==x) return m;
        if (m*m*m<x) l=m+1;
        else r=m-1;
    }
    return 0;
}
ll a,b,t;
int n;
int main() {
    scanf("%d",&n);
    for (int i=0;i<n;++i)
    {
        scanf("%lld%lld",&a,&b);
        if (!(t=root3(a*b))||a%t||b%t)
        {
            printf("No\n");
            continue;
        }
        printf("Yes\n");
    }
    return 0;
}