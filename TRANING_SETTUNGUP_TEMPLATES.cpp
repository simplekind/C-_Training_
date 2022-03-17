#include <bits/stdc++.h>

#define fli(i,a,b) for(auto i=a;i<b;i++)
#define fld(i,a,b) for(auto i=a;i>=b;i--)
#define llfli(i,a,b) for(auto i=a;i<b;i++)
#define llfld(i,a,b) for(auto i=a;i>b;i--)
#define test int s2; cin>>s2;while(s2--)
#define lltest ll s2; cin>>s2;while(s2--)
#define endln '\n'
#define ll long long
#define ld long double
#define pb push_back
#define popb pop_back
#define mp make_pair
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);cout<<fixed;srand(time(0));
#define F first
#define S second
#define intu unsigned int
#define inf 0x3f3f3f3f
#define _inf 0xcfcfcfcf
#define in_arr(a,n) int n ;cin>>n;int a[n];fli(i,0,n)cin>>a[i];
#define in_vec(v,n) int n ;cin>>n;vector<int> v (n);fli(i,0,n)cin>>v[i];
#define cout_arr(a,n)  fli(i,0,n) cout<<a[i]<<" ";
#define for_it(v,it) for (auto it= v.begin(); it!=v.end();it++)
#define deb(x) cout << #x << " = " << x << endl
#define endln '\n'

using namespace std;

#define forll(h,i) for (link i = head;i!=0;i=i->nxt)
#define null nullptr

//template <typename Item>
//struct node {
//	Item item ;
//	node *nxt ;
//	node (Item item , node *t ){
//		this->item =item;
//		(*this).nxt = t ;
//	}
//};
//
//template <typename Item>
//using link = node<Item>* ;
//
//template <typename Item>
//void insertAt (link<Item>& head ,link<Item> temp,int pos){
//	if(pos==1){
//		temp->nxt = head ;
//		head = temp ;
//		return ;
//	}
//	link<Item> curr = head ;
//	for (int i =0;i<pos-2;i++){
//		curr= curr->nxt  ;
//		if(pos!=i+3 && curr->nxt == NULL ){
//			cout<<"Memory Overflow"<<endl;
//			return ;
//		}
//	}
//	temp->nxt = curr->nxt ;
//	curr->nxt = temp ;
//}
//
//template <typename Item>
//void printList(link<Item> head){
//	if(head ==null){
//		cout<<"Linked List is empty"<<endln;
//		return ;
//	}
//	link<Item> curr = head ;
//	while(curr!=NULL){
//		deb(curr->item);
//		curr = curr->nxt ;
//	}
//}
//
//template <typename Item>
//void delList(link<Item>& head ,int pos){
//	if(pos==1){
//		link<Item> temp = head ;
//		head = head->nxt;
//		delete temp ;
//		return ;
//	}
//	link<Item> curr = head ;
//	fli(i,0,pos-2){
//		curr= curr->nxt ;
//		if(curr==null && i!=pos-3){
//			cout<<"Memory Overflow"<<endln;
//			return;
//		}
//	}
//	link<Item> temp = curr->nxt ;
//	curr->nxt=curr->nxt->nxt;
//	delete temp ;
//}
//
//template <typename Item>
//void delSinglyLinkedList(link<Item>& head ){
//	while( head !=null){
//		link <Item> temp = head ;
//		head = head->nxt ;
//		delete temp ;
//	}
//}// \\
//03/01/22 11:30

//template <typename t>
//struct node {
//	t item ;
//	node* l , *r;
//	node(t item , node*l, node*r){
//		this->item=item;
//		this->l=l;
//		this->r=r;
//	}
//};
//
//#define null nullptr
//template< typename t>
//using link = node<t> *;
//
//template<typename t>
//void levelOrder(link<t> curr){
//	queue <link<t>> q  ;
//	q.push(curr) ;
//	while(!q.empty()){
//		q.push(null);
//		while(q.front()!=null){
//			link<t> temp = q.front();
//			cout<<temp->item<<" ";
//			if(temp->l!=null) q.push(temp->l);
//			if(temp->r!=null) q.push(temp->r);
//			q.pop();
//		}
//		q.pop();
//		cout<<endln;
//	}
//}

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

template<typename t>
link<t> insertAtRoot(link<t> root,int x){
	if(root==null) return new node<t>(x,0,0);
	if(x>root->item) {
		root->r=insertAtRoot(root->r,x);
	}else{
		root->l=insertAtRoot(root->l,x);
	}
	int balanceFactor = height(root->l) - height(root->r) ;
	if(balanceFactor>1){
		if(height(root->l->l) >= height(root->l->r)){
			return Rrot(root);
		}else{
			root->l = Lrot(root->l);
			return Rrot(root);
		}
	}else if (balanceFactor<-1){
		if(height(root->r->r) >= height(root->r->l)){
			return Lrot(root);
		}else{
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

int main(){
//	link<double> headDouble = new node<double>(0.0,null) ;
//	link<int> headInt = new node<int>(1,null) ;
//	
//	fli(i,0,10){
//		insertAt(headDouble,new node<double>((double) 0.5,null ),i+1) ;
//	}
//	fli(i,0,10){
//		insertAt(headInt,new node<int>(i+2,null ),i+1) ;
//	}
//	
//	printList<double>(headDouble);
//	cout<<endln;
//	printList<int>(headInt);
	
	return 0;
}

