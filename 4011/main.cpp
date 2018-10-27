#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
const int p=1000000000;
//Same as 4152
class longint{

    long long num[3000];
    int len;
public:
    longint(){
        memset(num,0,sizeof(num));
        len=1;
    };

    longint(const char *s){
        memset(num,0,sizeof(num));
        int l=(strlen(s)-1)/9+1,length=strlen(s);
        for (int i=0;i<l;++i){
            for (int j=length-9*i-9;j<length-9*i;++j)
                if (j>=0)
                    num[i]=num[i]*10+s[j]-48;
        }
        len=l;
    }

    longint(int x){
        memset(num,0,sizeof(num));
        len=0;
        while (x!=0)
        {
            num[len++]=x%p;
            x/=p;
        }
    }

    longint(const longint &a):len(a.len){
        memset(num,0,sizeof(num));
        for (int i=0;i<a.len;++i)
            num[i]=a.num[i];
    }

    longint &operator=(const longint& a){
        memset(num,0,sizeof(num));
        len=a.len;
        for (int i=0;i<a.len;++i)
            num[i]=a.num[i];
        return *this;
    }

    friend longint operator+(const longint& a,const longint& b){
        long long c=0;
        longint r;
        r.len=max(a.len,b.len);
        for (int i=0;i<r.len;++i){
            r.num[i]=a.num[i]+b.num[i]+c;
            c=r.num[i]/p;
            r.num[i]%=p;
        }
        if (c>0) r.num[r.len++]=c;
        return r;
    }

    friend longint operator-(const longint& a,const longint& b){
        int c=0;
        longint r;
        r.len=max(a.len,b.len);
        for (int i=0;i<max(a.len,b.len);++i){
            r.num[i]=a.num[i]-b.num[i]-c;
            c=0;
            if (r.num[i]<0){
                r.num[i]+=p;
                c=1;
            }
        }
        while (r.len>1&&!r.num[r.len-1]) r.len--;
        return r;
    }

    friend longint operator*(const longint& a,const longint& b){
        long long c=0,pos;
        int x=0;
        longint r;
        for (int i=0;i<b.len;++i){
            x=i;
            c=0;
            longint tmp;
            for (int j=0;j<a.len;++j){
                pos=a.num[j]*b.num[i]+c;
                c=pos/p;
                tmp.num[x]=pos%p;
                x++;
            }
            tmp.len=x;
            if (c>0) tmp.num[tmp.len++]=c;
            r=r+tmp;
        }
        return r;
    }

    friend longint div(const longint& a){
        longint r;
        long long x=0;
        for (int i=a.len-1;i>=0;i--){
            x=x*p+a.num[i];
            r.num[i]=x/2;
            x%=2;
        }
        r.len=a.len;
        if (!r.num[r.len-1]) r.len--;
        return r;
    }

    friend bool operator>(const longint& a,const longint& b){
        if (a.len>b.len) return true;
        if (a.len<b.len) return false;
        for (int i=a.len-1;i>=0;--i){
            if (a.num[i]>b.num[i]) return true;
            if (a.num[i]<b.num[i]) return false;
        }
        return false;
    }

    friend ostream& operator<<(ostream& os,const longint &a){
        os.fill('0');
        os<<a.num[a.len-1];
        for (int i=a.len-2;i>=0;--i) {
            os<<setw(9)<<a.num[i];
        }
        return os;
    }

    friend bool odd(longint &a){
        return a.num[0]%2!=0;
    }
};
longint x[51][51];
int h,k;
int main() {
    cin>>k>>h;
    for (int i=0;i<=k-1;++i) x[1][i]=k-i;
    for (int i=2;i<=h-1;++i){
        for (int j=0;j<=k-1;++j)
            for (int l=0;l<k-j;++l) x[i][j]=x[i][j]+x[i-1][l];
    }
    cout<<x[h-1][0];
}