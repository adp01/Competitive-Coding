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

typedef struct data{
    long long int prefix, suffix, sum, ans;
}data;

const int MAXN=50000;
data st[4*MAXN];

void combine(int node){
    int l=2*node,r=2*node+1;
    st[node].sum=st[l].sum+st[r].sum;
    st[node].prefix=max(st[l].prefix,st[l].sum+st[r].prefix);
    st[node].suffix=max(st[r].suffix,st[l].suffix+st[r].sum);
    st[node].ans=max(st[l].ans,max(st[r].ans,st[l].suffix+st[r].prefix));
}
void build(int node,int l,int r,vli &a){
    // cout<<node<<endl;
    if(l==r){
        st[node].sum=a[l];
        st[node].prefix=st[node].suffix=a[l];
        st[node].ans=a[l];
        return;
    }
    int m=l+(r-l)/2;
    build(2*node,l,m,a);
    build(2*node+1,m+1,r,a);
    combine(node);
}
data soln(int l,int r,int node,int x,int y){
    if(x>r || y<l){
        data d;
        d.sum=0;
        d.prefix=d.suffix=-1000000;
        d.ans=INT_MIN;
        return d;
    }

    if(l>=x && r<=y)return st[node];

    int m=l+(r-l)/2;
    data left=soln(l,m,2*node,x,y);
    data right=soln(m+1,r,2*node+1,x,y);
    data d;
    if(left.ans==INT_MIN){
        return right;
    }
    if(right.ans==INT_MIN){
        return left;
    }
    d.sum=left.sum+right.sum;
    d.prefix=max(left.prefix,left.sum+right.prefix);
    d.suffix=max(right.suffix,left.suffix+right.sum);
    d.ans=max(left.ans,max(right.ans,right.prefix+left.suffix));
    return d;
}

int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int n;
    cin>>n;
    vli a(n);
    loop(i,n){
        cin>>a[i];
    }
    build(1,0,n-1,a);
    // cout<<"Build successful"<<endl;

    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        data d=soln(0,n-1,1,l-1,r-1);
        cout<<d.ans<<endl;
    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}