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
bool comp(const pii p1,const pii p2){
    if(p1.first==p2.first){
        return p1.second<p2.second;
    }
    return p1.first>p2.first;
}
void update(vector <pii > & p,pii d){
    int s=0,e=p.size()-1;
    while(s<=e){
        
        int m=s+(e-s)/2;
        if(p[m].second<=d.second){
            s=m+1;
        }
        else{
            e=m-1;
        }
        
    }
    if(s==p.size()){
        p.pb(d);
    }
    else{
        p[s].first=d.first;
        p[s].second=d.second;
    }
}
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
        vector <pii > v(n);
        loop(i,n){
            cin>>v[i].first>>v[i].second;
        }
        sort(all(v),comp);
        vector <pii > p;
        p.pb(v[0]);
        loops(i,1,n){
            update(p,v[i]);
            // loop(i,p.size()){
            //     cout<<p[i].first<<" "<<p[i].second<<endl;
            // }
            // cout<<endl;
        }
        
        cout<<p.size()<<endl;


    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}