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
int ** newArr(int n,int m)  ;

const int mod = 1000000007;

//For the purpose of binary searhces we need items to be in sorted order
//If we need to insert new items dynamically in it, it seems that we need
//a LL, but a singly LL does not lead to an efficient implementation, because 
//the efficiency of binary search depends on our ability to get to the middle 
//of any subarray quickly via indexing, and the only way to get to the middle 
//of a singly linked list is to follow links.

//binary search tree (BST) is a binary tree that has
//a key associated with each of its internal nodes, with the additional
//property that the key in any node is larger than (or equal to) the keys
//in all nodes in that node’s left subtree and smaller than (or equal to)
//the keys in all nodes in that node’s right subtree.

#define null nullptr
template <typename t>
struct node {
	t item ;
	node* l , *r;
	node (){
		this->l=null;
		this->r=null;
	}
	private:
		node* searchHelper(node* head,t x){
			if(head==null) return null;
			if(head->item==x) return head;
			else if(head->item < x ) return searchHelper(head->r,x);
			else if(head->item > x ) return searchHelper(head->l,x);
		}
		
		node* insertHelper(node* head , t x){
			if(head==null) {
				node* curr = new node(x,0,0);
				return curr;				
			}
			else if(head->item<x) {
				head->r=insertHelper(head->r,x);
			}else{
				head->l=insertHelper(head->l,x);				
			}
			return head;			
		}
		
		void inorderHelper(node* head){
			if(head==null) return;
			inorderHelper(head->l);
			deb(head->item);
			inorderHelper(head->r);
		}
		
		node* maxHelper (node* head){
			if(head==null) return null;
			while(head->r!=null){
				head=head->r;
			}
			return head;
		}
		
		node* minHelper (node* head){
			if(head==null) return null;
			while(head->l!=null){
				head=head->l;
			}
			return head;
		}
		
	public:
		node(t item , node*l, node*r){
			this->item=item;
			this->l=l;
			this->r=r;
		}

		node* search(t x){
			return searchHelper(this,x) ;
		}
		void insert(t x){
			insertHelper(this,x);
		}
		
		void inorder(){
			inorderHelper(this);
		}
		
		node* max(){
			return maxHelper(this);
		}

		node* min(){
			return minHelper(this);
		}
		
		void printNode(char x,int h){
			fli(i,0,h) cout<<"	 ";
			cout<<((int)(x)==46?-1:x)<<endln;
		}
		
		void inorderIndentPrint(node*  root,int h){
			if(root==null) {
				printNode('.',h);
				return ;
			}
			inorderIndentPrint(root->r,h+1);
			printNode(root->item,h) ;
			inorderIndentPrint(root->l,h+1);
		}
};

template< typename t>
using link = node<t> *;
void solve(){
	link<int> head = new node<int> (10,0,0);
	srand(time(0));
	fli(i,0,8)
		head->insert(rand() % 20 + 1) ;
	head->inorder();
	head->search(20)==null ? deb("not found") : deb(head->search(20)->item);
	deb(head->max()->item);
	deb(head->min()->item);
	head->inorderIndentPrint(head,0);
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

