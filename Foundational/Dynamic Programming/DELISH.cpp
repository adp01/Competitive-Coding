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
        vli a(n);
        loop(i,n){
            cin>>a[i];
        }
        vli e(n),s(n),me(n),ms(n);
        lli cur=0;
        loop(i,n){
            e[i]=max(cur+a[i],a[i]);
            cur=e[i];
        }
        cur=0;
        loop(i,n){
            me[i]=min(cur+a[i],a[i]);
            cur=me[i];
        }
        cur=0;
        rloop(i,n){
            s[i]=max(a[i],cur+a[i]);
            cur=s[i];
        }
        cur=0;
        rloop(i,n){
            ms[i]=min(a[i],cur+a[i]);
            cur=ms[i];
        }
        vli ma(n),mi(n);
        ma[n-2]=s[n-1];
        mi[n-2]=ms[n-1];
        rloop(i,n-2){
            ma[i]=max(s[i+1],ma[i+1]);
            mi[i]=min(ms[i+1],mi[i+1]);
        }
        // cout<<"Max ending:"<<endl;
        // loop(i,n){
        //     cout<<e[i]<<" ";
        // }
        // cout<<endl;
        // cout<<"Min ending:"<<endl;
        // loop(i,n){
        //     cout<<me[i]<<" ";
        // }
        // cout<<endl;
        // cout<<"Max starting:"<<endl;
        // loop(i,n){
        //     cout<<s[i]<<" ";
        // }
        // cout<<endl;
        // cout<<"Min starting:"<<endl;
        // loop(i,n){
        //     cout<<ms[i]<<" ";
        // }
        // cout<<endl;
        lli ans=0;
        loop(i,n-1){
            ans=max(abs(ma[i]-me[i]),max(abs(ma[i]-e[i]),max(abs(mi[i]-me[i]),max(abs(mi[i]-e[i]),ans))));
        }
        cout<<ans<<endl;

    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}