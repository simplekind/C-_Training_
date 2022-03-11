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

//The running times of algorithms on binary search trees are dependent
//on the shapes of the trees

#define null nullptr
template <typename t>
struct node {
	t item ;
	node* l , *r;
	node (){
		this->l=null;
		this->r=null;
	}
	
//	While solving problems on BST, 
//  we first process left subtree, then
//	root data, and then
//	right subtree.
//	This means, depending on the problem, 
//	only the intermediate step (processing root data) changes
//	and we do not touch the first and third steps.

// in some problems you can convert bst to dll then process and back to dll
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
			else if(head->item<=x) {
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
		
		void insertHelperIt(node* head, t x){
			if(head==null){
				head  = new node (x,0,0);
				return;
			}
			node* par = head;
			for (node* curr = head ; curr!=null;){
				par=curr;
				if(curr->item > x) curr=curr->l;
				else curr=curr->r;
			}
			if(par->item > x) par->l = new node (x,0,0);
			else par->r = new node (x,0,0);
		}
		
		node* delHelper (node*& root ,int x){
			if (root==null) return null;
			deb(root->item);
			deb(root->r->item);
			if(root->item<x) root->r=delHelper(root->r,x);
			else if(root->item>x) root->l=delHelper(root->l,x);
			else if (root->item==x){
				deb(root->r->item);
				node* r=root->r , *l=root->l ;
				if(root->l==null && root->r==null) {
					root=null;
					return null;
				}else if (root->l==null){
					node* temp = root->r;
					root->r=null;
					root=temp;
					return temp;
				}else if (root->r=null && root->l!=null){
					node* temp = root->l;
					root->l=null;
					root=temp;
					return temp;
				}else{
					deb(root->item);
					// either go in left node of root and return max node from there or,
					// either go in right node of root and return min node of it 
					node* temp = root->l , *prevTotemp = root;
					while(temp!=null && temp->r!=null) prevTotemp=temp,temp = temp->r;
					temp->r = r ;
					if(prevTotemp!=root){
						prevTotemp->r = temp->l;
						temp->l = l;
					}
					root->l=null,root->r=null;
					root=temp;
				}
			}
			return root;
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
		void insertIt(t x){
			insertHelperIt(this,x);
		}
		
		node* del ( int x ){
			node* root = this;
			return delHelper(root,x);
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
// Actaully following one is a problem , but is good for understanding the basics of BST and inorder traversal!		
//		Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.
		int minDiffInBST(TreeNode* root) {
	        if (root==null) return 0;
	        link next = null;
	        int ans = INT_MAX;
	        InorderHelper(root,next,ans);
	        return ans ;
	    }
	    
	    void InorderHelper (link root,link& prev,int & ans ){
	        if (root==null) return ;
	        InorderHelper(root->left,prev,ans);
	        if (prev!=null) ans = min (ans,root->val-prev->val);
	        prev = root;
	        InorderHelper(root->right,prev,ans);
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

// So why its so useful?
//• Find/ Find Minimum / Find Maximum element in binary search trees
//• Inserting an element in binary search trees
//• Deleting an element from binary search trees (IMP)

// But, performing these operations on BST the height of the tree gets changed each time.
// Hence there exists variations in time complexities of best case, average case, and worst case.
// Worst case occurs when elements are in sorted order already


template< typename t>
using link = node<t> *;

void solve(){
	link<int> head = new node<int> (10,0,0);
	head->r=new node<int> (10,0,0);
	head->r->r=new node<int> (10,0,0);
	srand(time(0));
	fli(i,0,8)
		head->insert(rand() % 10 + 1) ;
	head->inorder();
	head->inorderIndentPrint(head,0);
	head=head->del(10);
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

