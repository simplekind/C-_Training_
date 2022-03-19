#include <bits/stdc++.h>

#define fli(i,a,b) for(auto i=a;i<b;i++)
#define fld(i,a,b) for(auto i=a;i>=b;i--)
#define llfli(i,a,b) for(auto i=a;i<b;i++)
#define llfld(i,a,b) for(auto i=a;i>b;i--)
#define fla(i,v) for(auto i: v)
#define endln '\n'
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);cout<<fixed;srand(time(0));
#define intu unsigned int
#define inf 0x3f3f3f3f
#define _inf 0xcfcfcfcf
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x,y) cout << #x << " = " << x << " , "<<#y << " = " << y <<endl
#define endln '\n'
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define sortall(x) sort(all(x))
#define vt vector

using namespace std;

typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

int mpow(int base, int exp) ;
int ** newArr(int n,int m)  ;

const int mod = 1000000007;

template <typename t> // cin>> vector<t>
istream &operator>> (istream &istream, vt<t> &v){
	for (auto & i : v) cin>>i;
	return istream;
}

template <typename T> // cout << vector<t>
ostream &operator<<(ostream &ostream, const vector<T> &c){
	for (auto &i : c)
		cout << i << " ";
	return ostream;
}

// Binary shifting
// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
vector<vector<int>> v ;
TreeAncestor(int n, vector<int>& parent) {
    int countBits =  0 ;
    int m = n;
    while(m){
        countBits++;
        m>>=1;
    }
    v.resize(countBits,vector<int> (n,-1));
    // here k' is actually power of kth ancestor of a node i
    // and in v we are storing respective parent present at 2^k = k'
    // here we rep. k' as k in program
    for (int i = 0 ; i<n;i++) 
        v[0][i] = parent[i];
    for (int k = 1 ; k<countBits;k++){
        for (int i =0 ;i<n;i++){
            if(v[k-1][i]!=-1)
                v[k][i] = v[k-1][v[k-1][i]];
        }
    }
}

int getKthAncestor(int node, int k) {
    if(v[0].size()<k) return -1;
    int i = 1,j=0;
    while(i<=k){
        if(k&(i)){
            if(node==-1) return -1;
            node = v[j][node];
        }
        i<<=1;
        j++;
    }
    return node;
}

void solve(){
	
}

int main(){
	fastio
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	int t ; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}


int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

int ** newArr(int n,int m){
	int ** arr = new int* [n] ;
	fli(i,0,m) arr[i] = new int [m];
	return arr ;
}

