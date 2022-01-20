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
#define deb(x) cout << #x << " = " << x << endln
#define endln '\n'
#define null nullptr

using namespace std;

// Circular LL
struct Node {
	int item;
	Node* next;
	Node(int x,Node* next){
		this->item=x;
		this->next=next;
	}
};

typedef Node* link ;

void insertAtHead (link &head,link node){
	if(head==null){
		node->next= node;
		head= node ;
		return ;
	}	
	link curr = head;
	while(curr->next!=head) curr=curr->next;
	curr->next=node;
	node->next=head;
	head=node;
}

// for traversing the circular linked list you need to start from next node of head and traverse it 
// until you find head in a cirulcar dirn back again 
// A good alternative is you can start from head and traverse it using do while loop 
// coz it will  help u to get loop executed even loop's condition is met 
 
void print (link &head){
	if(head==null)
		return ;
	link curr = head;
	deb(head->item);
	curr=curr->next;
	while(curr!=head) deb(curr->item),curr=curr->next;
}	

int CountNodes (link head){
	if (head==null) return 0;
	link curr = head->next ;
	int count = 1;	
	while(curr!=head) count++,curr=curr->next;
	return count ;
}

void insertAtTail (link &head,link node){
	if(head==null){
		node->next= node;
		head= node ;
		return ;
	}	
	link curr = head;
	while(curr->next!=head) curr=curr->next;
	curr->next=node;
	node->next=head;
}

void delAtHead(link &head){ 
	if(head==null) return;
	link curr= head->next;
	while(curr->next!=head) curr=curr->next;
	curr->next=head->next;
	link temp = head;
	head->next=null;
	head= curr->next;
	delete temp;
}

void insertAtPos(link& head,link node,int pos){
	if(head==null){
		head=node;
		node->next=node;
		return;
	}
	if(pos==1){
		insertAtHead(head,node);
		return ;
	}  
	int i =2;
	for (link curr=head;curr->next!=head;i++,curr=curr->next){
		if(i==pos){
			node->next=curr->next;
			curr->next=node;
			return;
		}
	} 
	if(i==pos){
		insertAtTail(head,node);
		return;
	}
	cout<<"Memory Overflow"<<endln;
}

int main(){
	link head = null;
	link node = new Node (1,0);
	insertAtHead(head,node);
//	delAtHead(head);
	link node1 = new Node (2,0);
	insertAtHead(head,node1);
	link node2 = new Node (3,0);
	insertAtHead(head,node2);
	print(head);
	cout<<CountNodes(head)<<endln;
	cout<<endln;
	fli(i,4,21){
		insertAtHead(head,new Node(i,0)) ;
	}
	print(head);
	cout<<CountNodes(head)<<endln;
	cout<<endln;
	fli(i,1,12){
		insertAtTail(head,new Node(1-i,0)) ;
	}
	print(head);
	cout<<CountNodes(head)<<endln;
//	delAtHead(head);
//	delAtHead(head);
//	delAtHead(head);
	insertAtPos(head,new Node(100,0),1);
	insertAtPos(head,new Node(100,0),3);
	insertAtPos(head,new Node(100,0),5);
	insertAtPos(head,new Node(100,0),7);
	insertAtPos(head,new Node(100,0),36);

	cout<<endln;
	print(head);
	cout<<CountNodes(head)<<endln;

	
	return 0;
}
