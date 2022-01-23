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
		link<t> temp = q.front();cout<<temp->item<<" ";q.pop();
		if(temp->l!=null) q.push(temp->l);
		if(temp->r!=null) q.push(temp->r);
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
// depth of node is no.of edges from root to node
// depth of tree is depth of bottomost leaf node which is same as height of tree

// Prints Binary Tree (using inorder)

void printNode(char x,int h){
	fli(i,0,h) cout<<"	 ";
	cout<<x<<endln;
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
	char arr [] = {'*','+','a','*','*','b','c','+','d','e','f'};
	link<char> Node = parseTree(arr);
	inorderIndentPrint(Node,0);
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

