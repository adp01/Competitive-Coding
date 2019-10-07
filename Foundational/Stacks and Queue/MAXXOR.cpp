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

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    stack <int> s;
    int l=a[0]^a[1];
    s.push(max(a[0],a[1]));
    s.push(min(a[0],a[1]));
    for(int i=2;i<n;i++){
        while(!s.empty() && a[i]>s.top()){
            l=max(a[i]^s.top(),l);
            s.pop();
        }
        if(!s.empty()){
            l=max(l,s.top()^a[i]);
        }
        s.push(a[i]);
    }
    cout<<l<<endl;
    return 0;
}