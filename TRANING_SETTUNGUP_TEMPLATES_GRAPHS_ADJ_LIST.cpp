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

#define forll(h,i) for (link i = head;i!=0;i=i->nxt)
#define null nullptr

struct edge{
	int v;
	int w;
	edge(int v,int w){
		this->v=v;
		this->w=w;
	}
	edge(int v){
		this->v=v;
	}
	edge(){}
};

ostream &operator<<(ostream &ostream, const edge &e){
	cout<<e.v;
	return ostream;
}

template <typename Item>
struct node {		// linked list node
	Item item ;
	node *nxt ;
	node (Item item , node *t ){
		this->item =item;
		(*this).nxt = t ;
	}
};

template <typename Item>
using link = node<Item>* ;

template <typename Item>
void insertAt (link<Item>& head ,Item item,int pos){
	link<Item> temp = new node<Item> (item,0);
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
}

class graph{
	int v;
	int e;
	bool digraph ;
	public:
		vt<link<edge>> adj;
		graph(int v, bool digraph = 0) : v(v),e(0),digraph(digraph){
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
			this->e ++;
			edge e(v) ;
			insertAt(adj[u],e,1);
			if(!digraph)
				e.v=u;
				insertAt(adj[v],e,1);
		}
		
		void remove(int u , int v){
			link<edge> curr = adj[u];
			while(curr->nxt!=null && curr->nxt->item.v!=v)
				curr=curr->nxt;
			if(curr->nxt==null)
				return ;
			link<edge> temp = curr->nxt->nxt;
			curr->nxt->nxt=null;
			curr->nxt=temp;
			if(!digraph){
				curr = adj[v];
				while(curr->nxt!=null && curr->nxt->item.v!=u)
					curr=curr->nxt;
				if(curr->nxt==null)
					return ;
				link<edge> temp = curr->nxt->nxt;
				curr->nxt->nxt=null;
				curr->nxt=temp;
			}
		}
		
		bool isEdge (int u , int v) const{
			link <edge> curr = adj[u];
			while(curr!=null && curr->item.v!=v)
				curr=curr->nxt;
			if(curr==null)
				return 0;
			return 1;
		}
};

void solve(){
	graph g(6);
	g.insert(0,1);
	g.insert(0,2);
	g.insert(1,3);
	g.insert(2,3);
	g.insert(3,4);
	g.insert(3,5);
	g.insert(4,5);
	for (int i =0 ;i< g.getV();i++)
		cout<<i<< ": ",
		printList(g.adj[i]),
		cout<<endln;
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
