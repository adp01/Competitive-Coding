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
        int l;
        cin>>l;
        string s;
        cin>>s;
        long long int c=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                c++;
            }
        }
        c=(c*(c+1))/2;
        cout<<c<<endl;


    }
    return 0;
}