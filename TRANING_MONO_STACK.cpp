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

// MONO Stacck:
// 
// It finds prev/next less/great (basically in monotonous order) ele of each ele in a given vector A in O(n) time
//
// a typical way of solving mono stack prob
//	for(int i = 0; i < A.size(); i++){
//	  while(!in_stk.empty() && in_stk.top() > A[i]){
//	    in_stk.pop();
//	  }
//	  in_stk.push(A[i]);
//	}
//
// we generally push index instead of ele  it helps in avoiding duplicate cases and somtimes to calculate lengths
// 
// prev less ele
//
// previous_less[i] = j means A[j] is the previous less element of A[i].
// previous_less[i] = -1 means there is no previous less element of A[i].
//	vector<int> previous_less(A.size(), -1);
//	for(int i = 0; i < A.size(); i++){
//	  while(!in_stk.empty() && A[in_stk.top()] > A[i]){
//	    in_stk.pop();
//	  }
//	  previous_less[i] = in_stk.empty()? -1: in_stk.top();
//	  in_stk.push(i);
//	}
//
// next less ele
//
// next_less[i] = j means A[j] is the next less element of A[i].
// next_less[i] = -1 means there is no next less element of A[i].
//	vector<int> previous_less(A.size(), -1);
//	for(int i = 0; i < A.size(); i++){
//	  while(!in_stk.empty() && A[in_stk.top()] > A[i]){
//	    auto x = in_stk.top(); in_stk.pop();
//	    next_less[x] = i;
//	  }
//	  in_stk.push(i);
//	}
//
// you can try some other vars like next greater and prev greater
// Just try this one , it contains all varities
// https://leetcode.com/problems/sum-of-subarray-ranges/
void solve(){

}

int main(){
	fastio
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	int t=1;
	cin >> t;
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

