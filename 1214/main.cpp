#include <iostream>
#include <cstdio>
using namespace std;
int n,l[200000],r[200000],v[200000],s[200000],root,queue[200000],head=0,tail=1,p;
void pre(int x){
    cout<<v[x]<<" ";
    int p=l[x];
    while (p) {pre(p); p=r[p];}
}
void post(int x){
    int p=l[x];
    while (p) {post(p); p=r[p];}
    cout<<v[x]<<" ";
}
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d%d%d",&l[i],&r[i],&v[i]);
        s[l[i]]=1;
        s[r[i]]=1;
    }
    for (int i=1;i<=n;++i)
        if (!s[i]) root=i;
    pre(root);
    cout<<endl;
    post(root);
    cout<<endl;
    queue[0]=root;
    while (head<tail){
        cout<<v[queue[head]]<<" ";
        p=l[queue[head++]];
        while (p) {
            queue[tail++]=p;
            p=r[p];
        }
    }
    return 0;
}