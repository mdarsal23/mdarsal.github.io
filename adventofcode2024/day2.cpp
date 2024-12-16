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
    vvi a;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break; // Stop reading on empty line
        vi row;
        stringstream ss(line);
        int num;
        while (ss >> num) {
            row.pb(num);
        }
        a.pb(row);
    }
    int count = 0;
    f(i,a.size()){
        
        fi(k,0,a[i].size()){
            bool unsafe = false;
            vi v;
            
            f(j,a[i].size()){
                if(j == k) continue;
                v.pb(a[i][j]);
            }
            // print(v);
            bool ascd = false, desc = false;
            int d = abs(v[0] - v[1]);
            if(d<1 || d>3) unsafe = true;
            if(v[0] < v[1]) ascd = true;
            else desc = true;
            // cout<< d <<" "<<ascd<<" "<<desc << nl;
            if(!unsafe){
            fi(j,1,v.size()-1){
                d = abs(v[j] - v[j+1]);
                // cout << d << " ";
                if(d<1 || d>3) unsafe = true;
                else if(v[j] < v[j+1] && desc) unsafe = true;
                else if(v[j] > v[j+1] && ascd) unsafe = true;
                // if(unsafe) break;
            }
            }
            // cout << unsafe << nl;
            if(!unsafe){count++;break;}
        }
        // if(!unsafe)count++;
    }
    cout << count<< nl;
    // ...existing code...
}
 
signed main(){
    
    init_code();
    
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}