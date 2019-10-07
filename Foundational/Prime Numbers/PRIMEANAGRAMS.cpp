#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;


#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }


double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}

class PrimeAnagrams{
    public:
    vector<int> primes(string s){
        sort(s.begin(),s.end(),greater<char>() );
        int lim=stoi(s.substr(0,s.length()-2));
        bool primes[lim+1];
        for(int i=0;i<=lim;i++){
            primes[i]=true;
        }
        primes[0]=false;
        primes[1]=false;
        for(int i = 2; i < lim+1; i++){
            if(primes[i]){
                for(int j=2*i;j<=lim+1;j+=i){
                    primes[j]=false;
                }
            }
        }
        sort(s.begin(),s.end());
        int product=INT_MAX;
        vector<int> ans;
        do{
            for(int i=1;i<=s.length()-2;i++){
                int p1=stoi(s.substr(0,i));
                if(!primes[p1]||s[0]=='0'){
                    continue;
                }
                for(int j=1;j<=s.length()-i-1;j++){
                    int p2=stoi(s.substr(i,j));
                    if(!primes[p2]||s[i]=='0'){
                        continue;
                    }
                    int p3=stoi(s.substr(i+j,s.length()-i-j));
                    if(!primes[p3]||s[i+j]=='0'){
                        continue;
                    }
                    if(p1*p2*p3<product){
                        product=p1*p2*p3;
                        if(ans.size()!=0){
                            ans[0]=p1;
                            ans[1]=p2;
                            ans[2]=p3;
                        }
                        else{
                            ans.push_back(p1);
                            ans.push_back(p2);
                            ans.push_back(p3);
                        }
                    }
                }
                
            }
        }while(next_permutation(s.begin(),s.end()));
        sort(ans.begin(),ans.end());
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
//     PrimeAnagrams p;
//     while(T--){
//         string s;
//         cin>>s;
//         vector <int> a=p.primes(s);
//         if(a.size()!=0)
//         cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
//     }
//     cout<<"Execution time : "<<tick()<<"\n";

//     return 0;
// }