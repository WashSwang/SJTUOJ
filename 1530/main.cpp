#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char cmd1[10],cmd2[10],s[1010000],ans[1010000];
int t,n,top,stack[1050000],vis[1010000];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
inline void inorderEncode(const char* s,int n){
    int i=0,now;
    stack[top++]=1;
    while (top!=0){
        now=stack[top-1];
        if (vis[now]==0){
            vis[now]++;
            if (ls(now)<=n) stack[top++]=ls(now);
        }
        else
        if (vis[now]==1){
            top--;
            ans[i++]=s[now-1];
            if (rs(now)<=n) stack[top++]=rs(now);
        }
    }
}
inline void preorderEncode(const char* s,int n){
    int i=0,now;
    stack[top++]=1;
    while (top!=0){
        now=stack[top-1];
        if (vis[now]==0){
            ans[i++]=s[now-1];
            vis[now]++;
            if (ls(now)<=n) stack[top++]=ls(now);
        }
        else
        if (vis[now]==1){
            vis[now]++;
            if (rs(now)<=n) stack[top++]=rs(now);
        }
        else
            top--;
    }
}
inline void postorderEncode(const char* s,int n){
    int i=0,now;
    stack[top++]=1;
    while (top!=0){
        now=stack[top-1];
        if (vis[now]==0){
            vis[now]++;
            if (ls(now)<=n) stack[top++]=ls(now);
        }
        else
        if (vis[now]==1){
            vis[now]++;
            if (rs(now)<=n) stack[top++]=rs(now);
        }
        else
        {
            ans[i++]=s[now-1];
            top--;
        }
    }
}
inline void inorderDecode(const char* s,int n){
    int i=0,now;
    stack[top++]=1;
    while (top!=0){
        now=stack[top-1];
        if (vis[now]==0){
            vis[now]++;
            if (ls(now)<=n) stack[top++]=ls(now);
        }
        else
        if (vis[now]==1){
            top--;
            ans[now-1]=s[i++];
            if (rs(now)<=n) stack[top++]=rs(now);
        }
    }
}
inline void preorderDecode(const char* s,int n){
    int i=0,now;
    stack[top++]=1;
    while (top!=0){
        now=stack[top-1];
        if (vis[now]==0){
            ans[now-1]=s[i++];
            vis[now]++;
            if (ls(now)<=n) stack[top++]=ls(now);
        }
        else
        if (vis[now]==1){
            vis[now]++;
            if (rs(now)<=n) stack[top++]=rs(now);
        }
        else
            top--;
    }
}
inline void postorderDecode(const char* s,int n){
    int i=0,now;
    stack[top++]=1;
    while (top!=0){
        now=stack[top-1];
        if (vis[now]==0){
            vis[now]++;
            if (ls(now)<=n) stack[top++]=ls(now);
        }
        else
        if (vis[now]==1){
            vis[now]++;
            if (rs(now)<=n) stack[top++]=rs(now);
        }
        else
        {
            ans[now-1]=s[i++];
            top--;
        }
    }
}
int main() {
    cin>>t;
    ios::sync_with_stdio(false);
    for (int i=0;i<t;++i){
        top=0;
        memset(ans,0,sizeof(ans));
        memset(vis,0,sizeof(vis));
        cin>>n>>cmd1>>cmd2>>s;
        if (strcmp(cmd1,"INORDER")==0){
            if (strcmp(cmd2,"ENCODE")==0)
                inorderEncode(s,n);
            else
                inorderDecode(s,n);
        }
        if (strcmp(cmd1,"PREORDER")==0){
            if (strcmp(cmd2,"ENCODE")==0)
                preorderEncode(s,n);
            else
                preorderDecode(s,n);
        }
        if (strcmp(cmd1,"POSTORDER")==0){
            if (strcmp(cmd2,"ENCODE")==0)
                postorderEncode(s,n);
            else
                postorderDecode(s,n);
        }
        cout<<ans<<endl;
    }
    return 0;
}