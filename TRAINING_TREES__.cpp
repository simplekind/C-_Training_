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

struct node {
	int item ;
	node* l , *r;
	node(int item , node*l, node*r){
		this->item=item;
		this->l=l;
		this->r=r;
	}
};

typedef node* link ;
#define null nullptr

void preOrderTrav(link curr){
	if(curr==null) return ;
	cout<<curr->item<<" ";
	preOrderTrav(curr->l);
	preOrderTrav(curr->r);
}

void preOrderTrav_It(link curr){
	if(curr==null) return ;
	stack <link> s  ;
	s.push(curr);
	while(!s.empty()){
		link temp = s.top();
		s.pop();
		cout<<temp->item<<" ";
		if(temp->r != null) s.push(temp->r);
		if(temp->l != null) s.push(temp->l);
	}
}

void inOrderTrav(link curr){
	if(curr==null) return ;
	inOrderTrav(curr->l);
	cout<<curr->item<<" ";
	inOrderTrav(curr->r);
}

void inOrderTrav_it(link curr){
	if(curr==null) return;
	stack <link> s ;
	link temp =curr; 
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

void postOrderTrav(link curr){
	if(curr==null) return ;
	postOrderTrav(curr->l);
	postOrderTrav(curr->r);
	cout<<curr->item<<" ";
}

void postOrder_It(link curr){
	if(curr==null) return ;
	stack <link> s ;
	link temp = curr ;
	while(1){
		if(temp!=null){
			s.push(temp);
			temp=temp->l;
		}else{
			temp=s.top();
			s.pop();
			s.push(temp);
			temp=temp->r;
			link root = s.top();
			if(temp!=null){
				// dummy condn
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
		if(s.empty()) break ;
	}
}

void solve(){
	link root   = new node (5,null,null);
	link rootl  = new node (4,null,null);
	link rootr  = new node (8,null,null);
	link rootll = new node (2,null,null);
	link rootlll = new node (1,null,null);
	link rootllr = new node (3,null,null);
	link rootrl = new node (6,null,null);
	link rootrlr = new node (7,null,null);
	
	root->l= rootl;root->r=rootr;
	rootl->l=rootll;
	rootll->l=rootlll;rootll->r=rootllr;
	rootr->l=rootrl;
	rootrl->r=rootrlr;
	cout<<"preOrderTrav : ";
	preOrderTrav(root);cout<<endln;
	cout<<"preOrderTrav_It : ";
	preOrderTrav_It(root);cout<<endln;
	cout<<"inOrderTrav : ";
	inOrderTrav(root);cout<<endln;
	cout<<"inOrderTrav_it : ";
	inOrderTrav_it(root);cout<<endln;
	cout<<"postOrderTrav : ";
	postOrderTrav(root);cout<<endln;
	cout<<"postOrder_It : ";
	postOrder_It(root);cout<<endln;
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

