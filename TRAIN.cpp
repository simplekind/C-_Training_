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
#define pop pop_back
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

using namespace std;

struct node {		
	int item ;
	node *nxt ;
	node (int item , node *t ){
		this->item =item;
		(*this).nxt = t ;
	}
}; 

typedef node *link ; 

void insert (link& head ,link temp,int pos){
	if(pos==1){
		temp->nxt = head ; 
		head = temp ; 
		return ;
	}
	link curr = head ;
	for (int i =0;i<pos-2;i++){
		curr= curr->nxt  ;
		if(pos!=i+3 && curr->nxt == NULL ){
			cout<<"Memory Overflow"<<endl;
			return ;
		}
	} 
	temp->nxt = curr->nxt ;
	curr->nxt = temp ;
}
 
void print(link head){
	link curr = head ;
	while(curr!=NULL){
		deb(curr->item);
		curr = curr->nxt ;
	}
}

int main() {
	link head = new node (1,0) ;  
	for (int i =0;i<16;i++){
		link temp =  new node (i,0) ;		
		insert(head,temp,i) ;
	}	
	link curr = head;
	link temp =  new node (100,0) ;		
	insert(head, temp,1);
	print(head) ;
}  
