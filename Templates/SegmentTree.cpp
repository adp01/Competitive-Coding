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

const int MAXN = 4*1e5;
int st[MAXN];
int n;

int combine(int a,int b){
    int val = a + b;

    return val;
}

void build(int l=0,int r=n-1,int node=1,vi &a){
    if(l == r){
        st[node] = a[l];
        return;
    }
    int m = l + (r - l) / 2;
    build(l, m, 2*node, a);
    build(m+1, r, 2*node + 1, a);
    st[node] = combine(st[2*node], st[2*node + 1]);
}

int query(int l=0,int r=n-1,int node=1,int x,int y){
    if(l > y || r < x){
        return 0;
    }
    if(l >= x && r <= y){
        return st[node];
    }

    int m = l + (r - l) / 2;
    int left = query( l, m, 2*node, x, y);
    int right=query(m + 1, r, 2*node + 1, x, y);

    int ans = combine(left, right);

    return ans;
}
void update(int l=0,int r=n-1,int node=1,int pos,int value){
    if(l == r){
        st[node] = value;
        return;
    }
    int m = l + (r - l) / 2;

    if(pos <= m){
        update(l, m, 2*node, pos, value);
    }
    else{
        update(m + 1, r, 2*node + 1, pos, value);
    }
    st[node] = combine(st[2*node],st[2*node + 1]);
}

int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int n;
    cin>>n;
    vi a(n);
    loop(i,n){
        cin>>a[i];
    }

    build(0,n-1,1,a);

    int q;
    cin>>q;
    while(q--){
        
    }

    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}