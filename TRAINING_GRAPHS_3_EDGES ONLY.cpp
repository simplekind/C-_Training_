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
#define fastio ios_base::sync_with_stdio(0);cout.tie(NULL);cin.tie(NULL);cout<<fixed;srand(time(0));
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

class Graph{
    int V;
    list< pair<int, int> > *adj;
	public:
    	Graph(int V);  // Constructor
	    void addEdge(int u, int v, int w);
    	void primMST();
};
 
// Allocates memory for adjacency list
Graph::Graph(int V){
    this->V = V;
    adj = new list<pii> [V];
}
 
void Graph::addEdge(int u, int v, int w){
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 
void Graph::primMST(){
 	vpii v2, v5 , v7;
    int src = 0; // Taking vertex 0 as source
    // Create a vector for keys and initialize all
    // keys as infinite (INF)
    vector<int> key(V, inf);
    // To store parent array which in turn store MST
    vector<int> parent(V, -1);
    // To keep track of vertices included in MST
    vector<bool> inMST(V, false);
    // Insert source itself in priority queue and initialize
    // its key as 0.
    v2.push_back({0,src});
    key[src] = 0;
    /* Looping till priority queue becomes empty */
    while (v2.size() || v5.size() || v7.size() ){
        int u;
		if(v2.size())
			u = v2.back().second,
        	v2.pop_back();
		else if (v5.size())
			u = v5.back().second,
        	v5.pop_back();
		else 
			u = v7.back().second,
        	v7.pop_back();
        if(inMST[u] == true){
            continue;
        }
        inMST[u] = true;  // Include vertex in MST
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i){
            int v = (*i).first;
            int weight = (*i).second;
            if (inMST[v] == false && key[v] > weight){
                key[v] = weight;
                if(weight==2)
                	v2.push_back(make_pair(key[v], v));
                else if (weight==5)
                	v5.push_back(make_pair(key[v], v));
                else 
                	v7.push_back(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    // Print edges of MST using parent array
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
}

void solve(){
	int V = 9;
    Graph g(V);
 
    //  making above shown graph
    g.addEdge(0, 1, 2);
    g.addEdge(0, 7, 2);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 7, 5);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, 7);
    g.addEdge(3, 5, 7);
    g.addEdge(4, 5, 5);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 7);
    g.addEdge(6, 8, 5);
    g.addEdge(7, 8, 7);
    g.primMST();
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

