#include <bits/stdc++.h>
#include <iomanip> 
// #include <ext/pb_ds/assoc_container.hpp>	policy-based data structures

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
#define deb(x) cout << #x << " = " << x << endln;
#define endln '\n'
#define null nullptr

int max (const int& x ,const int& y,const int& z){ return  ( ( x>y ) ? ( (x>z) ? x : z ) : ( (y>z) ? y : z ) ) ; }
float randFloat() { return (float) 1*rand()/RAND_MAX ; }
 
 // TO OPTIMIZE A o(N^2) SOLUTIOON in which j depends on i , In most of the such algos
 // U might be able to optimize it with help of STACKS
 
using namespace std;
// using namespace __gnu_pbds; // for policy-based data structures

typedef vector<int> vi;
typedef vector<int> pi;  

//	members of struct are public by default.
struct node {		// Kinda template / primitive construct for LInked list 
	int item ;		//  Item is an unspecified datatype 
	node *nxt ;
	node *prev ;
	node (int item , node *prev , node *next ){
		this->item =item;
		(*this).nxt = next ;
		(*this).prev = prev ;
	}
}; 


typedef node *link ; // to avoid typing * and making it readable
					 // link = new node ;
#define forll(h,i) for (link i = head;i!=0;i=i->nxt)

void insertAtHead(link &head, int x){
	link temp = new node(x,null,null);
	if(head==null) {
		head= temp;
		return;
	} 
	head->prev=temp;
	temp->nxt=head;
	head=temp;
}

void insertAtTail(link head, int x){ 
	link temp = new node(x,null,null);
	if(head==null) {
		head= temp;
		return;
	} 
	link curr= head;
	while(curr->nxt!=null){
		curr=curr->nxt;
	} 
	curr->nxt=temp;
	temp->prev=curr;
//	deb(curr->item);
}

void insert(link &head, int x,int pos){
	link temp = new node(x,null,null);
	if(head==null) {
		head= temp;
		return;
	}
	if(pos==1){
		temp->nxt = head ; 
		head->prev=temp;
		head = temp ; 
		return ;
	} 
	link curr = head;
	int i =0;
	while(curr!=null){
		if(pos-2==i){  
			temp->prev=curr;
			temp->nxt=curr->nxt;
			if(curr->nxt !=null) {
				curr->nxt->prev=temp;
			}
			curr->nxt=temp;
			return;
		}
		curr=curr->nxt;
		i++;
	} 
	cout<<"Size Overflow"<<endln;
}
  
void printForward(link& head){ 
	if(head ==null){
		cout<<"Doubly Linked List is empty"<<endln;
		return ;
	} 
	link curr = head ;
	while(curr!=null){
		deb(curr->item);
		curr = curr->nxt ;
	}
}

void printReverse(link& head){ 
	if(head ==null){
		cout<<"Doubly Linked List is empty"<<endln;
		return ;
	} 
	link curr = head ;
	while(curr->nxt!=null){
//		deb(curr->item);	
		curr = curr->nxt ;
	} 
	while(curr!=null){
		deb(curr->item);
		curr = curr->prev ;
	}
}

void del(link* head ,int pos){
	if(pos==1){
		if(head==null) return;
		if(head->nxt==null) return;
		head=head->nxt;
		return ;
	}	
	link curr = (*head) ;
	fli(i,0,pos-2){
		curr= curr->nxt ;
		if(curr==null && i!=pos-3){
			cout<<"Memory Overflow"<<endln;
			return;
		}	
	} 
	link temp = curr->nxt->nxt;
	curr->nxt->nxt=null;
	curr->nxt->prev=null;
	curr->nxt=temp;
	temp->prev=curr;
} 

void delSinglyLinkedList(link*head ){
	while( (*head )!=null){
		link temp = (*head ) ; 
		(*head ) = (*head )->nxt ; 
		delete temp ;
	}
}

int main() {
	link head = new node (4,0,0) ;  
	insertAtHead(head,3);
	insertAtTail(head,5);
	insertAtHead(head,2);
	insertAtHead(head,1);
	insertAtTail(head,6);
	fli(i,7,16)
		insert(head,i,i) ;
	printForward(head); 
	cout<<endln;
	printReverse(head);
	insert(head,-1,10);
	insert(head,-1,7);
	insert(head,-1,5);
	cout<<endln;
	printForward(head); 
}  
