#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;


#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }


double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}

lli sq(int b){
    if(b==1 || b==2 || b==3){
        return 0;
    }
    lli ans=0;
    if(b%2==0){
        ans=sq(b-2)+(b-2)/2;
    }
    else{
        ans=sq(b-3)+(b-2)/2;
    }
    return ans;

}

int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int T;
    cin>>T;
    while(T--){
        int b;
        cin>>b;
        cout<<sq(b)<<endl;

    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}