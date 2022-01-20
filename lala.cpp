#include <bits/stdc++.h>

#define fli(i,a,b) for(auto i=a;i<b;i++)
#define fld(i,a,b) for(auto i=a;i>=b;i--)
#define llfli(i,a,b) for(auto i=a;i<b;i++)
#define llfld(i,a,b) for(auto i=a;i>b;i--)
#define lltest ll s2; cin>>s2;while(s2--)
#define endln '\n'
#define ll long long
#define ld long double
#define pb push_back
#define popb pop_back
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);cout<<fixed;srand(time(0));
#define intu unsigned int
#define inf 0x3f3f3f3f
#define _inf 0xcfcfcfcf
#define in_arr(a,n) int n ;cin>>n;int a[n];fli(i,0,n)cin>>a[i];
#define in_vec(v,n) int n ;cin>>n;vector<int> v (n);fli(i,0,n)cin>>v[i];
#define cout_arr(a,n)  fli(i,0,n) cout<<a[i]<<" ";
#define for_it(v,it) for (auto it= v.begin(); it!=v.end();it++)
#define deb(x) cout << #x << " = " << x << endl
#define endln '\n'
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define sortall(x) sort(all(x))

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

bool comparator(const vl& a1, const vl& a2){
	return (a1[1] >= a2[1]);
}

void solve(){
	ll n;
	cin>>n;
	vector<vl> stud;
	llfli(i,0,n){
		cin>>stud[i][0];
	}
	llfli(i,0,n){
		cin>>stud[i][1];
	}
	sort(stud.begin(),stud.end(),comparator);
	vector<vl> adj;
	llfli(i,0,n){
		adj[(stud[i][0]-1)].pb(stud[i][1]);
	}
	llfli(i,0,n){
		llfli(j,1,adj[i].size()){
			adj[i][j] += adj[i][j-1];
		}
	}
	vl answer(n,0);
	llfli(i,0,n){
		ll len = adj[i].size();
		llfli(k,1,len){
			ll sub = len % k;
			answer[k-1] += adj[i][len-1-sub];
		}
	}
	llfli(i,0,n){
		cout<<answer[i]<<" ";
	}
	cout<<endln;
}

int main(){
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

