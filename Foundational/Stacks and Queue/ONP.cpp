#include <bits/stdc++.h>
using namespace std;

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int T;
    cin>>T;
    while(T--){
        string e;
        cin>>e;
        stack <string> s;
        for(int i=0;i<e.length();i++){
                if(e[i]=='('){
                    continue;
                }
                else if(e[i]==')'){
                    string op2,op,op1;
                    op2=s.top();
                    s.pop();
                    op=s.top();
                    s.pop();
                    op1=s.top();
                    s.pop();
                    s.push(op1+op2+op);
                }
                else{
                    s.push(string(1,e[i]));
                }
        }
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}