#include <iostream>
#include <cstring>
using namespace std;
struct node{
    int val,p;
} h[1001],cur;
int n,nxt,a,b,len,pos[1001],way[1001][1001],k[1001],ans[1001];
void minheapify(int x){
    int smallest=x,l,r;
    while (true) {
        l=x<<1;
        r=l+1;
        if (l <= len && h[l].val < h[x].val) smallest = l;
        if (r <= len && h[r].val < h[smallest].val) smallest = r;
        if (smallest != x) {
            swap(pos[h[smallest].p],pos[h[x].p]);
            swap(h[smallest],h[x]);
            x = smallest;
        }
        else break;
    }
}
node pop(){
    node ret=h[1];
    pos[ret.p]=0;
    h[1]=h[len--];
    pos[h[1].p]=1;
    minheapify(1);
    return ret;
}
void insert(int val,int p){
    int i=++len;
    pos[p]=len;
    h[len].val=val;
    h[len].p=p;
    while (i>1 && h[i>>1].val>h[i].val)
    {
        swap(pos[h[i].p],pos[h[i>>1].p]);
        swap(h[i],h[i>>1]);
        i>>=1;
    }
}

void modify(int val,int p){
    h[p].val=val;
    int i=p;
    while (i>1 && h[i>>1].val>h[i].val)
    {
        swap(pos[h[i].p],pos[h[i>>1].p]);
        swap(h[i],h[i>>1]);
        i>>=1;
    }
}

int main() {
    scanf("%d%d%d",&n,&a,&b);
    for (int i=1;i<=n;++i){
        scanf("%d",&k[i]);
        for (int j=0;j<k[i];++j)
            scanf("%d",&way[i][j]);
        ans[i]=-1;
    }
    insert(0,a);
    while (len>0){
        cur=pop();
        ans[cur.p]=cur.val;
        if (k[cur.p]>0) {
            nxt=way[cur.p][0];
            if (pos[nxt]) {
                if (cur.val < h[nxt].val) modify(cur.val, pos[nxt]);
            }
            else if (ans[nxt]==-1||cur.val+1<ans[nxt]) insert(cur.val,nxt);
            for (int i=1;i<k[cur.p];++i)
            {
                nxt=way[cur.p][i];
                if (pos[nxt]) {
                    if (cur.val + 1 < h[nxt].val) modify(cur.val + 1, pos[nxt]);
                }
                else if (ans[nxt]==-1||cur.val+1<ans[nxt]) insert(cur.val+1,nxt);
            }
        }
    }
    printf("%d",ans[b]);
    return 0;
}