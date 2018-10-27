#include <iostream>
#include <cstdio>
using namespace std;
char rstack[1000001],istack[1000001],c;
int rtop,itop,n,x;
bool match[1000001];
void push(char c){
    if (rstack[rtop-1]=='('&&c==')') {
        rtop--;
        match[itop]=true;
    }
    else if (rstack[rtop-1]=='['&&c==']') {
        rtop--;
        match[itop]=true;
    }

    else if (rstack[rtop-1]=='{'&&c=='}') {
        rtop--;
        match[itop]=true;
    }
    else rstack[rtop++]=c;
}
void raw_push(char c){
    if (rstack[rtop-1]=='('&&c==')') rtop--;
    else if (rstack[rtop-1]=='['&&c==']') rtop--;
    else if (rstack[rtop-1]=='{'&&c=='}') rtop--;
    else rstack[rtop++]=c;
}
void pop(){
    switch (istack[itop-1]) {
        case '(':
            raw_push(')');
            break;
        case ')':
            if (match[itop-1]) {raw_push('('); match[itop-1]=false;}
            else rtop--;
            break;
        case '[':
            raw_push(']');
            break;
        case ']':
            if (match[itop-1]) {raw_push('['); match[itop-1]=false;}
            else rtop--;
            break;
        case '{':
            raw_push('}');
            break;
        case '}':
            if (match[itop-1]) {raw_push('{'); match[itop-1]=false;}
            else rtop--;
            break;
    }
    itop--;
}
int main() {
    scanf("%d",&n);
    for (int i=0;i<n;++i)
    {
        scanf("%d",&x);
        if (x==1){
            scanf(" %c",&c);
            push(c);
            istack[itop++]=c;
        }
        if (x==2&&itop>=1) pop();
        if (x==3&&itop>=1) printf("%c\n",istack[itop-1]);
        if (x==4){
            if (!rtop) printf("YES\n");
            else printf("NO\n");}
    }
    return 0;
}