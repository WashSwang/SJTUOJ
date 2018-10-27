#include <iostream>
#include <cstring>
using namespace std;
struct node{
    int n,h;
};
char cmd[200];
node heap[200000];
int ptr[200000],num,x,d;
inline int ls(int x){ return x<<1;}
inline int rs(int x){ return x<<1|1;}
void minheapify(int x){
    int s=x;
    while (true){
        if (ls(x)<=num&&(heap[ls(x)].h<heap[s].h||(heap[ls(x)].h==heap[s].h&&heap[ls(x)].n<heap[s].n))) s=ls(x);
        if (rs(x)<=num&&(heap[rs(x)].h<heap[s].h||(heap[rs(x)].h==heap[s].h&&heap[rs(x)].n<heap[s].n))) s=rs(x);
        if (s!=x)
        {
            swap(ptr[heap[s].n],ptr[heap[x].n]);
            swap(heap[s],heap[x]);
            x=s;
        }
        else break;
    }
}
void modify(int x,int d){
    heap[ptr[x]].h-=d;
    minheapify(ptr[x]);
    int cur=ptr[x];
    while (cur>1){
        if (heap[cur].h<heap[cur/2].h||(heap[cur].h==heap[cur/2].h&&heap[cur].n<heap[cur/2].n)){
            swap(ptr[heap[cur].n],ptr[heap[cur/2].n]);
            swap(heap[cur],heap[cur/2]);
            cur/=2;
        }
        else break;
    }
}
int findmin(int x,int cur){
    int ans=0x3f3f3f3f,index=0x3f3f3f3f,tmp;
    if (heap[cur].h<=x){
        if (ls(cur)<=num){
            tmp=findmin(x,ls(cur));
            if (tmp<=num&&(heap[ptr[tmp]].h<ans||(heap[ptr[tmp]].h==ans&&tmp<index))) {
                ans = heap[ptr[tmp]].h;
                index = tmp;
            }
        }
        if (rs(cur)<=num){
            tmp=findmin(x,rs(cur));
            if (tmp<=num&&(heap[ptr[tmp]].h<ans||(heap[ptr[tmp]].h==ans&&tmp<index))) {
                ans = heap[ptr[tmp]].h;
                index = tmp;
            }
        }
        return index;
    }
    else return heap[cur].n;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>num;
    for (int i=1;i<=num;++i) {
        cin>>heap[i].h;
        heap[i].n=i;
        ptr[i]=i;
    }
    for (int i=num;i>=1;--i)
        minheapify(i);
    while (cin>>cmd){
        if (strcmp(cmd,"findmin")==0){
            cin>>x;
            cout<<findmin(x,1)<<endl;
        }
        if (strcmp(cmd,"decrease")==0){
            cin>>x>>d;
            modify(x,d);
        }
    }
    return 0;
}