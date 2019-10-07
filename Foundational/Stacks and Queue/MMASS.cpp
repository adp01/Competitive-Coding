#include <bits/stdc++.h>
using namespace std;

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }
pair<int,int> calc_mass(string f,int st){
    pair<int,int> a;
    a.first=0;
    int lm=0;
    for(int i=st;i<f.length();i++){
        if(f[i]=='C'){
            a.first+=12;
            lm=12;
        }
        else if(f[i]=='H'){
            lm=1;
            a.first+=1;
        }
        else if(f[i]=='O'){
            a.first+=16;
            lm=16;
        }
        else if(f[i]=='('){
            pair <int,int> u;
            u=calc_mass(f,i+1);
            i=u.second;
            a.first+=u.first;
            lm=u.first;
        }
        else if(f[i]==')'){
            a.second=i;
            return a;
        }
        else if(f[i]>'1' && f[i]<='9'){
            a.first+=lm*(f[i]-'0'-1);
        }
    }
    return a;
}
int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    string f;
    cin>>f;
    pair <int,int> a=calc_mass(f,0);
    cout<<a.first<<endl;
    
    return 0;
}