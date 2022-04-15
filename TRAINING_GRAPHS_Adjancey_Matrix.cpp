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

// adjancey matrix
// time proportional to V2, thats why its for dense graph
// no parallel edges but self loops

class DenseGraph{
	int v;
	int e;
	bool digraph ;
	vt<vt<bool>> adj ; // The value Adj[u, v] is set to 1 if there is an edge from vertex u to vertex v and 0 otherwise
				 // To save time, we can process only half of this symmetric matrix.
	public:
		DenseGraph(int v, bool digraph = 0) : v(v),e(0),digraph(digraph){
			adj.resize(v,vt<bool> (v,0));
		}
		
		int getV() const{
			return v;
		}
		
		int getE() const{
			return e;
		}
		
		bool isDirected() const{
			return digraph;
		}
		
		void insert (int u , int v){
			if(!adj[u][v])
				e++;
			adj[u][v] =1;
			if(!digraph)
				adj[v][u] =1;
		}
		
		void remove(int u , int v){
			if(adj[u][v])
				e--;
			adj[u][v]=0;
			if(!digraph)
				adj[v][u]=0;
		}
		
		bool edge (int u , int v) const{
			return adj[u][v];
		}
		
		class adjit;
		friend class adjit;
};

// an iterator to iterate over edges in order they appear in adjancey matrix
class DenseGraph :: adjit{
	const DenseGraph & g;
	int i ;
	int v ;
	public :
		adjit(const DenseGraph & g, int v):g(g),v(v),i(-1){}
		
		int nxt(){
			for (i++;i<g.getV();i++)
				if(g.adj[v][i])
					return i;
			return -1;
		}
		
		int beg(){
			i=-1;
			return  nxt();
		}
		
		bool end(){
			return i>=g.getV();
		}
};

// for sparse graphs , V^2 is large compared to V+E then we prefer using
// adjancey lists

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
