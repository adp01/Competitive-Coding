#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;

const int MOD	= 1e9 + 7;

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define init(a)         memset(a,0,sizeof(a))    
#define pb              push_back  
#define all(a)          a.begin(),a.end()  

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }


double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}

int solve(vli a, int s, int e,int k){
    if(k==0){
        return 1;
    }
    if(k==1){
        return a[e]%MOD;
    }
    lli pp = (a[e]%MOD*a[e-1]%MOD)%MOD;
     if(a[s]>=0 ){
        return pp*solve(a,s,e-2,k-2);
    }

    lli np = (a[s]%MOD*a[s+1]%MOD)%MOD;
    // cout<<np<<" "<<pp<<endl;
    if(pp>=np){
        return pp*solve(a,s,e-2,k-2);
    }
    return np*solve(a,s+2,e,k-2);

}
int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        vli a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(all(a));
        lli ans=solve(a,0,n-1,k);
        if(ans<0){
            ans=ans+MOD;
        }
        cout<<ans<<endl;
    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}