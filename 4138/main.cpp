#include <iostream>
#include <iomanip>
using namespace std;
int sum,n,m,k[200],c[200],ex[20],num,x;
double ans;
int main() {
    cin>>n>>m;
    for (int i=0,j=1;i<15;i++,j<<=1) ex[i]=j;
    for (int i=0;i<m;++i){
        cin>>num>>c[i];
        for (int j=0;j<num;++j){
            cin>>x;
            k[i]+=ex[x];
        }
    }
    for (int i=0;i<(1<<n);++i){
        sum=0;
        num=0;
        for (int j=0;j<m;++j)
            if ((i&k[j])==k[j]) sum+=c[j];
        for (int j=i;j>0;j>>=1)
            if (j%2) num++;
        if (num!=0&&sum/double(num)>ans) ans=sum/double(num);
    }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<ans;
    return 0;
}