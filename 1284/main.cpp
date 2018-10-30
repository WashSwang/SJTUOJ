#include <iostream>
#include <cstring>
using namespace std;
int f[51][5001],a[51],b[51],n,k,v,w,c,pa,pb,ans;
int main() {
    scanf("%d%d%d",&k,&v,&n);
    memset(f,0x80,sizeof(f));
    f[0][0]=0;
    for (int i=0;i<n;++i){
        scanf("%d%d",&w,&c);
        for (int j=v;j>=w;--j){
            for (int l=0;l<k;++l){
                a[l]=f[l][j];
                b[l]=f[l][j-w]+c;
            }
            pa=pb=0;
            for (int l=0;l<k;++l)
                if (a[pa]>b[pb]) f[l][j]=a[pa++];
                else f[l][j]=b[pb++];
        }
    }
    for (int i=0;i<k;++i) ans+=f[i][v];
    printf("%d",ans);
    return 0;
}