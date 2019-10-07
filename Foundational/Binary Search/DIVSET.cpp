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

bool solve(multiset<lli> &m,lli e,int k,int c){
    // cout<<"ele "<<e<<endl;
    if(k==0){
        return true;
    }
    multiset<lli>::iterator it;
    it=m.find(e);
    if(it==m.end()){
        it=m.upper_bound(e);
    }
    if(it!=m.end()){
        // cout<<"ele :"<<e<<" "<<*it<<endl;
        bool a= solve(m,(*it)*c,k-1,c);
        m.erase(it);
        return a;
    }
    return false;
}
int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int T;
    cin>>T;
    while(T--){
        int n,k,c;
        cin>>n>>k>>c;
        multiset<lli > m;
        loop(i,n){
            int x;
            cin>>x;
            m.insert(x);
        }
        multiset<lli>::iterator it;
        lli ans=0;
        for(it=m.begin();it!=m.end();it++){
            if(solve(m,*it,k,c)){
                ans+=1;
            }
        }
        // for(it=m.begin();it!=m.end();it++){
        //     cout<<*it<<endl;
        // }
        cout<<ans<<endl;
    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}