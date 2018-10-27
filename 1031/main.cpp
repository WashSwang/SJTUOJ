#include <iostream>
using namespace std;
int A[101][101],n,queue[20000][2],head,tail,dir[4][2]={-1,0,1,0,0,-1,0,1};
bool visit[101][101];
void enqueue(int x,int y,int lowb,int upb)
{
    int dx,dy;
    for (int i=0;i<4;++i){
        dx=dir[i][0];
        dy=dir[i][1];
        if (x+dx>=0&&x+dx<n&&y+dy>=0&&y+dy<n&&!visit[x+dx][y+dy]&&A[x+dx][y+dy]<=upb&&A[x+dx][y+dy]>=lowb){
            queue[tail][0]=x+dx;
            queue[tail][1]=y+dy;
            visit[x+dx][y+dy]=true;
            tail+=1;
        }
    }
}
int binarysearch(int low,int high)
{

    int ans=0;
    int l=low;
    int r=high;
    int mid;
    bool flag;
    while (l<=r)
    {
        mid=(l+r)/2;
        flag=false;
        for (int k=max(0,A[0][0]-mid);k<=min(A[0][0],A[n-1][n-1]);++k)
        {
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    visit[i][j]=0;
            queue[tail][0]=0;
            queue[tail][1]=0;
            visit[0][0]=true;
            head=0;tail=1;
            flag=false;
            while (head!=tail)
            {
                int x=queue[head][0];
                int y=queue[head][1];
                head+=1;
                if (x==n-1 && y==n-1)
                {
                    flag=true;
                    break;
                }
                enqueue(x,y,k,k+mid);
            }
            if (flag) break;
        }
        if (flag){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int high=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        {
            cin>>A[i][j];
            if (A[i][j]>high)
                high=A[i][j];
        }
    cout<<binarysearch(0,high);
    return 0;
}