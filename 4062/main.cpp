#include <iostream>
using namespace std;
long long a,b;
long long x(long long a,long long b)
{
    if (b!=0)
        return a/b*4*b+x(b,a%b);
    else return 0;
}
int main() {
    cin>>a>>b;
    cout<<x(a,b);
    return 0;
}