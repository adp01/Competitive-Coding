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

    int n;
    cin>>n;
    vi c[3];
    lli m=0;
    loop(i,n){
        int w,v;
        cin>>w>>v;
        c[w].pb(v);
        m+=w;
    }
    sort(all(c[1]),greater<int>());
    sort(all(c[2]),greater<int>());
    vli ans(m+1);
    ans[0]=0;
    int t=0,o=0;
    int s1=c[1].size();
    for(int i=2;i<=m;i+=2){
        ans[i]=0;
        if(o<(s1-1) && t<c[2].size()){
            if(c[1][o]+c[1][o+1]>c[2][t]){
                ans[i]=ans[i-2]+c[1][o]+c[1][o+1];
                o+=2;
            }
            else{
                ans[i]=ans[i-2]+c[2][t];
                t+=1;
            }
        }
        else if(o<(s1-1)){
            ans[i]=ans[i-2]+c[1][o]+c[1][o+1];
            o+=2;
        }
        else if(t<c[2].size()){
            ans[i]=ans[i-2]+c[2][t];
            t+=1;
        }
    }
    if(s1>0){
        o=1;t=0;
        ans[1]=c[1][0];

    }
    else{
        ans[1]=0;
        o=0;t=0;
    }
    for(int i=3;i<=m;i+=2){
        ans[i]=0;
        if(o<(s1-1) && t<c[2].size()){
            if(c[1][o]+c[1][o+1]>c[2][t]){
                ans[i]=ans[i-2]+c[1][o]+c[1][o+1];
                o+=2;
            }
            else{
                ans[i]=ans[i-2]+c[2][t];
                t+=1;
            }
        }
        else if(o<(s1-1)){
            ans[i]=ans[i-2]+c[1][o]+c[1][o+1];
            o+=2;
        }
        else if(t<c[2].size()){
            ans[i]=ans[i-2]+c[2][t];
            t+=1;
        }
    }
    loops(i,1,m+1){
        ans[i]=max(ans[i],ans[i-1]);
    }
    loop(i,m){
        cout<<ans[i+1]<<" ";
    }
    cout<<endl;
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}