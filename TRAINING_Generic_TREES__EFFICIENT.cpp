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

#define null nullptr
template <typename t>
struct node {
	t item ;
	node* firstChild , *nxtSib;
	node (){
		this->firstChild=null;
		this->nxtSib=null;
	}
	node(t item , node*l, node*r){
		this->item=item;
		this->firstChild=l;
		this->nxtSib=r;
	}
};

// This is kind of generic tree represn where
// parent has first child and other children are 
// linked with first child in a linked list manner
// eg:
// 					1
//			      / | \
//				2   3  4
//					|   \
//					5    8
//				   / \
//				  6   7
// can be:
//
//					1
//				    |
//					2 -> 3 -> 4
//						 |    |
//						 |	  8    
//						 5
//						 | 
//						 6 -> 7
 
// So these can be solved by repalcing left and right
// pointers from tree with firstChild and nxtSibling
// pointers

// stacks and level order traversals used queues as an auxiliary data structure. 
// We can alternatively use traversal algorithms which do not need both stacks and queues.
// called as threaded binary tree traversals or stack/queue – less traversals

// But why do we need them without stacks/queues?
// The storage space required for the stack and queue is large.
// The majority of pointers in any binary tree are NULL. For example, a binary tree
// with n nodes has n + 1 NULL pointers and these were wasted.
// It is difficult to find successor node (preorder, inorder and postorder successors) for a given node.


// SOLUTION :-
// THREADED BINARY TREES
// 	If we observe the previous traversals carefully, stack/ queue is required because we have to record the
//	current position in order to move to the right subtree after processing the left subtree. 
//	If we store the useful information in NULL pointers, then we don’t have to store such information in stack/queue.
//	Such tree is called threaded binary trees.
//	So in NULL Nodes we will be storing predecessor.succesor info
// 	eg: 
// 	While Preorder traversals
//	NULL left pointer will contain preorder
//	predecessor information and NULL right pointer will contain preorder successor information.
//	These special pointers are called threads
//	If only left then left threaded BT
//	If only right then right threaded BT
//	If both then fully/simply threaded BT

// MORRIS INORDER TRAVERSAL

template< typename t>
using link = node<t> *;

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

