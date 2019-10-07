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

int insert(string &s,int b,int e,vector<int> dp[]){
    if(b>=e){
        return 0;
    }
    if(dp[b][e]!=-1){
        return dp[b][e];
    }
    if(s[b]==s[e]){
        dp[b][e]=insert(s,b+1,e-1,dp);
    }
    else{
        dp[b][e]=1+min(insert(s,b,e-1,dp),insert(s,b+1,e,dp));
    }
    return dp[b][e];

}
int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int l=s.length();
        vector<int> dp[l];
        loop(i,l){
            loop(j,l){
                dp[i].pb(-1);
            }
        }
        cout<<insert(s,0,l-1,dp)<<endl;
    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}