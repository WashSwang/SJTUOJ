#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
const int p=1000000000;
//Attention! This class is not complete (It may make mistakes if you apply it in other problems).
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
char s[2000];
int main() {
    cin>>s;
    longint l,r(s),t(s),n(s),mid;
    r=(r-1)*2;
    t=(t-1)*2;
    while (!(l>r)){
        mid=div(l+r);
        if (mid*(mid+1)>t) r=mid-1;
        else l=mid+1;
    }
    l=l-1;
    n=n-div(l*(l+1));
    if (odd(l))
        cout<<n<<"/"<<l+2-n;
    else
        cout<<l+2-n<<"/"<<n;
    return 0;
}
