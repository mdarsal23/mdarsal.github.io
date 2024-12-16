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
 
void print_with_map(vi v, unordered_map <int,vi> mp)
{
    for(auto it : v) {
        cout << it << ": " ;
        print(mp[it]);
    }
}

void solve()
{
    //Part 1 && part 2
    int n, m, incorrect = 0, sum=0;
    vi a;
    cout << "entering loop" << nl;
    unordered_map <int,vi> mp;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break;
        size_t pos = line.find('|');
        if (pos != string::npos) {
            try {
                int m = stoi(line.substr(0, pos));
                int n = stoi(line.substr(pos + 1));
                a.pb(n);
                mp[n].pb(m);
            } catch (const invalid_argument& e) {
                cerr << "Invalid input: " << line << nl;
            } catch (const out_of_range& e) {
                cerr << "Out of range input: " << line << nl;
            }
        } else {
            cerr << "Invalid format: " << line << nl;
            break;
        }
    }
    cout << nl;
    // print_with_map(a,mp);
    vvi ab;
    // string line;
    while (getline(cin, line)) {
        if (line.empty()) break; // Stop reading on empty line
        stringstream ss(line);
        string number;
        vi list;
        while (getline(ss, number, ',')) {
            try {
                list.pb(stoi(number));
            } catch (const invalid_argument& e) {
                cerr << "Second loop " << number << nl;
            } catch (const out_of_range& e) {
                cerr << "Out of range input: " << number << nl;
            }
        }
        // Print the list
        ab.pb(list);
    }
    cout << "out of loop"<< nl;
    // f(i,ab.size()){
    //     f(j,ab[i].size()){
    //         cout << ab[i][j] << " ";
    //     }
    //     cout << nl;
    // }
    t(it,a){
        sort(all(mp[it]));
    }
    bool mark = false;
    // print_with_map(a,mp);
    f(i,ab.size()){
        mark = false;
        f(j,ab[i].size()){
            incorrect = 0;
            fi(k,j+1,ab[i].size()){
                if(binary_search(all(mp[ab[i][j]]),ab[i][k])){
                    swap(ab[i][j],ab[i][k]);
                    mark = true;
                    // cout << "here"<<nl;
                    incorrect=1;
                    // j = ab[i].size();
                    // break;
                }
            }
        }
        // cout << incorrect << nl;
        if(mark) {
            sum+= ab[i][ab[i].size()/2];
            // cout << ab[i][ab[i].size()/2] << nl;
        }
        if(incorrect==0){
            // sum+= ab[i][ab[i].size()/2];  // part1
            // cout << ab[i][ab[i].size()/2] << nl;
        }
    }
    cout << sum << nl;

}
 
signed main(){
    
    init_code();
    
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}