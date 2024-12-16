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
    string s, ans = "XMAS";
    int ctr = 0;
    vector<string> input;
    while (1) {
        cin >> s;
        if (s == "$") break;
        input.push_back(s);
    }
    // **Part 2**
    //M_S | M_M | S_M | S_S 
    //_A_ | _A_ | _A_ | _A_
    //M_S | S_S | S_M | M_M 
    int rows = input.size();
    int cols = input[0].size();
    fi(i, 1, rows - 1) {
        fi(j, 1, cols - 1) {
            if (input[i][j] == 'A') {
                string a = "", b = "", c = "", d = "";
                a += string(1, input[i + 1][j + 1]) + string(1, input[i + 1][j - 1]);
                b += string(1, input[i - 1][j + 1]) + string(1, input[i - 1][j - 1]);
                c += string(1, input[i + 1][j + 1]) + string(1, input[i - 1][j + 1]);
                d += string(1, input[i + 1][j - 1]) + string(1, input[i - 1][j - 1]);
                if (a == "MM" && b == "SS") ctr++;
                if (b == "MM" && a == "SS") ctr++;
                if (c == "MM" && d == "SS") ctr++;
                if (d == "MM" && c == "SS") ctr++;
                cout << a << " " << b << " " << c << " " << d << nl;
            }
        }
    }
    cout << ctr << nl;
    // **Part 1**
    f(i, input.size()) {
        f(j, input[i].size()) {
            if (input[i][j] == 'X') {
                string a, b, c, d, e, f, g, h;
                if (i < input.size() - 3) {
                    f(k, 4) a += input[i + k][j];
                }
                if (j < input[i].size() - 3) {
                    f(k, 4) b += input[i][j + k];
                }
                if (i < input.size() - 3 && j < input[i].size() - 3) {
                    f(k, 4) c += input[i + k][j + k];
                }
                if (i >= 3) {
                    f(k, 4) d += input[i - k][j];
                }
                if (i >= 3 && j < input[i].size() - 3) {
                    f(k, 4) g += input[i - k][j + k];
                }
                if (j >= 3) {
                    f(k, 4) e += input[i][j - k];
                }
                if (j >= 3 && i < input.size() - 3) {
                    f(k, 4) h += input[i + k][j - k];
                }
                if (i >= 3 && j >= 3) {
                    f(k, 4) f += input[i - k][j - k];
                }
                if (a == ans) ctr++;
                if (b == ans) ctr++;
                if (c == ans) ctr++;
                if (d == ans) ctr++;
                if (e == ans) ctr++;
                if (f == ans) ctr++;
                if (g == ans) ctr++;
                if (h == ans) ctr++;
            }
        }
    }
    cout << ctr << nl;
}
 
signed main(){
    
    init_code();
    
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}