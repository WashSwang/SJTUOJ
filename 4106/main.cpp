#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int tr[1050000],m,h,w,n,t,x,f,ans[200001];//丐版线段树 请勿模仿
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    for (int i=0;i<t;++i)
    {
        memset(tr,0,sizeof(tr));
        cin>>h>>w>>n;
        h=min(h,n);
        for (m=1;m<h;m<<=1);
        for (int j=1+m;j<=m+h;++j)
            tr[j]=w;
        for (int j=m+h+1;j<=m<<1;++j)
            tr[j]=0;
        for (int j=m;j>=1;--j)
            tr[j]=max(tr[j<<1],tr[(j<<1)+1]);//以上为建树
        for (int j=0;j<n;++j)
        {
            cin>>x;
            if (tr[1]<x)
            {
                ans[j]=-1;
                continue;
            }
            f=1;
            while (f<=m)
                if (tr[f<<=1]<x) f+=1;//单点查询
            tr[f]-=x;
            ans[j]=f-m;
            for (f>>=1;f>=1;f>>=1) tr[f]=max(tr[f<<1],tr[(f<<1)+1]);//单点修改
        }
        for (int j=0;j<n;++j)
            cout<<ans[j]<<" ";
        cout<<endl;
    }
    return 0;
}