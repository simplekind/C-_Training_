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

template <typename t>
struct node {
	t item ;
	node* l , *r;
	node(t item , node*l, node*r){
		this->item=item;
		this->l=l;
		this->r=r;
	}
};

//typedef node* link ;
#define null nullptr
template< typename t>
using link = node<t> *;

template<typename t>
void preOrderTrav(link<t> curr){
	if(curr==null) return ;
	cout<<curr->item<<" ";
	preOrderTrav(curr->l);
	preOrderTrav(curr->r);
}

template<typename t>
void preOrderTrav_It(link<t> curr){
	if(curr==null) return ;
	stack <link<t>> s  ;
	s.push(curr);
	while(!s.empty()){
		link<t> temp = s.top();
		s.pop();
		cout<<temp->item<<" ";
		if(temp->r != null) s.push(temp->r);
		if(temp->l != null) s.push(temp->l);
	}
}

template<typename t>
void inOrderTrav(link<t> curr){
	if(curr==null) return ;
	inOrderTrav(curr->l);
	cout<<curr->item<<" ";
	inOrderTrav(curr->r);
}

template<typename t>
void inOrderTrav_it(link<t> curr){
	if(curr==null) return;
	stack <link<t>> s ;
	link<t> temp =curr; 
	while(1){
		if(temp!=null){
			s.push(temp);
			temp=temp->l;
			
		}else{
			if(s.empty()) break ; 
			temp=s.top();s.pop();
			cout<<temp->item<<" ";
			temp=temp->r;
		}
	}
}

template<typename t>
void postOrderTrav(link<t> curr){
	if(curr==null) return ;
	postOrderTrav(curr->l);
	postOrderTrav(curr->r);
	cout<<curr->item<<" ";
}

template<typename t>
void postOrder_It(link<t> curr){
	if(curr==null) return ;
	stack <link<t>> s ;
	link<t> temp = curr ;
	s.push(temp);
	temp=temp->l;
	while(1){
		if(temp!=null){
			s.push(temp);
			temp=temp->l;
		}else{
			temp=s.top();
			s.pop();
			s.push(temp);
			temp=temp->r;
			link<t> root = s.top();
			if(temp!=null){
				
			}else{
				while(root->r==temp){
					s.pop();
					cout<<root->item<<" ";
					temp=root;
					root=s.top();
				}
				temp=root->r;
			}
		}
	}
}


template<typename t>
void levelOrder(link<t> curr){
	queue <link<t>> q  ;
	q.push(curr) ;
	while(!q.empty()){
		q.push(null);
		while(q.front()!=null){
			link<t> temp = q.front();
			cout<<temp->item<<" ";
			if(temp->l!=null) q.push(temp->l);
			if(temp->r!=null) q.push(temp->r);
			q.pop();
		}
		q.pop();
		cout<<endln;
	}
}

template<typename t>
int countNodes(link<t> root){
	if(root==null) return 0;
	return countNodes(root->l) + countNodes(root->r)+1;
}
// height of node is no. of edges from node to a bottomost leaf
// height of tree is height of root
// height of tree with 1 node is 0

template<typename t>
int getHeight(link<t> root){
	if(root==null) return -1;
	return max(getHeight(root->l),getHeight(root->r)) +1 ;
}

template<typename t>
int getSizeIt(link <t> root){
	if(root==null) return -1;
	queue <link<t>> q;
	q.push(root);
	q.push(null);
	int h = 0 ;
	while(!q.empty() && q.front()!=null){
		while(q.front()!=null){
			h++;
//			deb(q.front()->item);	
			if(q.front()->l!=null) q.push(q.front()->l);
			if(q.front()->r!=null) q.push(q.front()->r);
			q.pop();
		}
//		cout<<endln;
		q.pop();
		q.push(null);
	}
	return h;
}

// depth of node is no.of edges from root to node
// depth of tree is depth of bottomost leaf node which is same as height of tree

// Prints Binary Tree (using inorder)

void printNode(char x,int h){
	fli(i,0,h) cout<<"	 ";
	cout<<(((int)x)==46?-1:x)<<endln;
}

template<typename t>
void inorderIndentPrint(link<t> root,int h){
	if(root==null) {
		printNode('.',h);
		return ;
	}
	inorderIndentPrint(root->l,h+1);
	printNode(root->item,h) ;
	inorderIndentPrint(root->r,h+1);
}

// array to tree - desiging a game of tournament using divide and conquer
template<typename t>
link<t> dnc(int* a,int l ,int r){
	int m = (l+r)/2;
	link<t> temp = new node<t>(a[m],0,0);
	if(l>=r) return temp;
	temp->l=dnc<t>(a,l,m);
	temp->r=dnc<t>(a,m+1,r);
	int x = temp->l->item, y= temp->r->item ;
	if(x>y) temp->item= x;
	else temp->item=y;
	return temp;
}

// prefix to B.T.

link<char> parseTreeHelper(char *a,int& i){
	char t = a[i++];
	link<char> temp = new node<char>(t,0,0);
	if(t=='+' || t=='*' ||t=='-' || t=='/'){
		temp->l= parseTreeHelper(a,i) ;
		temp->r= parseTreeHelper(a,i) ;		
	}
	return temp;
}

link<char> parseTree(char *a){
	int i = 0;
	return parseTreeHelper(a,i);
}

// for ques based on leaf nodes , use the fact they have both left and right child as null
// for ques based on full nodes , use the fact they have both non empty nodes
// for ques based on half nodes , use the fact they have either of nodes null but not both

// DIAMETER OF A TREE-> longest path between 2 nodes of a tree 
// O(n^2)
template<typename t>
int diam(link<t> root){
	if(root==null) return 0;
	int lD = diam(root->l);
	int rD = diam(root->r);
	int lH = getHeight(root->l);
	int rH = getHeight(root->r);
	return max(lD,max(lH+rH+2,rD));
}

// using DP in O(n)
template<typename t>
int getHeight(link<t> root,map<link<t>,int>& dp){
    if(root==null) return -1;
    int ans = max(getHeight(root->l,dp),getHeight(root->r,dp)) +1 ;
    dp[root] =ans;
    return ans;
}

template<typename t>
int helper(link<t> root,map<link<t>,int>& dp){
    if(root==null) return 0;
    int lD = helper(root->l,dp);
    int rD = helper(root->r,dp);
    int lH ,rH;
    lH=rH=-1;
    if(root->l!=null) lH = dp[root->l];
    if(root->r!=null)rH = dp[root->r];
    return max(lD,max(lH+rH+2,rD));
}

template<typename t>
int diamDP(link<t> root) {
    if(root==null) return 0;
    int count = 0;
    map<link<t>,int> dp ;
    getHeight(root,dp);
    return helper(root,dp);
}

template<typename t>
void invert(link<t> root){
	if(root==null) return ;
	link<t> temp = root->l ;
	root->l = root->r;
	root->r= temp ;
	invert(root->l);
	invert(root->r);
}

//LCA -> Lowest Common Ancestor : For 2 given nodes , there are many common ancestors , LCA is Lowest of all of common ancestors
template<typename t>
link<t> lca (link<t> root, link<t> p, link<t> q){
	if(root==null) return root;
	if(root==p) return p;
	if(root==q) return q;
	link<t> a = lca(root->l,p,q);
	if((a!=null && (a!=p && a!=q))) return a;
	link<t> b = lca(root->r,p,q);
	if(a==null) return b;
	if(b==null) return a;
	return root;
}

// If one of the traversal methods is Inorder then
// the tree can be constructed uniquely, otherwise not.
//• Inorder and Preorder
//• Inorder and Postorder
//• Inorder and Level-order

//The following combinations do not uniquely identify a tree.
//• Postorder and Preorder
//• Preorder and Level-order
//• Postorder and Level-order

//
// 	Given a parent array P, where P[i] indicates the parent of ith node in the tree
//	(assume parent of root node is indicated with –1). Give an algorithm for finding the height
//	or depth of the tree.
//
//  Parent - child relationship:
//		-1 	0 	1 	6 	6 	0 	0 	2 	7
//	 	 0 	1 	2 	3 	4 	5 	6 	7 	8 
int getMaxDepthKaryTree_n2(vi p){
	if(!p.size()) return -1;
	int md = -1;
	fli(i,0,p.size()){
		int j = i, cd = 0;
		while(j!=-1){
			j=p[j];cd++;
		}
		md= max (md,cd);
	}
	return md;
}
    
int getMaxDepthKaryTree_n(vi p){
	if(!p.size()) return -1;
	int md = -1;
	vi dp (p.size(),-1);
	fli(i,0,p.size()){
//		deb(i);
		int j = i, cd = 0;
//		deb(dp[i]);
		if (dp[i]!=-1) 
			cd = dp[i]+1;
		else
			while(j!=-1){
				j=p[j];
				cd++;
			}
		md= max (md,cd);			
		dp[i]= md;
//		deb(dp[i]);
	}
	return md ;
}



void solve(){
	link<int> root   = new node<int> (5,null,null);
	link<int> rootl  = new node<int> (4,null,null);
	link<int> rootr  = new node<int> (8,null,null);
	link<int> rootll = new node<int> (2,null,null);
	link<int> rootlll = new node<int> (1,null,null);
	link<int> rootllr = new node<int> (3,null,null);
	link<int> rootrl = new node<int> (6,null,null);
	link<int> rootrlr = new node<int> (7,null,null);
	
	root->l= rootl;root->r=rootr;
	rootl->l=rootll;
	rootll->l=rootlll;rootll->r=rootllr;
	rootr->l=rootrl;
	rootrl->r=rootrlr;
//	cout<<"preOrderTrav : ";
//	preOrderTrav(root);cout<<endln;
//	cout<<"preOrderTrav_It : ";
//	preOrderTrav_It(root);cout<<endln;
//	cout<<"inOrderTrav : ";
//	inOrderTrav(root);cout<<endln;
//	cout<<"inOrderTrav_it : ";
//	inOrderTrav_it(root);cout<<endln;
//	cout<<"postOrderTrav : ";
//	postOrderTrav(root);cout<<endln;
//	cout<<"postOrder_It : ";
//	postOrder_It(root);cout<<endln;
//	cout<<"levelOrder : ";
//	levelOrder(root);cout<<endln;
//	deb(countNodes(root));
//	deb(getHeight(root));
//	cout<<"Quick tree-print function : "<<endln;
//	inorderIndentPrint(root,0);
//	int arr [] = {1,13,16,12,5};
//	link<int> Node = dnc<int>(arr,0,4);
//	inorderIndentPrint(Node,0);
//	char arr [] = {'*','+','a','*','*','b','c','+','d','e','f'};
//	link<char> Node = parseTree(arr);
//	inorderIndentPrint(root,0);
//	deb (getSizeIt(root));	
//	deb(diam(root)) ;
////	deb(diamDP(root)) ;
//	inorderIndentPrint<int>(root,0);
//	invert(root);
//	cout<<endln<<endln<<endln<<endln;
//	inorderIndentPrint<int>(root,0);
//	cout<<lca(root,rootlll,rootrlr)->item;
//	vi p  = {-1 	,0 	,1 	,6 	,6 	,0 	,0 	,2 	,7};	
//	deb (getMaxDepthKaryTree_n2(p));
//	deb (getMaxDepthKaryTree_n(p));
	
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

