#include <iostream>
using namespace std;
int x,y,ans,n,head,rear=-1,c,s[5000000];
long long tol[4];
int parse(int c){
    if (c=='U') return 0;
    if (c=='D') return 1;
    if (c=='L') return 2;
    return 3;
}
inline bool check(long long x){
    return (x>=0)&&(x%2==0);
}
inline long long dist(){
    return abs(x-(tol[3]-tol[2]))+abs(y-(tol[0]-tol[1]));
}
int main() {
    scanf("%d",&n);
    ans=n+1;
    getchar();
    for (int i=0;i<n;++i){
        c=getchar();
        s[i]=parse(c);
        tol[parse(c)]++;
    }
    scanf("%d%d",&x,&y);
    for (int i=0;i<n;++i){
        tol[s[++rear]]--;
        while (check((rear-head+1)-dist())&&head<=rear){
            if (rear-head+1<ans) ans=rear-head+1;
            tol[s[head++]]++;
        }
    }
    if (ans==n+1) printf("-1");
    else printf("%d",ans);
    return 0;
}