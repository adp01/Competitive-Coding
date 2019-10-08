#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef priority_queue <int, vector <int>, greater <int> > min_pq;

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

//---------------------------------------------------------------------------------------------
const int MAXN = 100005;
int id[MAXN];
int sz[MAXN];

int root(int p){
    while(p != id[p]){
        id[p] = id[id[p]];
        p = id[p];
    }
    return p;
}

void unite(int a, int b){
    int p1 = root(a);
    int p2 = root(b);
    if(p1 != p2){
        if(sz[p1] < sz[p2]){
            id[p1] = p2;
            sz[p2] += sz[p1];
        }else{
            id[p2] = p1;
            sz[p1] += sz[p2];
        }
    }
}

void init_dsu(int N){
    loop(i, N){
        id[i] = i;
        sz[i] = 1;
    }
}

int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int n, m, k;
    cin >> n >> m >> k;
    init_dsu(n);

    loop(i, n - k + 1){
        int l = k - 1;
        for(int j = 0; j <= l / 2; j++ ){
            unite(j + i, l - j + i);
            // cout << j + i <<" " << l - j + i << endl;
        }
    }

    set <int> s;
    lli ans = 1;
    int p;
    loop(i, n){
        p = root(i);
        s.insert(p);
    }

    loop(i, s.size()){
        ans = ans * m;
        ans %= MOD;
    }

    // set <int> :: iterator it;
    // for( it = s.begin(); it != s.end(); it++){
    //     cout << *it << endl;
    // }

    cout<< ans <<endl;

    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}