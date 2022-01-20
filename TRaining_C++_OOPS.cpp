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
#define forll(h,i) for (link i = head;i!=0;i=i->nxt)
#define null nullptr

using namespace std ;

// We need OOPS for client-interface implementation and ADT

struct node {
	private :
		int item ;
		node *nxt ;
		// now class point can acces members of node !
		friend class point ;
	public :
	node (int item , node *t ){
		this->item =item;
		(*this).nxt = t ;
	} 
	friend void insertList (node*& head ,node* temp,int pos) ;
	friend void printList(node* head) ;
	friend void delList(node*& head ,int pos) ;
	friend void delSinglyLinkedList(node*& head ) ;
};

typedef node *link ;

void insertList (link& head ,link temp,int pos){
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

void printList(link head){
	if(head ==null){
		cout<<"Linked List is empty"<<endln;
		return ;
	}
	link curr = head ;
	while(curr!=NULL){
		deb(curr->item);
		curr = curr->nxt ;
	}
}

void delList(link& head ,int pos){
	if(pos==1){
		link temp = head ;
		head = head->nxt;
		delete temp ;
		return ;
	}
	link curr = head ;
	fli(i,0,pos-2){
		curr= curr->nxt ;
		if(curr==null && i!=pos-3){
			cout<<"Memory Overflow"<<endln;
			return;
		}
	}
	link temp = curr->nxt ;
	curr->nxt=curr->nxt->nxt;
	delete temp ;
}

void delSinglyLinkedList(link& head ){
	while( head !=null){
		link temp = head ;
		head = head->nxt ;
		delete temp ;
	}
}

class point{
	private:
		int x;
		int y;
		friend float distance(point a,point b ) ;
	public:
		point(){
			x=1;
			y=1;
		}
		
		point(int x, int y){
			this->x=x;
			this->y=y;
		}
		
		int getX() const{
			return this->x;
		}
				
		int getY() const{
			return this->y;
		}
		
		void setX(int x) {
			this->x=x;
		}		
		
		void setY(int y) {
			this->y=y;
		}
		
		// Real Use of friend is to use operator overloading
		// when the following operator is used (== here)
		// It takes a on left side of binary operator (== here) and b on right
		// returns true/false
		friend bool operator == (point a,point b){
			return distance(a,b)<2;
		}
};

// Earlier we had to call the static func of distance inside point(that means we dont
// need an object of that class to be called .
// But a better approach could be by using a function not part of class but still 
// being able to access the private members of class
// F.R.I.E.N.D.S
// This means that this function being a friend of class point 
// allows you to access the private members of class point wihtout even also creating any object of that class!
float distance(point a,point b ){ 
	float dx  = a.x - b.x, dy = a.y-b.y;
	return (sqrt(dx*dx + dy*dy)) ;
} 
// it only lessens the value of encapsulation of separate classes in object-oriented programming.
// friendship is not inherited!

// takes an output  stream and then passes p in this stream and returns it
// This operator is not even a member function, nor even a friend: it uses the
// public member functions getX() and getY() to access the data.
ostream& operator << (ostream& t,point p){
	cout<<"Hey! x = "<<p.getX()<<" and y = "<<p.getY()<<endln;
	return t ;
} 

// So now after understanding basics of client-interface ways , we will now actually implement it
// 	POINT ADT INTERFACE
//class Point{
//	private:
//	public:
//		Point();
//		float distance(Point a, Point b) const;
//};
		
//	we use the C++ template mechanism
//	to write code that is generic with respect to types.
	
//template <class point>
		
int main(){ 
	point a , b;
	b.setX(1);
	b.setY(2);
	deb(distance(a,b));
	cout<<(a==b)<<endln;
	cout<<a;
	cout<<b;
	return 0;
}
