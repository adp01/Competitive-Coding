#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;


#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }


double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}

int maxUse(int l,int r,int tl){
    // cout<<l<<" "<<r<<endl;
    if(r-l<=1){
        return 0;
    }
    int m=0;
    for(int i=l+1;i<=(l+r)/2;i++){
        int len=maxUse(l,i,tl)+maxUse(i,r,tl)+(i-l)+(r-i);
        if(len>tl){
            continue;
        }
        else{
            m=max(len,m);
        }
    }
    return m;
}
int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        int ml=maxUse(0,n+1,m);
        // cout<<ml<<endl;
        if(ml==0){
            cout<<-1<<endl;
        }
        else{
            cout<<(m-ml)<<endl;
        }
    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}