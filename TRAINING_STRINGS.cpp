#include <bits/stdc++.h>
//#include <string> 
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

// 1. Different Ways to get input :
//	cin stops at any white spaces thus reading only a single word
//	cin.getline() reads input up to '\n' and stops
//	cin.get() reads input up to '\n' and keeps '\n' in the stream

// 2. char* vs std:string vs char[] 
// 	a) char* str, str is basically a pointer to the (const)string literal.
//		Syntax:
//			char* str = "Hello World!";
//			cout<<str<<endln; 				// will give actually Hello World! ,
//		Why  it prints Hello World! ? and not H ? coz cout being an overloaded function is defined that whenever it recives char* , it will print it in C-style string fashion
//		If you want only first , do cout<< (void *) str<<endln;
//		Note that since rval is a const , so we need const char* , howerv not necc but we get a compiler warning if we dont do so
//
//	b) string str ="Hello World!"; OR string *str = new string ("Hello World");
//		Here str is the object of std::string class which is an instantiation of the basic_string class template that uses char (i.e., bytes) as its character type
//		So basically YOUR STRING IS KINDA AN ADT BUT IS PRE-DEFINED 
//	c) char str[] = "This is GeeksForGeeks";
//    					 or 
//	   char str[size] = "This is GeeksForGeeks";
// 

// The most basic problem of Strings is substrings in order 


//class A{ 
//	public: 
//	int data ;
//	string s;
//	A (int data){
//		this->data=data;
//	} 
//	A(string s){
//		this->s=s;
//	}
//};
//	A a = 2 ;
//	string s = "meeri billi";
//	a= s;
//	a="hehe" ; will give errror coz u r passsing a const char literal to a object which has no idea what it is , 
//				unless u define a constructor in it which can take A(const char [] ) , this shall work
//	cout<<a.s;

//typedef string* String ;

// “”, ”b”, ”o”, ”y”, ”bo”, ”oy”, ”boy”
// Total no. of strings is : n+n-1+... 2+1=n(n+1)/2
void Substrings(string s, int n ){ 
	cout<<"subs = "<<endln; // assumes empty subst as subst as well 
	fli(i,0,n){ // this is to get starting index
		char subs [n-i+1]; // we are creating a char array of size n-i+1 so taking all lengths from n+1(+1 becuase we will be adding null manually ) to 1 
		// n-i will do the work as well coz null gets added automatically 
		int subs_index= 0;
		fli(j,i,n){  // this is to get all subst from starting index(i) to a particalr length given by j+1
			subs[subs_index++] = s[j] ;
			subs[subs_index] = 0 ; // 0 is same as null char and if we dont add it then we will get garbage char as remining char when we print char array whose size of its contents is less than its actual size
			deb(subs) ;
		} 
	} 
}

// ”ga”, ”gar”, ”gard”, ”garde”, “garden” 
void PrefixSubstrings(string s, int n){
	cout<<"sub = "<<endl; // assumes empty subst as subst as well 
	char sub[n+1];
	fli(j,0,n){
		sub[j]= s[j] ; 
		sub[j+1]=0 ;
		cout<<"sub = "<<sub<<endl;
	}			
}

void SuffixSubstrings(string s, int n){
	cout<<"sub = "<<endln; // assumes empty subst as subst as well 
	char sub[n];
//	int index = n;
	fld(i,n-1,0){
		sub[i]=s[i]; 	
		cout<<"sub = ";
		fli(j,i,n+1) cout<<sub[j];
		cout<<endln;
	}		 
}

int main(){  
	string s ;
	getline(cin,s) ; 
//	cin
	cout<<"Substrings are: "<<endln;
	Substrings(s,s.size()) ;
	cout<<"Prefix Substrings are: "<<endln;
	PrefixSubstrings(s,s.size());
	cout<<"Suffix Substrings are: "<<endln;
	SuffixSubstrings(s,s.size());
	return 0;
}
