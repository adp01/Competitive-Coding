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

bool comp(pair <int,pii > p1,pair <int,pii > p2){
    return p1.second.first<p2.second.first;
}
int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int T;
    cin>>T;
    while(T--){
        int n,d;
        cin>>n>>d;
        vector < pair <int, pii > > v(n);
        loop(i,n){
            cin>>v[i].second.first>>v[i].second.second>>v[i].first;
        }
        sort(all(v),comp);
        priority_queue<pair<int, pii > > p;
        int j=0;
        loops(i,1,d+1){
            while(j<n && v[j].second.first==i){
                p.push(v[j]);
                j++;
            }
            if(p.empty()){
                continue;
            }
            pair <int, pii > a=p.top();
            // cout<<i<<": "<<a.first<<endl;
            p.pop();
            a.second.second--;
            if(a.second.second>0){
                p.push(a);
            }
        }
        lli ans=0;
        while(!p.empty()){
            pair <int, pii > a=p.top();
            p.pop();
            ans+=(lli)a.first*(lli)a.second.second;
        }
        cout<<ans<<endl;
    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}