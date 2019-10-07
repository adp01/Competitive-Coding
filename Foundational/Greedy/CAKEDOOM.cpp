#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;


#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }


double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}


int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int T;
    cin>>T;
    while(T--){
        int k;
        string s;
        cin>>k>>s;
        int flag=0;
        int n=s.length();
        if((s[0]==s[n-1] ||s[0]>=k+'0') && s[0]!='?' && n!=1){
            cout<<"NO"<<endl;
        }
        else{
            for(int i=1;i<n;i++){
                if((s[i]==s[i-1] || s[i]==s[(i+1)%n] || s[i]>=k+'0')&&s[i]!='?'){
                    flag=1;
                    break;
                }
            }
            if(flag==0 && k==2){
                if(n%2==1){
                    flag=1;
                }
                else{
                    int i;
                    for(i=0;i<n;i++){
                        if(s[i]!='?'){
                            break;
                        }
                    }
                    if(i<n){
                        if()
                    }
                }
            }
            if(flag==0 && s[0]=='?'){
                    if(n==1){
                        s[0]='0';
                    }
                    else{
                        int j;
                        for(j=0;j<k;j++){
                            if(j+'0'==s[1]||j+'0'==s[n-1]){
                                continue;
                            }
                            else{
                                s[0]=j+'0';
                                break;
                            }
                        }
                        if(j==k){
                            flag=1;
                        }
                    }
            }
            for(int i=1;i<n&&flag==0;i++){
                if(s[i]=='?'){
                    int j;
                    for(j=0;j<k;j++){
                        if(j+'0'==s[i-1]||j+'0'==s[(i+1)%n]){
                            continue;
                        }
                        else{
                            s[i]=j+'0';
                            break;
                        }
                    }
                    if(j==k){
                        flag=1;
                        break;
                    }
                }
                
            }
            if(flag==1){
                cout<<"NO"<<endl;
            }
            else{
                cout<<s<<endl;
            }
        }
        
    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}