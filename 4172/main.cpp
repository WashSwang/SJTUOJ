#include <iostream>
using namespace std;
const int MAXN=1000001;
int a[MAXN],ans[4*MAXN],tag[4*MAXN],leftc[4*MAXN],rightc[4*MAXN],c[4*MAXN];
inline int ls(int p) {
    return p<<1;
}

inline int rs(int p) {
    return p<<1|1;
}

inline void push_up(int p,int l,int r) {
    int mid=(l+r)>>1;
    ans[p]=ans[ls(p)]+ans[rs(p)];
    leftc[p]=leftc[ls(p)];
    rightc[p]=rightc[rs(p)];
    if (mid-l+1==leftc[ls(p)]) leftc[p]+=leftc[rs(p)];
    if (r-mid==rightc[rs(p)]) rightc[p]+=rightc[ls(p)];
    c[p]=max(max(c[ls(p)],c[rs(p)]),rightc[ls(p)]+leftc[rs(p)]);
}

void build(int l,int r,int p) {
    if (l==r)
    {
        ans[p]=a[l];
        leftc[p]=a[l];
        rightc[p]=a[l];
        c[p]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,ls(p));
    build(mid+1,r,rs(p));
    push_up(p,l,r);
}
inline void add_tag(int p,int l,int r,int k)
{
    tag[p]=k;
    if (k==1)
        ans[p]=leftc[p]=rightc[p]=c[p]=0;
    if (k==2)
        ans[p]=leftc[p]=rightc[p]=c[p]=r-l+1;
}

inline void push_down(int p,int l,int r)
{
    int mid=(l+r)>>1;
    add_tag(ls(p),l,mid,tag[p]);
    add_tag(rs(p),mid+1,r,tag[p]);
    tag[p]=0;
}

void update(int nl,int nr,int l,int r,int p,int k)
{
    if (nl<=l&&r<=nr)
    {
        add_tag(p,l,r,k);
        return;
    }
    if (tag[p]!=0) push_down(p,l,r);
    int mid=(l+r)>>1;
    if (nl<=mid) update(nl,nr,l,mid,ls(p),k);
    if (nr>mid) update(nl,nr,mid+1,r,rs(p),k);
    push_up(p,l,r);
}

int query(int nl,int nr,int l,int r,int p)
{
    if (nl<=l&&r<=nr) return ans[p];
    if (tag[p]!=0) push_down(p,l,r);
    int mid=(l+r)>>1,sum=0;
    if (nl<=mid) sum+=query(nl,nr,l,mid,ls(p));
    if (nr>mid) sum+=query(nl,nr,mid+1,r,rs(p));
    return sum;
}

int query2(int nl,int nr,int l,int r,int p)
{
    if (nl<=l&&r<=nr) return c[p];
    int mid=(l+r)>>1,leap=0,lmax=0,rmax=0;
    if (tag[p]!=0) push_down(p,l,r);
    if (mid>=nl) lmax=query2(nl,nr,l,mid,ls(p));
    if (mid<nr) rmax=query2(nl,nr,mid+1,r,rs(p));
    leap=min(mid-nl+1,rightc[ls(p)])+min(nr-mid,leftc[rs(p)]);
    return max(max(lmax,rmax),leap);
}

int m,n,x,k,l,r;
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    build(1,n,1);
    for (int i=0;i<m;++i){
        scanf("%d%d%d",&k,&l,&r);
        if (k==1){
            scanf("%d",&x);
            update(l,r,1,n,1,x+1);
        }
        if (k==2)
            printf("%d\n",query(l,r,1,n,1));
        if (k==3)
            printf("%d\n",query2(l,r,1,n,1));
    }
    return 0;
}