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
int ** newArr(int n,int m)  ;

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

/// AVL TREE
// BST
// For any node abs(leftHeight - rightHeight) <= 1

#define null nullptr
template <typename t>
struct node {
	t item ;
	node *l , *r;
	int height ;
	node(t item , node*l, node*r){
		this->item=item;
		this->l=l;
		this->r=r;
		this->height=0;
	}
};
template<typename t>
using link = node<t>*;

template<typename t>
int height( link<t> root){
	if(root==null) return -1; 
	return root->height;
}

template<typename t>
link<t> Lrot(link<t> root){
	if(root==null) return null;
	link<t> x  = root->r;
	root->r = x->l;
	x->l = root;
	root->height = max(height(root->l),height(root->r))+1;
	x->height = max(height(x->l),height(x->r)) + 1;
	return x;
}

template<typename t>
link<t> Rrot(link<t> root){
	if(root==null) return null;
	link<t> x  = root->l;
	root->l = x->r;
	x->r = root;
	root->height = max(height(root->l),height(root->r))+1;
	x->height = max(height(x->l),height(x->r)) + 1;
	return x;
}

// insertion of node at the root node
template<typename t>
link<t> insertAtRoot(link<t> root,int x){
	if(root==null) return new node<t>(x,0,0);
	if(x>root->item) { // that means we have to go to right to insert that node
		root->r=insertAtRoot(root->r,x);
	}else{
		root->l=insertAtRoot(root->l,x);
	}
	// left height - right height
	int balanceFactor = height(root->l) - height(root->r) ;
	if(balanceFactor>1){ // R rot
		if(height(root->l->l) >= height(root->l->r)){
			// R Rot 
			// since Rotation is on left part of node and no rotation is reqd on its left part of left node
			// LL ROTATION
			return Rrot(root);
		}else{
			// L Rot 
			// since Rotation is on left part of node and L rotation is reqd on its right part Of left node
			// LR ROTATION
			root->l = Lrot(root->l);
			return Rrot(root);
		}
	}else if (balanceFactor<-1){ // L Rot
		if(height(root->r->r) >= height(root->r->l)){
			// L Rot 
			// since Rotation is on right part of node and no rotation is reqd on its right part of right node
			// RR ROTATION
			return Lrot(root);
		}else{
			// L Rot 
			// since Rotation is on right part of node and R rotation is reqd on its left part Of right node
			// RL ROTATION
			root->r = Rrot(root->r);
			return Lrot(root);
		}
	}
	root->height= 1+ max(height(root->l),height(root->r));
	return root;
}

template<typename t>
void insert(link<t>& root, int x){
	root=insertAtRoot(root,x);
}

void printNode(char x,int h){
	fli(i,0,h) cout<<"	 ";
	cout<<((int)(x)==46?-1:x)<<endln;
}

template<typename t>
void inorderIndentPrint(link<t> root,int h){
	if(root==null) {
		printNode('.',h);
		return ;
	}
	inorderIndentPrint(root->r,h+1);
	printNode(root->item,h) ;
	inorderIndentPrint(root->l,h+1);
}

// for height h of AVL TREE
// 1) min no. of nodes
// N(h) = N(h-1) + N(h-2) + 1
// N(h) = O ( 1.618^h) ~= O(logn)
// so one can say max height reaches O(logn)

// 2) max no. of nodes when we try to fill each level , so h-1
// N(h) = N(h-1) + N(h-1) + 1
// N(h) = 2N(h-1) + 1
// N(h) = O(2^h) => h = logn ~= O(logn)

// Number of different shapes of AVL tree for minimal case:-
// 		o
//	  /	  \
//  h-1	   h-2
//
// So if for height h we have NS(h)
// for height h-1 we have NS(h-1)
// for height h-2 we have NS(h-2)
// So for this case we have all diffenet possibilities for a tree with h-1 and for a tree with h-2
// i.e., NS(h-1)*NS(h-2)
//
// But this tree can be inverted in the sense that
// 		o
//	  /	  \
//  h-2	   h-1
// will be counted as a separate case as well ,
// i.e., NS(h-2)*NS(h-1)
//
// so NS(h) = NS(h-1)*NS(h-2) + NS(h-2)*NS(h-1) = 2*NS(h-1)*NS(h-2)
//

// an imp conceptual question
// this techq might be used in various questions

// SORTED ARRAY TO AVL
// idea is to pick up middle element as root coz its left part and right part either be equal or differ by 1
template <typename t>
link<t> helper_Arr_To_AVl (vector<int>& nums, int start, int end){	// eventually passing by ref saves us time
    if(start>end) return null;
    int mid = start + ((end-start)>>1);
    link<t> root= new node<t>(nums[mid],0,0);
    root->l=helper_Arr_To_AVl<t>(nums,start,mid-1);
    root->r=helper_Arr_To_AVl<t>(nums,mid+1,end);
    return root;
}

template <typename t>
link<t> Arr_To_AVl (vi& nums){
	return helper_Arr_To_AVl<t>(nums,0,nums.size()-1);
}

// The above techq might be used like to convert a BST to balanced , by first doing an inorder traversal then following this

// APPLICATION OF AVL TREES (ALSO FOLLOWS FOR OTHER BALANCED TREES AND RED BLAC TREES):
//
// A balanced binary tree can be a better option than a complete binary tree for storing a set S.
// However A complete binary tree is more space efficient as we do not need any extra flags. A
// balanced binary tree usually takes more space since we need to store some flags. For example, in
// a Red-Black tree we need to store a bit for the color. Also, a complete binary tree can be stored
// in a RAM as an array without using pointers

void solve(){
	link<int> root =new node<int> (1,0,0);
	insert(root,2);
	insert(root,3);
	insert(root,4);
	insert(root,5);
	insert(root,7);
	insert(root,6);
	insert(root,-2);
	insert(root,-5);
	insert(root,-8);
	inorderIndentPrint(root,0);
	vi v = {1,2,3,4,5,6,7,78};
	cout<<endln<<endln<<endln<<endln<<endln<<endln;
	inorderIndentPrint(Arr_To_AVl<int>(v),0);	
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

