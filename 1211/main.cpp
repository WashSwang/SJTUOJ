#include <iostream>
#include <cstdio>
using namespace std;
int ls[200000],rs[200000],t[200000],n,d=-1,root;
bool ans=true,sec=true;
void dfs(int i,int depth)
{
    if (ls[i]) dfs(ls[i],depth+1);
    if ((!ls[i])||(!rs[i])) {
        if (d == -1)
            d = depth;
        else {
            if ((depth == d - 1) && sec) {
                d = depth;
                sec = false;
            }
            if (d != depth) ans = false;
        }
    }
    if (rs[i]) dfs(rs[i],depth+1);

}
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d%d",&ls[i],&rs[i]);
        t[ls[i]]++;
        t[rs[i]]++;
    }
    for (int i=1;i<=n;++i)
        if (!t[i]) {
            root=i;
            break;
        }
    dfs(root,1);
    if (ans) printf("Y");
    else printf("N");
    return 0;
}