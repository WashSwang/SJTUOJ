#include <iostream>
using namespace std;
int m,n;
int main() {
    cin>>m;
    for (int i=0;i<m;++i)
    {
        cin>>n;
        if (n!=0) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}