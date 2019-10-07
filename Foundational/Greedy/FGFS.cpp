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

bool comp(const pair<int,pii > p1,const pair<int,pii > p2){
    if(p1.second.second!=p2.second.second){
        return p1.second.second<p2.second.second;
    }
    return p1.first<p2.first;
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
        vector <pair<int,pii > > v;
        loop(i,n){
            int s,f,p;
            cin>>s>>f>>p;
            v.pb(make_pair(f,make_pair(s,p)));
        }
        sort(all(v),comp);
        // loop(i,n){
        //     cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
        // }
        int c=0;
        int cf=0;
        int p=v[0].second.second;
        loop(i,n){
            if(p!=v[i].second.second){
                //Begin of new compartment
                p=v[i].second.second;
                cf=0;
            }
            
            if(v[i].second.first>=cf){
                c++;
                cf=v[i].first;
            }
            
        }
        cout<<c<<endl;

           
    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}