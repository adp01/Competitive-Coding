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

    int n,k,p;
    cin>>n>>k>>p;
    vector <pii > a;
    vi g(n);
    loop(i,n){
        int pos;
        cin>>pos;
        a.pb({pos,i});
    }
    sort(all(a));
    int gr=0;
    loop(i,n){
        int f=a[i].first;
        int j=i;
        while(j<n && f+k>=a[j].first){
            f=a[j].first;
            j++;
        }
        for(;i<j;i++){
            g[a[i].second]=gr;
        }
        gr++;
        i--;
    }
    // loop(i,n){
    //     cout<<g[i]<<endl;
    // }
    loop(i,p){
        int f1,f2;
        cin>>f1>>f2;
        if(g[f1-1]==g[f2-1]){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}