#include <iostream>
using namespace std;
char t,cur,last;
int n,frag;
long long x,y;
int main() {
    scanf("%d%lld%lld",&n,&x,&y);
    getchar();
    last='1';
    for (int i=0;i<n;++i){
        cur=getchar();
        if (cur=='0'&&last=='1') frag++;
        last=cur;
    }
    if (frag==0) printf("%d",0);
    else
    printf("%lld",min((frag-1)*x+y,frag*y));
    return 0;
}