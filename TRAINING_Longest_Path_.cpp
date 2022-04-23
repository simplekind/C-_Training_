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

struct Edge {
    int src, dest;
};
 
class Graph{
public:
    vector<vector<int>> adjList;
    Graph(vector<Edge> const &edges, int n){
        adjList.resize(n);
        for (const Edge &edge: edges){
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};
 
class DiGraph{
public:
    vector<vector<int>> adjList;
    DiGraph(vector<Edge> const &edges, int n){
        adjList.resize(n);
        for (const Edge &edge: edges){
            adjList[edge.src].push_back(edge.dest);
        }
    }
};
 
vector<Edge> convert(Graph const &graph, int n, int s,vi D){
    vector<Edge> edges;
    vector<bool> vis(n);
    vis[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()){
        s = q.front();
        q.pop();
        for (int u: graph.adjList[s]){
            if (!vis[u] ){
                vis[u] = true;
                if(D[v]-D[u]>=0)
                	edges.push_back({u, v}),
	                q.push(u);
                else
                	edges.push_back({v, u}),
    	            q.push(v);
            }
        }
    }
    return edges;
}

void dfs(int node, vector<vi> adj, int dp[], bool vis[]){
    vis[node] = true;
    for (int i = 0; i < adj[node].size(); i++){
        if (!vis[adj[node][i]])
            dfs(adj[node][i], adj, dp, vis);
        dp[node] = max(dp[node], 1 + dp[adj[node][i]]);
    }
}

int findLongestPath(vector<vi> adj, int n,int s){
    int dp[n + 1];
    memset(dp, _inf, sizeof dp);
    dp[s]=0;
    bool vis[n + 1];
    memset(vis, false, sizeof vis);
    for (int i = s; i < n; i++){
        if (!vis[i])
            dfs(i, adj, dp, vis);
	}
	for (int i = s-1; i >=0; --i){
        if (!vis[i])
            dfs(i, adj, dp, vis);
	}
	int ans = 0;
    for (int i = 0; i <n; i++){
        ans = max(ans, dp[i]);
	}
    return ans;
}

void solve(){
	vector<Edge> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}};
    int n = 6;
    int s= 2;
    Graph graph(edges, n);
    edges = BFS(graph, n, s);
    DiGraph digraph(edges, n);
 	vt<vi> adj = digraph.adjList;
    cout<<findLongestPath(digraph.adjList,n,s)<<endln;
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

