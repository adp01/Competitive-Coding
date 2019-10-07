#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;


#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }


double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}

class PrimePolynom{
    vector <bool> findPrimes(int l){
        vector <bool> p(l+1);
        for(int i=0;i<l+1;i++){
            p[i]=true;
        }
        p[0]=false;
        p[1]=false;
        for(int i=2;i<l+1;i++){
            if(p[i]){

                for(int j=2*i;j<l+1;j+=i){
                    p[j]=false;
                }
            }
        }
        return p;

    }
    public:
    int reveal(int a, int b, int c){
        vector <bool> prime=findPrimes(a*80*80+b*80+c);
        int ans=80;
        for(int i=0;i<=80;i++){
            int f=a*i*i+b*i+c;
            if(f<=0){
                ans=i;
                break; 
            }
            if(!prime[f]){
                ans=i;
                break;
            }
        }
        return ans;

    }

};

// int main(){
//     fastio;

//     #ifndef ONLINE_JUDGE
// 		freopen("in.txt", "r", stdin);
// 	#endif

//     int T;
//     cin>>T;
//     while(T--){
//         int a,b,c;
//         cin>>a>>b>>c;
//         PrimePolynom p;
//         cout<<p.reveal(a,b,c)<<endl;
//     }
//     cout<<"Execution time : "<<tick()<<"\n";

//     return 0;
// }