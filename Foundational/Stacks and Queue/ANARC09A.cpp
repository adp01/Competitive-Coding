#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;


#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int T=0;
    string s;
    cin>>s;
    while(s[0]!='-'){
        T++;
        stack <int> st;
        int m=0,c=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='{'){
                st.push(0);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
                else{
                    c++;
                }
            }
        }
        m+=c/2+c%2;
        int op=0;
        while(!st.empty()){
            op++;
            st.pop();
        }
        m+=op/2+op%2;
        cout<<T<<". "<<m<<endl;
        cin>>s;
    }
    return 0;
}