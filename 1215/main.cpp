#include <iostream>
#include <cstring>
using namespace std;
int n,heap[30000],len,x;
char cmd[20];
void minheapify(int x){
    int smallest=x,l,r,tmp;
    while (true) {
        l=x<<1;
        r=l+1;
        if (l <= len && heap[l] < heap[x]) smallest = l;
        if (r <= len && heap[r] < heap[smallest]) smallest = r;
        if (smallest != x) {
            tmp = heap[smallest];
            heap[smallest] = heap[x];
            heap[x] = tmp;
            x = smallest;
        }
        else break;
    }
}
void insert(int x){
    int i=++len,tmp;
    heap[len]=x;
    while (i>1 && heap[i/2]>heap[i])
    {
        tmp=heap[i/2];
        heap[i/2]=heap[i];
        heap[i]=tmp;
        i=i/2;
    }
}
int pop(){
    int ret=heap[1];
    heap[1]=heap[len--];
    minheapify(1);
    return ret;
}
int main() {
    cin>>n;
    len=0;
    for (int i=0;i<n;++i){
        cin>>cmd;
        if (strcmp(cmd,"insert")==0){
            cin>>x;
            insert(x);
        }
        if (strcmp(cmd,"delete")==0) pop();
        if (strcmp(cmd,"min")==0) cout<<heap[1]<<endl;
    }
    return 0;
}