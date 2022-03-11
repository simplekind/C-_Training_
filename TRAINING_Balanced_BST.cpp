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

#define null nullptr
template <typename t>
struct node {
	t item ;
	node* l , *r;
	node(t item , node*l, node*r){this->item=item;this->l=l;this->r=r;}
};
template<typename t>
using link = node<t> * ;


void printNode(char x,int h){
	fli(i,0,h) cout<<"	 ";
	cout<<((int)(x)==46?-1:x)<<endln;
}

void inorderIndentPrint(link<int> root,int h){
	if(root==null) {
		printNode('.',h);
		return ;
	}
	inorderIndentPrint(root->r,h+1);
	printNode(root->item,h) ;
	inorderIndentPrint(root->l,h+1);
}

template<typename t>
link<t> searchHelper(link<t> head,t x){
	if(head==null) return null;
	if(head->item==x) return head;
	else if(head->item < x ) return searchHelper(head->r,x);
	else if(head->item > x ) return searchHelper(head->l,x);
}

template<typename t>
link<t> insertHelper(link<t> head , t x){
	if(head==null) {
		link<t> curr = new node<t>(x,0,0);
		return curr;
	}
	else if(head->item<=x) {
		head->r=insertHelper(head->r,x);
	}else{
		head->l=insertHelper(head->l,x);
	}
	return head;
}

template<typename t>
void inorderHelper(link<t> head){
	if(head==null) return;
	inorderHelper(head->l);
	deb(head->item);
	inorderHelper(head->r);
}

template<typename t>
link<t> maxHelper (link<t> head){
	if(head==null) return null;
	while(head->r!=null){
		head=head->r;
	}
	return head;
}

template<typename t>
link<t> minHelper (link<t> head){
	if(head==null) return null;
	while(head->l!=null){
		head=head->l;
	}
	return head;
}

template<typename t>
link<t> delHelper (link<t>& root ,int x){
	if (root==null) return null;
	if(root->item<x) root->r=delHelper(root->r,x);
	else if(root->item>x) root->l=delHelper(root->l,x);
	else if (root->item==x){link<t> r=root->r , *l=root->l ;
		if(root->l==null && root->r==null) {root=null;return null;
		}else if (root->l==null){link<t> temp = root->r;root->r=null;root=temp;return temp;
		}else if (root->r=null && root->l!=null){link<t> temp = root->l;root->l=null;	root=temp;return temp;
		}else{link<t> temp = root->l , *prevTotemp = root;
			while(temp!=null && temp->r!=null) prevTotemp=temp,temp = temp->r;
			temp->r = r ;
			if(prevTotemp!=root){prevTotemp->r = temp->l;temp->l = l;}
			root->l=null,root->r=null;
			root=temp;
		}
	}
	return root;
}//~\\
10/03/22 18:31

// rotation at root h
template <typename t>
link<t> Rrot (link<t> h){
	if(h==null) return h;
	link <t> x = h->l;
	h->l=x->r;
	x->r=h;
	h=x;
	return h;
}

// rotation at root h
template <typename t>
link<t> Lrot (link<t> h){
	if(h==null) return h;
	link<t> x = h->r;
	h->r = x->l;
	x->l=h;
	h=x;
	return h;
}

// bring a node to root in BST
template <typename t>
void nodeToRoot ( link<t>& h , link<t> x){
	// Base Case
	if(h->r==x){
		h=Lrot(h);
		return;
	}
	if(h->l==x){
		h=Rrot(h);
		return;
	}
	// first search for its parent node and parent of parent node
	link<t> par = h, parpar = h ;
	while(par->r!=x && par->l!=x){
		parpar= par;
		if(par->item < x->item ) par=par->r;
		else par=par->l;
	}
	cout<<endln<<endln;
	if(par==null) return; // no par found		
	if (par->r==x){
		if(parpar->r==par)
			parpar->r = Lrot(par); // now x is parent of par
		else
			parpar->l = Lrot(par); // now x is parent of par 
		nodeToRoot(h,x);
	}else if (par->l==x){
		if(parpar->r==par)
			parpar->r = Rrot(par); // now x is parent of par
		else
			parpar->l = Rrot(par); // now x is parent of par 
		nodeToRoot(h,x);
	}else{
		return ; // no par found		
	}
}

template<typename t>
void insertAtRoot(link<t> par,link<t>& head , t x){
	if(head==null) {
		if(par->item<x)
			par->r= new node<t> (x,0,0);
		else 
			par->l= new node<t> (x,0,0);
		return ;
	}
	else if(head->item<=x) {
		inorderIndentPrint(head,0);
		cout<<endln<<endln<<endln;
		insertAtRoot(head,head->r,x);
		if(par==head) {
			head=Lrot(head);
			return;
		}
		if(par->item<head->item)
			par->r=Lrot(head);
		else 
			par->l=Lrot(head);
	}else{
		inorderIndentPrint(head,0);
		cout<<endln<<endln<<endln;
		insertAtRoot(head,head->l,x);
		if(par==head) {
			head=Rrot(head);
			return ;
		}
		if(par->item<head->item)
			par->r=Rrot(head);
		else 
			par->l=Rrot(head);
	}
	return ;
}

// First things first , INSERTION AT ROOT IN BST , but why?
// In the standard implementation of BSTs, every new node inserted goes
// somewhere at the bottom of the tree, replacing some external node.
// an alternative insertion method, where we insist that each new item be
// inserted at the root, so recently inserted nodes are at the top of the

// can be done using ROTATION
//
// RIGHT ROTATION->
// b/w root and left child
// Upper node(A) comes down and lower node(B) comes up in clockwise
// But it comes down at a cost that (pun intended) that right part of B shall now be left
// part of A to preserve the property of BSTs.
//
//
// LEFT ROTATION->
// b/w root and right child
// Upper node(A) comes down and lower node(B) comes up in ANTI-clockwise
// But it comes down at a cost that (pun intended) that LEFT part of B shall now be RIGHT
// part of A to preserve the property of BSTs.

// This is basically to reduce the time complexity
// of BSTs in case of skew trees (worst case pfft ) 
// by restricting its height to an extent

// These are rep as HB(k) where k is abs diff
// between left subtree height and right subtree height
// k is also called Balance Factor

// for k = 0  we get full BST

void solve(){
	link<int> head = new node<int> (1,0,0);
	insertHelper(head,12);
	insertHelper(head,20);
	insertHelper(head,5);
	insertHelper(head,3);
	insertHelper(head,10);
	insertHelper(head,8);
	insertHelper(head,7);
	inorderIndentPrint(head,0);
	link<int> se7even = searchHelper(head,7);
	// now we wish to bring 7 to the head
	nodeToRoot(head,se7even);
	inorderIndentPrint(head,0);
	inorderHelper(head);
	// now we wish to insert node at root
	// this can be done in 2 ways by :
	//	1. insert and rotate together
	//  2. first insert then rotate	
	insertAtRoot(head,head,21);
	inorderIndentPrint(head,0);	
	inorderHelper(head);
	insertHelper(head,15);
	link<int> fif = searchHelper(head,15);
	nodeToRoot(head,fif);	
	inorderIndentPrint(head,0);	
	inorderHelper(head);
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

