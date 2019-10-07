#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef priority_queue<int, vector<int>, greater<int>> min_pq;

const int MOD = 1e9 + 7;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define init(a) memset(a, 0, sizeof(a))
#define pb push_back
#define all(a) a.begin(), a.end()
#define loop(i, n) for (int i = 0; i < n; i++)
#define loops(i, s, n) for (int i = s; i < n; i++)
#define rloop(i, n) for (int i = n - 1; i >= 0; i--)
#define rloops(i, s, n) for (int i = n - 1; i >= s; i--)

#define DEBUG 1
#ifdef DEBUG
#define pf printf
#else
#define pf
#endif

template <typename T>
T gcd(T a, T b)
{
    return (b ? __gcd(a, b) : a);
}
template <typename T>
T lcm(T a, T b) { return (a * b) / gcd(a, b); }

double tick()
{
    static clock_t oldt, newt = clock();
    double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
    oldt = newt;
    return diff;
}
//---------------------------------------------------------------------------------------------
const int MAXN = 2 * 1e5 + 5;
int st[4 * MAXN];
int a[MAXN];
int n;

void update(int pos, int val,  int node = 1, int l = 0, int r = n-1){
    if(l == r){
        st[node] = val;
        return;
    }
    int m = (l+r) / 2;

    if(pos <= m){
        update(pos, val,  2*node, l, m);
    }
    else{
        update(pos, val,  2*node + 1, m + 1, r);
    }
    st[node] = st[2* node] + st[2 * node + 1];

}

int query(int x, int y, int node = 1,int l = 0,int r = n-1){
    // cout<< l<<" "<< r <<endl;
    if(l > y || r < x){
        return 0;
    }
    if(l >= x && r <= y){
        return st[node];
    }

    int m = (r + l) / 2;

    return query(x, y, 2 * node, l, m) + query(x, y, 2 * node + 1, m + 1, r);
}

int ksmall(int k, int node = 1,int l = 0,int r = n-1){
    if(l == r){
        return l;
    }
    int m = (l + r ) / 2;
    if(k <= st[2 * node]){
       return ksmall(k, 2* node, l , m);
    }
    else{
        return ksmall( k - st[2 * node], 2 * node + 1 , m + 1, r);
    }
}

int main()
{

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif

    n = 0;
    int q;
    cin >> q;
    vector < pair<char, int> > queries(q);

    loop(i,q){
        cin>> queries[i].first >> queries[i].second;
    }

    set <int> s;
    loop(i, q){
        if(queries[i].first != 'K' && queries[i].first != 'D'){
            s.insert(queries[i].second);
        }
    }

    unordered_map <int, int> m;
    set<int> :: iterator it = s.begin();
    while(it != s.end()){
        m[*it] = n;
        a[n] = (*it);
        // cout<<a[n]<<endl;
        n++;
        it++;
    }


    loop(i,q){
        switch(queries[i].first){
            case 'I':{
                update(m[queries[i].second], 1);
                break;
            }
            case 'D':{
                if(m.find(queries[i].second) != m.end()){
                    update(m[queries[i].second], 0);
                }
                break;
            }
            case 'K':{
                int k = queries[i].second;
                if(k > st[1]){
                    cout << "invalid" << endl;
                }
                else{
                    int pos = ksmall(k);
                    cout<< a[pos] << endl;
                }
                break;

            }
            case 'C':{
                int pos = m[queries[i].second] - 1;
                if(pos < 0){
                    cout<< 0 <<endl;
                }
                else{
                    cout << query(0, pos) << endl;
                }
                // cout<<pos <<endl;
               break;
            }
        }
    }

    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}