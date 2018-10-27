#include <iostream>
#include <string>
using namespace std;
string s,name[30],who,towho,days[7]={"Monday.","Tuesday.","Wednesday.","Thursday.","Friday.","Saturday.","Sunday."};
int m,n,p,mh,f,t,c,succ,pos;
char ch;
int findname(string name1)
{
    for (int j=0;j<m;++j)
        if (name1==name[j])
            return j;
    return -1;
}
int main() {
    cin>>m>>n>>p;
    ch=getchar();
    for (int i=0;i<m;++i){
        getline(cin,name[i]);
    }
    for (int i=0;i<p;++i){
        getline(cin,s);
        mh=s.find(':');
        who=s.substr(0,mh);
        c=-1;
        f=findname(who);
        if (f==-1) continue;
        pos=s.find('.');
        if (pos!=s.length()-1) continue;
        pos=s.find(" have the ring.");
        if (pos!=-1) {
            if (pos - mh == 3 && s[pos - 1] == 'I' && s[mh + 2] == 'I') {
                t = f;
                c = 1;
            }
        }
        else{
            pos=s.find(" have not the ring.");
            if (pos!=-1) {
                if (pos - mh == 3 && s[pos - 1] == 'I' && s[mh + 2] == 'I') {
                    t = f;
                    c = 2;
                }
            }
            else{
                pos=s.find(" has the ring.");
                if (pos!=-1){
                    t=findname(s.substr(mh+2,pos-2-mh));
                    if (t!=-1) c=1;
                }
                else{
                    pos=s.find(" has not the ring.");
                    if (pos!=-1){
                        t=findname(s.substr(mh+2,pos-2-mh));
                        if (t!=-1) c=2;
                    }
                    else{
                        pos=s.find(" Today is ");
                        if (pos!=-1){
                            t=-1;
                            for (int j=0;j<7;++j)
                                if (s.find(days[j])==pos+10)
                                {
                                    t=j+1;
                                    break;
                                }
                            if (t!=-1) c=3;
                        }
                    }
                }
            }
        }
        if (c!=-1)
        {
            succ++;
            cout<<f<<" "<<t<<" "<<c<<endl;
        }
    }
    if (!succ) cout<<"Orz"<<endl;
    return 0;
}