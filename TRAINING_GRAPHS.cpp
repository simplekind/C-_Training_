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

// ALL in all there are 4 reps of graphs
//
// As vector 			Space		Check edge u and v		Iterate over edges incident 
//																  to v
//
// list of edges :		  E					E						E
// adj matrix    :		  V^2				1						V
// adj list		 :		  E+v		 Incoming Edges of v	 Incoming Edges of v
// adj set		 :		  E+V		 log (Inc Edges of v)	 Incoming Edges of v
//
//
// GRAPH ALGOS
//
//  Graph traversal
//
//	Breadth First Search
//	Depth First Search
//	Connected components, bridges, articulations points
//	Finding Connected Components
//	Finding Bridges in O(N+M)
//	Finding Bridges Online
//	Finding Articulation Points in O(N+M)
//	Strongly Connected Components and Condensation Graph
//	Strong Orientation
//	Single-source shortest paths
//	Dijkstra - finding shortest paths from given vertex
//	Dijkstra on sparse graphs
//	Bellman-Ford - finding shortest paths with negative weights
//	0-1 BFS
//	D´Esopo-Pape algorithm
//	All-pairs shortest paths
//	Floyd-Warshall - finding all shortest paths
//	Number of paths of fixed length / Shortest paths of fixed length
//	Spanning trees
//	Minimum Spanning Tree - Prim's Algorithm
//	Minimum Spanning Tree - Kruskal
//	Minimum Spanning Tree - Kruskal with Disjoint Set Union
//	Second best Minimum Spanning Tree - Using Kruskal and Lowest Common Ancestor
//	Kirchhoff Theorem
//	Prüfer code
//	Cycles
//	Checking a graph for acyclicity and finding a cycle in O(M)
//	Finding a Negative Cycle in the Graph
//	Eulerian Path
//	Lowest common ancestor
//	Lowest Common Ancestor
//	Lowest Common Ancestor - Binary Lifting
//	Lowest Common Ancestor - Farach-Colton and Bender algorithm
//	Solve RMQ by finding LCA
//	Lowest Common Ancestor - Tarjan's off-line algorithm
//	Flows and related problems
//	Maximum flow - Ford-Fulkerson and Edmonds-Karp
//	Maximum flow - Push-relabel algorithm
//	Maximum flow - Push-relabel algorithm improved
//	Maximum flow - Dinic's algorithm
//	Maximum flow - MPM algorithm
//	Flows with demands
//	Minimum-cost flow
//	Assignment problem. Solution using min-cost-flow in O (N^5)
//	Matchings and related problems
//	Bipartite Graph Check
//	Kuhn's Algorithm - Maximum Bipartite Matching
//
//	Miscellaneous
//		Topological Sorting
//		Edge connectivity / Vertex connectivity
//		Tree painting
//		2-SAT
//		Heavy-light decomposition
//
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

