#include <bits/stdc++.h>

#define fli(i,a,b) for(auto i=a;i<b;i++)
#define fld(i,a,b) for(auto i=a;i>=b;i--)
#define llfli(i,a,b) for(auto i=a;i<b;i++)
#define llfld(i,a,b) for(auto i=a;i>b;i--)
#define fla(v,i) for(auto i: v)
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

vt <vi> g ;
vpii v;

void dfs(int u){
	
}

// for weighted BFS wont work 
// for unweihted it does
bool bipar(int u=1,int curr_color){
	
}

// dijsktra 
// single source shortest path

// https://www.codechef.com/problems/EVEDG
void solve(){
//	int n, e; cin>>n>>e;
//	g.resize(n+1,vi());
//	vi ans(n+5,1);
//	fli(i,0,e){
//		int u , v;
//		cin>>u>>v;
//		g[u].pb(v);
//		g[v].pb(u);
//	}
//	// Even edges then only 1 min possible subset
//	if(!(e%2)){
//		cout<<1<<endln;
//		fli(i,0,n)
//			cout<<1<<" ";
//		cout<<endln;
//	}else{		// odd edges
//		// count degree for each vertex and store it in v
//		int flag=0;
//		fli(i,1,n+1){
//			// checking if any odd no. of degree
////			deb(g[i].size());
//			if(g[i].size()%2)
//				flag=1;
//			v.pb({i,g[i].size()});
//		}
//		int f1=1,f2=1;
//		if(flag){	// for odd degree inside odd edges
//			for (auto i:v){
//				// odd degree vertex
//				if(i.s%2 &&f1){
//					ans[i.f]=2; f1=0;	// now since odd is covered no need to do it for any other vertex since taking out one odd degree from an odd no. of edges means we have no even. no. of degres in both sub
//				// 2 because now we have put it in 2nd subset
//				}
//				if(i.s==0)
//					ans[i.f]=2;	// this is a case as well
//			}
//		}else{ // for even degree inside odd edges
//			for (auto i:v){
//				if(i.s && f2){ // now we have to remove 2 vertices
//					ans[i.f]=2;	// one vertex without 0 degre
//					ans[g[i.f][0]]=3; // on in neighbour to it 
//					f2=0;
//				}
//				if(i.s==0){
//					ans[i.f]=2;
//				}
//			}
//		}
//		if (flag) cout<<2<<endln; // for min case with atleast 1 odd deg max subset size is 2
//		else cout<<3<<endln; // for min case max subset size is 3
//		fli(i,1,n+1){
//			if(!ans[i]) cout<<1<<" ";
//			else cout<<ans[i]<<" ";
//		}
//		cout<<endln;
//	}

	
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

