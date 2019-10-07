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

    int k;
    cin>>k;
    while(k){
        string s1,s2;
        cin>>s1>>s2;
        int l1=s1.length();
        int l2=s2.length();
        if(l1<k || l2<k){
            cout<<0<<endl;
            cin>>k;
            continue;
        }
        int r=l1-k+1;
        int c=l2-k+1;
        vi dp[r];
        loop(i,r){
            loop(j,c){
                dp[i].pb(0);
            }
        }
        rloop(i,r){
            string sub1;
            sub1=s1.substr(i,k);
            rloop(j,c){
                string sub2;
                sub2=s2.substr(j,k);
                if(i+1<r && j+1<c){
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
                else if(i+1<r){
                    dp[i][j]=dp[i+1][j];
                }
                else if(j+1<c){
                    dp[i][j]=dp[i][j+1];
                }
                if(sub1==sub2){
                    int l=k-1;
                    if(i+k<r && j+k<c){
                        l=k;
                    }
                    else{
                        while(i+l<l1 && j+l<l2 && s1[i+l]==s2[j+l]){
                            l+=1;
                            if(i+l>=l1 || j+l>=l2){
                                break;
                            }
                        }
                    }
                    if(i+l<r && j+l<c){
                        dp[i][j]=max(dp[i][j],dp[i+l][j+l]+l);
                    }
                    else{
                        dp[i][j]=max(dp[i][j],l);
                    }
                }
            }
        }
        // loop(i,r){
        //     loop(j,c){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        cout<<dp[0][0]<<endl;

        cin>>k;
        // cout<<"K: "<<k<<endl;

    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}