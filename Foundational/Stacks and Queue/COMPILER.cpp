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
        int fl=0;
        stack <int> s;
        for(int i=0;i<e.length();i++){
            if(e[i]=='<'){
                s.push(1);
            }
            else{
                if(!s.empty()){
                    s.pop();
                }
                else{
                    break;
                }
            }
            if(s.empty()){
                fl=i+1;
            }
        }
        cout<<fl<<endl;
    }
    return 0;
}