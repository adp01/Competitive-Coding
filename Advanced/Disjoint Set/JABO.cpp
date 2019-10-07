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

const int MAXN = 500*2500+3;
int id[MAXN];
int sz[MAXN];
int v[MAXN];

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
            v[p2]+= v[p1];
        }else{
            id[p2] = p1;
            sz[p1] += sz[p2];
            v[p1]+=v[p2];
        }
    }
}

void init_dsu(int N){
    loop(i, N){
        id[i] = i;
        sz[i] = 1;
        v[i]=0;
    }
}
int decrypt(char t,char o){
    int a,b;
    if(t>='a'){
        a=t-'a'+26;
    }
    else{
        a=t-'A';
    }
    if(o>='a'){
        b=o-'a'+26;
    }
    else{
        b=o-'A';
    }
    return a*52+b;
}
int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

   
    int n,R,C;
    cin>>n>>R>>C;
    init_dsu(R*C+3);
    while(n--){
        string s;
        cin>>s;
        int r,c,x,x1,x2,p,p1,p2;
        switch(s[0]){
            case 'W':
                r=decrypt(s[1],s[2]);
                c=decrypt(s[3],s[4]);
                x1=((c-1)/5)*C+r-1;
                r=decrypt(s[5],s[6]);
                c=decrypt(s[7],s[8]);
                x2=((c-1)/5)*C+r-1;
                // cout<<"W : "<<x1<<" "<<x2<<endl;
                unite(x1,x2);
            break;

            case 'V':
                r=decrypt(s[1],s[2]);
                c=decrypt(s[3],s[4]);
                x=((c-1)/5)*C+r-1;
                p=root(x);
                // cout<<"V : "<<x<<endl;
                v[p]+=1;
            break;

            case 'R':
                r=decrypt(s[1],s[2]);
                c=decrypt(s[3],s[4]);
                x=((c-1)/5)*C+r-1;
                p=root(x);
                // cout<<"R : "<<x<<endl;
                v[p]=max(0,v[p]-1);
            break;

            case 'L':
                r=decrypt(s[1],s[2]);
                c=decrypt(s[3],s[4]);
                x1=((c-1)/5)*C+r-1;
                r=decrypt(s[5],s[6]);
                c=decrypt(s[7],s[8]);
                x2=((c-1)/5)*C+r-1;
                p1=root(x1);
                p2=root(x2);
                // cout<<"L : "<<x1<<" "<<x2<<endl;
                // cout<<p1<<" "<<p2<<endl;
                if(v[p1]==v[p2]){
                    cout<<"OFF"<<endl;
                }
                else{
                    cout<<"ON"<<endl;
                }
            break;
        }
    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}