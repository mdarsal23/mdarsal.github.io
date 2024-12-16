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
    // part1
    // string str[6];
    string s;
    cin >> s;
    // f(i,6){
    //     cin >> s;
    //     str[i] = s;
    // }
    long long ans = 0,f=0;
    // vl ok;
    // f(j,6){
    f(i,s.size()){
        if(s[i] == 'm'){
            string a = s.substr(i, 4);
            if(a == "mul("){
                int j = i + 4;
                string num1, num2;
                while(j < s.size() && isdigit(s[j])) {
                    num1 += s[j++];
                }
                if(j < s.size() && s[j] == ',') {
                    j++;
                    while(j < s.size() && isdigit(s[j])) {
                        num2 += s[j++];
                    }
                    if(j < s.size() && s[j] == ')') {
                        int n1 = stoi(num1);
                        int n2 = stoi(num2);
                        ans+= (n1 * n2);
                    }
                }
            }
        }
    // }
    // cout << ans << nl;
    f+=ans; 
    }
    cout << ans;
}

 
signed main(){
    
    init_code();
    long long ans=0;
    int t = 1;
    // string s="",str="";
    // cin >> t;
    while(t--){;
        solve();
    }
    
}