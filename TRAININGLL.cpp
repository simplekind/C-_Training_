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
#define deb(x) cout << #x << " = " << x << endl
#define endln '\n'
#define null nullptr

int max (const int& x ,const int& y,const int& z){ return  ( ( x>y ) ? ( (x>z) ? x : z ) : ( (y>z) ? y : z ) ) ; }
float randFloat() { return (float) 1*rand()/RAND_MAX ; }
 
 // TO OPTIMIZE A o(N^2) SOLUTIOON in which j depends on i , In most of the such algos
 // U might be able to optimize it with help of STACKS
 
 // Furhter as in case of cycles in some DS like ll, grphs , arrrays , whhat we can do is use Floyds:
 // Floyd-Warshall algorithm is a procedure, which is used to find the shorthest (longest) paths among 
 // all pairs of nodes in a graph, which does not contain any cycles of negative length.(for determining 
 // the least cost path between every pair of nodes)
 
 //	Basically FLoyd is for shortest/longest distance (MOSTLY but not always) in cycles , however we use it also to detect cycle,find starting point of cycle and remove it 
 
 // Somtimes to solve some array questions , think of it as linked list with its values as address of linked list
 // TO prove it , keep distance initliazed as per the defn
 
using namespace std;
// using namespace __gnu_pbds; // for policy-based data structures

typedef vector<int> vi;
typedef vector<int> pi;  

//	members of struct are public by default.
struct node {		// Kinda template / primitive construct for LInked list 
	int item ;		//  Item is an unspecified datatype 
	node *nxt ;
	node (int item , node *t ){
		this->item =item;
		(*this).nxt = t ;
	}
}; 

// A variation to  particalr prob in Linked list is that to find ith element:
//	1. i=n%k, so find last such element that its position % k (given) =0 , a simple while loop will do
//	2. i=n%k, so find first from last , so basically kth element from last
//  3. i=n/k th, so find fractional node'th element from start, use floyd's algo just this time pointer moving at k speed instead of 2
//  4. i= sqrt(n) // GOOD 1 , so Take 2 pointers and iterate a pointer unitl u find a posn such that its sqaure of position of other pointer , do it unitl u reach last node, u will eventually find the reqd pointer

//  Given a list, List1 = {A1, A2, . . . An–1; An) with data, reorder it to {A1,
//	An,A2,An–1} without using any extra space.
//	Solution: Find the middle of the linked list. We can do it by slow and fast pointer approach. After
//	finding the middle node, we reverse the right halfl then we do a in place merge of the two halves
//	of the linked list.

typedef node *link ; // to avoid typing * and making it readable
					 // link = new node ;


// THis wont work
//void insert (link head ,link temp,int pos){
//	if(pos==1){ 
//		deb(head);
////		head->item=-2;
//		deb(temp);
//		temp->nxt = head ; 
//		head = temp ; 
//		deb(head);
//		return ;
//	}
//	link curr = head ;
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

// Reason why above insert wont work
//void insert (link head ,link temp,int pos){
// This wont change value of head pointing to , 
// lets say : 
//		we have a head = { 	1	->	2	->	3	->	4	}
// 		insert ( head , new node (100,0) , 1   )
//		insert ( head , temp 			 , pos ) will be called
//		if(pos==1){
//			temp->nxt = head ;
//			head=temp ; 
//			return ;
//		} 	
//		This block do changes the value of head pointing to ,
//		And if you print(head) here in this insert function
//		You sure will get head = { 	100	->	2	->	3	->	4	}
// 		BUT...
// 	In main function , if you print head value
//	you will get head = { 	1	->	2	->	3	->	4	} which is same as original head 
//
// Wa-What? Why this happened lol XD?
//
// When u called insert func u basically allocated a new mem in stack function 
// with its new head pointer in function's scope with a different address which is pointing to a node in heap 
// A local copy(scope limited to function insert) is created with name head and linker / node pointer
// And since function passes by value here (no ampresand & here)
// it stores the value of head from main which is the address of linked list first node in heap
// so when u did 
//			temp->nxt = head ;	head=temp ; 
// 			u basically changed the local head in function
//			and not the original head
//
// So to change the actual head pointing node , you either pass the address of head (initial we passed address of linked list first node in heap )
// Or pass by ref.
// Either will do the work

//	Shud prefer this
//	void insert (link &head ,link temp,int pos) { will do the work as well just keep func defn same as the wrong one	}
void insert (link* head ,link temp,int pos){
	if(pos==1){
//		if(head) temp->nxt = head ; 
		temp->nxt = *head ; 
		*head = temp ; 
		(*head)->item=-9;
		return ;
	}
	link curr = *head ;
	fli(i,0,pos-2) {
		curr= curr->nxt  ;
		if(pos!=i+3 && curr->nxt == null ){
			cout<<"Memory Overflow"<<endln;
			return ;
		}
	} 
	temp->nxt = curr->nxt ;
	curr->nxt = temp ;
}
  
void print(link head){ 
	if(head ==null){
		cout<<"Linked List is empty"<<endln;
		return ;
	} 
	link curr = head ;
	while(curr!=null){
		deb(curr->item);
		curr = curr->nxt ;
	}
}

void del(link* head ,int pos){
	if(pos==1){
		(*head) = (*head)->nxt;
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
	curr->nxt=curr->nxt->nxt;
} 

void delSinglyLinkedList(link*head ){
	while( (*head )!=null){
		link temp = (*head ) ; 
		(*head ) = (*head )->nxt ; 
		delete temp ;
	}
}

//class A{
//	public :
//		ll a=10000000000ll;
//		A(){
//			cout<< (*this).a;			
//		}
//};

int main() {
//    A *a = new A();
	
//	link node 			// creates a pointer to a class node named node in stack with an adresss let sat 0x0
//		=				// u store an address to this pointer 
//	new Node(5,node) ;  // before assignment u create a mem in heap first of type Node 
//						// so node stores the adress of link as one in stack 

//	link nxtnode = new Node (6,node) ;
//	link nxtnxtnode = new Node (7,nxtnode) ;
//	link nxtnxtnxtnode = new Node (8,nxtnxtnode) ;
//	cout<<nxtnxtnxtnode->nxt->nxt->nxt->item<<endln;

//	cout<<nxtnxtnode->nxt->nxt->item<<endln;
//	cout<<nxtnode->nxt->item<<endln;

//	link head = new node (1,nullptr) ;
//	Yes, you can pass 0 to pointer , it can be used as a null pointer constant anywhere that an object pointer is expected. You might prefer to write nullptr (in modern C++) or NULL (if you're stuck in a pre-2011 world), to make it slightly clearer that that's the intention.
	link head = new node (1,0) ;  
	fli(i,2,16)
		insert(&head,new node (i,0) ,i) ;	
	insert(&head,new node (100,0),1);
	print(head) ;
	cout<<endln;
	del(&head,1);
	del(&head,5);
	del(&head,14);
	print(head); 
	cout<<endln;
	delSinglyLinkedList(&head);
	print(head) ;
}  
