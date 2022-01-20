#include <bits/stdc++.h>

#define deb(x) cout << #x << " = " << x << endl
#define endln '\n'

using namespace std;

struct node {
	int item ;
	node *nxt ;
	node (int item , node *t ){
		this->item =item;
		(*this).nxt = t ;
	}
};

void insertList (node*& head ,node* temp,int pos){
	if(pos==1){
		temp->nxt = head ;
		head = temp ;
		return ;
	}
	node* curr = head ;
	for (int i =0;i<pos-2;i++){
		curr= curr->nxt  ;
		if(pos!=i+3 && curr->nxt == nullptr ){
			cout<<"Memory Overflow"<<endl;
			return ;
		}
	}
	temp->nxt = curr->nxt ;
	curr->nxt = temp ;
}

void printList(node* head){
	if(head ==nullptr){
		cout<<"Linked List is empty"<<endln;
		return ;
	}
	node* curr = head ;
	while(curr!=nullptr){
		deb(curr->item);
		curr = curr->nxt ;
	}
}

void delList(node*& head ,int pos){
	if(pos==1){
		node* temp = head ;
		head = head->nxt;
		delete temp ;
		return ;
	}
	node* curr = head ;
	for(int i =0;i<pos-2;i++) 
	for (int i =0;i<pos-2;i++){
		curr= curr->nxt ;
		if(curr==nullptr && i!=pos-3){
			cout<<"Memory Overflow"<<endln;
			return;
		}
	}
	node* temp = curr->nxt ;
	curr->nxt=curr->nxt->nxt;
	delete temp ;
}

void delSinglyLinkedList(node* & head ){
	while( head !=nullptr){
		node* temp = head ;
		head = head->nxt ;
		delete temp ;
	}
}

void solve(node* &head){
	if(head==nullptr) return;
	node* odd = head, *even = head->nxt;
	node* oddhead=head,*evenhead=head->nxt;	//	int i=0;
	while(odd->nxt!=nullptr && even->nxt!=nullptr ){ 
		odd->nxt=odd->nxt->nxt;
		even->nxt=even->nxt->nxt;
		odd=odd->nxt;
		even=even->nxt;
	}  
	deb(odd->item);
	if(odd->nxt!=nullptr) odd->nxt=nullptr; 
	odd->nxt=evenhead; 
}

int main() {
	node* head ;
	int n ;cin>>n ; 
	for (int i =0;i<n;i++){
		int x ; cin>> x;
		insertList(head,new node (x,0), i+1) ; 
	}
	printList(head);
	cout<<"ODD/EVEN "<<endln;
	solve(head);
	printList(head);
	delSinglyLinkedList(head);
}

