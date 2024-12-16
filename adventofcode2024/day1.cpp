#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
using pi=pair<int,int>;
using vi=vector<int>;
using vc=vector<char>;
using vl=vector<ll>;
using vvi=vector<vi>;
 
#define int ll
#define all(c) c.begin() , c.end()
#define f(i,n) for(int i=0 ; i < n ; i++) 
#define fi(i,x,n) for(int i = x ; i < n ; i++)
#define nl '\n'
#define pb push_back
#define t(it,v) for(auto it : v)
#define rall(c) c.rbegin() , c.rend()
#define band bit_and<int>()
#define bor bit_or<int>()
#define bnot bit_not<int>()
#define print(v) for(auto it: v) cout << it << " " ; cout << nl;

void init_code(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
void print_with_map(vi v, unordered_map <int,int> mp)
{
    for(auto it : v) cout << it << " " << mp[it] << nl;
}

void solve()
{
    //part2
    int n,m;
    vi a,b;
    do{
        cin >> n; if(n == -1) break;
        a.pb(n);
        cin >> m; b.pb(m);
    }while(m != -1 || n != -1);
    unordered_map <int,int> mp;
    f(i,a.size())
    {
        mp[b[i]]++;
    }
    int ans = 0;
    t(it,a)
    {
        ans += it*mp[it];
    }
    cout << ans << nl;
}
 
signed main(){
    
    init_code();
    
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}