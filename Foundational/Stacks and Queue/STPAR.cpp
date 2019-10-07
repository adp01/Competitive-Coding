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

    int ei;
    cin>>ei;
    while(ei){
        int n=ei;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        stack <int> s;
        int j=1;
        for(int i=0;i<n;i++){
            if(a[i]==j){
                j++;
            }
            else if(!s.empty() && s.top()==j){
                i--;
                j++;
                s.pop();
            }
            else{
                s.push(a[i]);
            }
        }
        if(j<=n && !s.empty()){
            while(!s.empty() && j==s.top()){
                j++;
                s.pop();
            }
        }
        if(j==n+1){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
        cin>>ei;
    }

    
    return 0;
}