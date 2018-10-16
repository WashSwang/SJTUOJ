#include <iostream>
using namespace std;
int t,st[1100000],top,n,now,a[1100000];
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    for (int i=0;i<t;++i)
    {
        cin>>n;
        now=0;
        top=0;
        for (int j=0;j<n;++j)
            cin>>a[j];
        for (int j=1;j<=n;++j) {
            st[top++] = j;
            while (a[now]==st[top-1]&&now<n&&top>=0) {
                top--;
                now++;
            }
        }
        if (top!=0) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}