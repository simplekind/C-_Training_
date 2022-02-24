#include <bits/stdc++.h>
#define fli(i,a,b) for(auto i=a;i<b;i++)
#define fld(i,a,b) for(auto i=a;i>=b;i--)
#define llfli(i,a,b) for(auto i=a;i<b;i++)
#define llfld(i,a,b) for(auto i=a;i>b;i--)
#define lltest ll s2; cin>>s2;while(s2--)
#define endln '\n'
#define ll long long
#define ld long double
#define pb push_back
#define popb pop_back
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);cout<<fixed;srand(time(0));
#define intu unsigned int
#define inf 0x3f3f3f3f
#define _inf 0xcfcfcfcf
#define in_arr(a,n) int n ;cin>>n;int a[n];fli(i,0,n)cin>>a[i];
#define in_vec(v,n) int n ;cin>>n;vector<int> v (n);fli(i,0,n)cin>>v[i];
#define cout_arr(a,n)  fli(i,0,n) cout<<a[i]<<" ";
#define for_it(v,it) for (auto it= v.begin(); it!=v.end();it++)
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x,y) cout << #x << " = " << x << " , "<<#y << " = " << y <<endl
#define endln '\n'
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define sortall(x) sort(all(x))

using namespace std;

typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

int mpow(int base, int exp) ;

const int mod = 1000000007;

// THE DIVIDE AND CONQUER WORKS JUST LIKE REC TREE CODE 
// WE FIND FOR LEFT PART
// THEN FIND FOR RIGHT PART
// DO IT UNITL U GET TO THE BASE CASE AND IT WILL RETURN THE VALUE
// USE THAT VALUE TO DETERMINE THE REQD CONDN
// KEEP ON RETURNING THAT NEW VALUE (GOT FROM CONDN) AND COMPUTE IT AGAIN FOR CONDN
// DO RETURN UNTIL U GET UR STARTING CONDN



// TEMPLATE FOR DIVIDE AND CONQUER in middle
//template<typename item, typename Return_t>
//Return_t solve (item*arr, int l , int r ){
//	if (r>=l) return arr[r]; // if u arent returning void else just return void
//	int m = l + (r-l)/2;
////	solve(arr,l,m) ;
////	solve(arr,m+1,r) ;
//// 	This is same as :- 
//	function_to_use(solve(arr,l,m),solve(arr,m+1,r))
//}
// eg:- B.S , Merg n srt , Quicksort , Closest Pair of Points


// The divide and conquer to find the max 
template <typename item> 
item maxInArr(item* arr,int l , int r){
	// so the plan is to keep on dividin our arrays into left and right and return back the max
	// its like normal rec we used to do.
	if (r<=l){
		return arr[r];
	}
	int m = l + (r-l)/2 ;
	return max(maxInArr(arr,l,m),maxInArr(arr,m+1,r)) ;
}

// returning index
int maxinArrIt (int * arr,int l , int r){
	if(r<=l || r<0) return -1;
	int maxEle = _inf,maxIndex=-1;
	for(int size = 1 ; size <r ; size = (1<<size))
		for (int pos = 0 ; pos<r ; pos+=(1<<size))
			if(maxEle<=arr[pos])
				maxEle=arr[pos],maxIndex=pos;
	return maxIndex;
}

//DIVIDE N CONQUER FOR TOWER OF HANOI 
// This problem is essence of recursion and helps to know how to think of basic rec soln
// 1) Show f(1) works	// base case
// 2) Assume f(n-1) works
// 3) Show f(n) works
// Source for Tower Of Hanoi :-
// https://www.youtube.com/watch?v=rf6uf3jNjbo
void tower(int& count ,int n , char start, char helper, char end){
	count++;
	// 1) Base case 
	if(n==1){
		cout<<"Move Disk #"<<1<<" from "<<start<<" to "<<end<<endln;
		return ;
	}
	// 2) Now we need to assume it workds for n-1
	tower(count,n-1,start,end,helper) ;
	cout<<"Move Disk #"<<n<<" from "<<start<<" to "<<end<<endln;
	tower(count,n-1,helper,start,end) ;
}
// Talking about time complexity : -
// First calls 2 function
// each of those 2 calls 2 more making 4 calls
// each of 4 calls makes 2 calls, making 8 calls
// each of 8 calls makes 2 calls, making 16 calls
// Thus at the end for n, we have 2^2(n-1) calls
// Total calls = 1+2+4+...+2^N-1 = 2^N - 1 
// Thus we can come up with a conclusion that 
// for n=3, we have 2^3-1=7 moves
// for n=4, we have 2^4-1=15 moves
// ...
// for n=10, we have 2^10-1=1023 moves
// At last time complexity = O(2^n)
// Space complexity = O ( height of tree ) = O(n)

// More about D n C is in Merge Sort , Binary Search

int main(){
	int t =1;
	while(t--){
// 		This is for eval max in int	
		int n =32;
		int * arr = new int [n] ;
		srand(time(0));
		fli(i,0,n) arr[i]= rand()%100+1;
		fli(i,0,n) cout<<(arr[i])<<" ";	
		cout<<endln;	
		cout<<"at posn "<<maxinArrIt(arr,0,n-1)<<" the value is "<<arr[maxinArrIt(arr,0,n-1)]<<endln;
//		
// 		This is for eval max in char
//		cin>>n;
//		char * arrch = new char [n] ;
//		fli(i,0,n) cin>>arrch[i];
//		cout<<maxInArr(arrch,0,n-1);
//		int n ; cin>>n;
//		int count = 0;
//		tower(count,n,'a','b','c') ;
//		cout<<count<<endln;
	}
	return 0;
}


int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
