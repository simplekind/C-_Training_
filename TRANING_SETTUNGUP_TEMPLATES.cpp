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
	node* l , *r;
	node(t item , node*l, node*r){this->item=item;this->l=l;this->r=r;}
};
template<typename t>
using link = node<t> * ;

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

