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
    while(n){
        lli a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        lli l[n],r[n];
        l[0]=0;
        r[n-1]=0;

        stack <pair <lli,lli> > s;
        s.push({a[0],0});
        for(int i=1;i<n;i++){
            while(!s.empty() && s.top().first>a[i]){
                s.pop();
            }
            if(s.empty()){
                l[i]=i;
            }
            else{
                if(s.top().first<a[i]){
                    l[i]=i-s.top().second-1;
                }
                else{
                    l[i]=i-s.top().second+l[s.top().second];
                    s.pop();
                }
            }
            // cout<<" "<<a[i]<<" "<<l[i]<<" "<<i<<endl;
            s.push({a[i],i});
        }

        while(!s.empty()){
            s.pop();
        }

        s.push({a[n-1],n-1});
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && s.top().first>a[i]){
                s.pop();
            }
            if(s.empty()){
                r[i]=n-1-i;
            }
            else{
                if(s.top().first<a[i]){
                    r[i]=s.top().second - i-1;
                }
                else{
                    r[i]=s.top().second-i+r[s.top().second];
                    s.pop();
                }

            }
            s.push({a[i],i});
        }

        lli ma=0;
        for(int i=0;i<n;i++){
            ma=max(ma,a[i]*(l[i]+r[i]+1));
        }

    
        // for(int i=0;i<n;i++){
        //     cout<<a[i]<<" "<<l[i]<<" "<<r[i]<<endl;
        // }
        cout<<ma<<endl;

       cin>>n; 
    }
    return 0;
}