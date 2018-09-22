#include <iostream>
#include <cstring>
using namespace std;
int s,n;
int t[501][4001];//前i根棒子中 可以组成的两条长度差为j的轨道中较大的那条的长度
int main() {
    cin>>n;
    memset(t,-1,sizeof(t));
    t[0][0]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>s;
        for (int j=0;j<=2000;++j){
            t[i][j]=t[i-1][j];//不加这根塑料棒
            if (j>=s&&t[i-1][j-s]!=-1&&t[i-1][j-s]+s>t[i][j]) t[i][j]=t[i-1][j-s]+s;//加在较长的那条上 差值变大 较长的长度变大
            if (t[i-1][j+s]>t[i][j]) t[i][j]=t[i-1][j+s];//加在较短的那条上 但并未超过较长的那条 差变小 较长的长度不变
            if (s>=j&&t[i-1][s-j]!=-1&&t[i-1][s-j]+j>t[i][j]) t[i][j]=t[i-1][s-j]+j;//加在较短的那条上 超过了原来较长的那条 长度变大
        }
    }
    if (!t[n][0]) cout<<"Impossible";
    else cout<<t[n][0];
    return 0;
}