#include <iostream>
#include <cstdio>
using namespace std;
int t,st[2000],top,n,m,p,x,s;
bool flag;
int main() {
    scanf("%d",&t);
    for (int i=0;i<t;++i){
        scanf("%d%d",&n,&m);
        s=0;
        flag=true;
        top=-1;
        for (int j=0;j<n;++j)
        {
            scanf("%d",&x);
            while (s<n&&s!=x&&((top>=0&&st[top]!=x)||top==-1))
            {
                if (top>=m-1) flag=false;
                st[++top]=s++;
            }
            if (s==x) s++;
            if (top>=0&&st[top]==x) top--;
        }
        if (top==-1&&s==n&&flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}