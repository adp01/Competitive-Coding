#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;

const int MOD	= 1e9 + 7;

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define init(a)         memset(a,0,sizeof(a))    
#define pb              push_back  
#define all(a)          a.begin(),a.end()  
#define loop(i,n)       for(int i=0;i<n;i++)  
#define loops(i,s,n)    for(int i=s;i<n;i++)
#define rloop(i,n)      for(int i=n-1;i>=0;i--)
#define rloops(i,s,n)   for(int i=n-1;i>=s;i--)

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }


double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}


int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vi h(n),k(n);
        int ma=0;
        loop(i,n){
            cin>>h[i];
            ma=max(ma,h[i]);
        }
        loop(i,n){
            cin>>k[i];
        }
        vi dp(2*ma+1);
        dp[0]=0;
        loops(i,1,2*ma+1){
            dp[i]=INT_MAX;
            loop(j,n){
                if(k[j]<=i){
                    if(dp[i-k[j]]!=INT_MAX){
                        dp[i]=min(dp[i],1+dp[i-k[j]]);
                    }
                }
            }
        }
        int ans=0;
        loop(i,n){
            ans+=dp[h[i]*2];
        }
        cout<<ans<<endl;
        
    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}