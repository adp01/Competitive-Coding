#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;


#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    string s;
    cin>>s;
    stack <char> t;
    queue <char> u;
    int k=s.length()-1;
    int l[26]={0};
    for(int i=0;i<s.length();i++){
        l[s[i]-'a']++;
    }
    for(int i=0;i<s.length();i++){
        t.push(s[i]);
        l[s[i]-'a']--;
        int m=-1;
        for(int j=0;j<26;j++){
            if(l[j]>0){
                m=j;
                break;
            }
        }
        if(m!=-1){
            while(!t.empty() && t.top()-'a'<=m){
                u.push(t.top());
                t.pop();
            }
        }

    }
    while(!t.empty()){
        u.push(t.top());
        t.pop();
    }
    while(!u.empty()){
        cout<<u.front();
        u.pop();
    }
    cout<<endl;
    
    
    return 0;
}