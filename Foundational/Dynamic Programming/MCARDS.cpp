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

vi p;
int n,c;

bool comp(pii p1,pii p2){
    if(p1.first==p2.first){
        return p1.second<p2.second;
    }
    int pos1=0,pos2=0;
    loop(i,p.size()){
        if(p[i]==p1.first){
            pos1=i;
        }
        if(p[i]==p2.first){
            pos2=i;
        }
    }
    // cout<<p1.first<<": "<<pos1<<p2.first<<": "<<pos2<<endl;
    return pos1<pos2;
}
int fact(int c){
    if(c==1){
        return c;
    }
    else{
        return c*fact(c-1);
    }
}
int lcs(vector <pii > &v, vector <pii> &cv){
    int dp[v.size()+1][v.size()+1];
    loop(i,v.size()+1){
        dp[0][i]=0;
        dp[i][0]=0;
    }
    loops(i,1,v.size()+1){
        loops(j,1,v.size()+1){
            if(v[i-1]==cv[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[v.size()][v.size()];

}
int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    
    cin>>c>>n;
    vector <pii > v(n*c),cv(n*c);
    loop(i,n*c){
        cin>>v[i].first>>v[i].second;
        cv[i]=v[i];
    }
    loop(i,c){
        p.pb(i+1);
    }
    int ans=n*c;
    loop(i,fact(c)){
        sort(all(cv),comp);
        // cout<<"Permutation:"<<endl;
        // loop(i,c){
        //     cout<<p[i]<<endl;
        // }
        // cout<<endl;
        // cout<<"Cards"<<endl;
        // loop(i,n*c){
        //     cout<<cv[i].first<<" "<<cv[i].second<<endl;
        // }
        next_permutation(all(p));
        int l=lcs(v,cv);
        // cout<<l<<endl;
        // cout<<"-------------------------"<<endl;
        ans=min(ans,n*c-l);
    }
    cout<<ans<<endl;

    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}