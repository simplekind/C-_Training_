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
using namespace std;
typedef vector<int> vi;
typedef vector<int> pi;  

struct Node {		
	int item ;		
	Node *ptrdiff ;
	
	// The ptrdiff pointer field contains the difference between the pointer to the next node and the
	// pointer to the previous node
	Node (int item , Node *ptrdiff){
		this->item =item;
		(*this).ptrdiff = ptrdiff ;	
	}
}; 

typedef Node *link ; // to avoid typing * and making it readable
					 // link = new node ;
#define forll(h,i) for (link i = head;i!=0;i=i->nxt)

// So basically how it works is that:
// lets say  u have 
//
//	   100	   104	   108	   112	
//		1 		2 		3 		4 
//	Now what to store in each link node ? so that we can go to next node and prev node
//  What we can do is store info addr about next node and prev node in the curr node by storing address in a single value using some
//  operation such as lets say we store (100,108) in node 104
//  While traversing to get next node what we can do is perform an operation (100,108) with prev node 100,
//	to get nxt node
//  Since 100,108 and 100 has 100 in common and to remove common and get rest of data , we can do is:
//	perform XOR !
//
//  100,108 ^ 100 = 108 ?
//	only possible if we store it as 100^108
//	So 100^108^100=108^0=108 
//
//	To get prev node we need data of next node while traversing
//	100^108^108=100
//
//	So we will store it as :
//	
//		100	   104	   108	   112	
//		 1 		2 		3 		4
//	   0^104  100^108  104^112 108^0
//
 
link xornode(link node1,link node2){
	return (link) ( (uintptr_t)node1 ^ (uintptr_t)node2 ) ;
} 

// one thing of which we have to care , while traversing the list , is that we need to remember the address of 
// the previously accessed node in order to calculate the next node’s address

void insertAtTail (link& head,link node){
	if(head==null){
		head=node;
		return;
	} 
	link curr = head ;
	link prev = null ;
	link next= xornode(curr->ptrdiff,prev) ;
	while(next!=null){
		prev=curr;
		curr=next;
		next=xornode(curr->ptrdiff,prev) ;
	} 
	curr->ptrdiff= xornode(prev,node); 
	node->ptrdiff= xornode(curr,0)   ;
}

void printForward_and_Reverse(link& head){
	if(head==null){
		return;
	} 
	cout<<"Printing in Forward ... "<<endln;
	link curr = head ;
	link prev = null; // we will use prev node address to get address of next node;
	while(curr!=null){
		deb(curr->item);
		link next= xornode(curr->ptrdiff,prev);
		prev=curr;
		curr=next;
	}	
	cout<<endln;
	cout<<"Printing in Reverse ... "<<endln;
	//Now we are on null node in curr but prev is on last node;
	link next = null;
	curr=prev;
	while(curr!=null){
		deb(curr->item);
		link prev = xornode(curr->ptrdiff,next);
		next=curr;
		curr=prev;
	} 
}

int main() {
	link head = new Node (1,0) ;   
	insertAtTail(head, new Node(2,0)) ;
	insertAtTail(head, new Node(3,0)) ;
	insertAtTail(head, new Node(4,0)) ;
	insertAtTail(head, new Node(5,0)) ;
	printForward_and_Reverse(head);
	return 0;
}  
