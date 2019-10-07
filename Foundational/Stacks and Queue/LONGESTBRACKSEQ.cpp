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
    int ml=0,c=1,b;
    for(int i=0;i<s.length();i++){
        int l=0;
        b=i;
        stack <int> st;
        for(int j=i;j<s.length();j++){
            if(s[j]=='('){
                st.push(j);
            }
            else{
                if(st.empty()){
                    i=j;
                    break;
                }
                else{
                    st.pop();
                    l+=2;
                }
            }
            i=j;
        }
        if(st.empty()){
            if(ml<l){
                ml=l;
                c=1;
            }
            else if(ml==l && l!=0){
                c++;
            }
        }
        else{
            int k=i;
            while(!st.empty()){
                int l1=k-st.top();
                k=st.top()-1;
                st.pop();
                if(ml<l1){
                    ml=l1;
                    c=1;
                }
                else if(ml==l1 && l1!=0){
                    c++;
                }

            }
            int l1=k-b;
            if(ml<l1){
                ml=l1;
                c=1;
            }
            else if(ml==l1 && l1!=0){
                c++;
            }
            
        }
        
    }
    cout<<ml<<" "<<c<<endl;
    return 0;
}