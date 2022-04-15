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

#define forll(h,i) for (link i = head;i!=0;i=i->nxt)
#define null nullptr

template <typename Item>
struct node {
	Item item ;
	node *next ;
	node (Item item , node *t ){
		this->item =item;
		(*this).next = t ;
	}
};

template <typename Item>
using link = node<Item>* ;

template <typename Item>
void insertAt (link<Item>& head ,link<Item> temp,int pos){
	if(pos==1){
		temp->nxt = head ;
		head = temp ;
		return ;
	}
	link<Item> curr = head ;
	for (int i =0;i<pos-2;i++){
		curr= curr->nxt  ;
		if(pos!=i+3 && curr->nxt == NULL ){
			cout<<"Memory Overflow"<<endl;
			return ;
		}
	}
	temp->nxt = curr->nxt ;
	curr->nxt = temp ;
}

template <typename Item>
void printList(link<Item> head){
	if(head ==null){
		cout<<"Linked List is empty"<<endln;
		return ;
	}
	link<Item> curr = head ;
	while(curr!=NULL){
		deb(curr->item);
		curr = curr->nxt ;
	}
}

template <typename Item>
void delList(link<Item>& head ,int pos){
	if(pos==1){
		link<Item> temp = head ;
		head = head->nxt;
		delete temp ;
		return ;
	}
	link<Item> curr = head ;
	fli(i,0,pos-2){
		curr= curr->nxt ;
		if(curr==null && i!=pos-3){
			cout<<"Memory Overflow"<<endln;
			return;
		}
	}
	link<Item> temp = curr->nxt ;
	curr->nxt=curr->nxt->nxt;
	delete temp ;
}

template <typename Item>
void delSinglyLinkedList(link<Item>& head ){
	while( head !=null){
		link <Item> temp = head ;
		head = head->nxt ;
		delete temp ;
	}
}//~\\
09/04/22 11:30

// adjancey lists
// time proportional to V+E, thats why its for sparse graph

class SparseGraph{
	int v;
	int e;
	bool digraph ;
	vt<link<int>> adj;
	public:
		SparseGraph(int v, bool digraph = 0) : v(v),e(0),digraph(digraph){
			adj.resize(v,null);
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
			adj[u] = new node<int>(v,adj[u]);
			if(!digraph)
				adj[v] = new node<int>(u,adj[v]);
		}
		
		void remove(int u , int v){
			link<int> curr = adj[u];
			while(curr->next!=null && curr->next->item!=v)
				curr=curr->next;
			if(curr->next==null)
				return ;
			link<int> temp = curr->next->next;
			curr->next->next=null;
			curr->next=temp;
			if(!digraph){
				curr = adj[v];
				while(curr->next!=null && curr->next->item!=u)
					curr=curr->next;
				if(curr->next==null)
					return ;
				link<int> temp = curr->next->next;
				curr->next->next=null;
				curr->next=temp;
			}
		}
		
		bool edge (int u , int v) const{
			link <int> curr = adj[u];
			while(curr!=null && curr->item!=v)
				curr=curr->next;
			if(curr==null)
				return 0;
			return 1;
		}
		
		class adjit;
		friend class adjit;
};

// an iterator to iterate over edges in order they appear in adjancey matrix
class SparseGraph:: adjit{
	const SparseGraph & g;
	int v ;
	link<int> i ;
	public :
		adjit(const SparseGraph& g, int v):g(g),v(v),i(null){}
		
		int nxt(){
			if(i!=null)
				i=i->next;
			return i!=null ? i->item : -1;
		}
		
		int beg(){
			i=g.adj[v];
			return i!=null ? i->item : -1;
		}
		
		bool end(){
			return i==null;
		}
};

//The primary advantage of the adjacency-lists representation over the
//adjacency-matrix representation is that it always uses space proportional to
//E + V, as opposed to V2 in the adjacency matrix

//The primary disadvantage
//is that testing for the existence of specific edges can take time proportional
//to V, as opposed to constant time in the adjacency matrix.

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
