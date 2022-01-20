#include <bits/stdc++.h>
#define null nullptr

using namespace std;

struct node {		
	int item ;
	node *nxt ;
	node (int item , node *t ){
		this->item =item;
		(*this).nxt = t ;
	}
}; 

// utility function
//					passing by ref, pass by val,pass by val, pass by val
// 					We passed List head by ref , inorder to change list head when we 
//					want to insert at first position

node* insertAt_util (node* &ListHead,node* temp ,node* x,int pos){
	if(pos==2){
		if(temp!=null){
			x->nxt=temp->nxt;
			temp->nxt=x; 
		}	 
		return temp;
	} 
	if(pos==1){
		x->nxt= temp;
		ListHead = temp = x; 
		return temp;
	}
	if(temp==null){
		return temp;
	} 
	temp->nxt = insertAt_util(ListHead,temp->nxt,x,--pos);
} 


node* insertAt( node* &head ,node* x,int pos){
	insertAt_util(head,head,x,pos) ;
}

// Printing through recursion
void print(node* head){ 
	if(head ==null){
		return ;
	} 
	cout<<head->item<<" ";
	print(head->nxt);
}


int main() {
	node* head = new node (1,0) ;  
	for (int i =2;i<16;i++)
		insertAt (head ,new node (i,0),i) ;
	insertAt (head ,new node (100,0),4) ;
	insertAt (head ,new node (101,0),200) ;
	insertAt (head ,new node (100,0),1) ;
	insertAt (head ,new node (100,0),18) ;
	print(head) ;
}  
