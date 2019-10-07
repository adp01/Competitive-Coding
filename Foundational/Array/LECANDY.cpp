#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
       int n,c,sum=0;
       cin>>n>>c;
       for(int i=0;i<n;i++){
           int x;
           cin>>x;
           sum+=x;
       } 
       if(sum<=c){
           cout<<"Yes"<<endl;
       }
       else{
           cout<<"No"<<endl;
       }
    }
}