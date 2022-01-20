#include <bits/stdc++.h>

#define fli(i,a,b) for(auto i=a;i<b;i++)
#define fld(i,a,b) for(auto i=a;i>=b;i--)
#define llfli(i,a,b) for(auto i=a;i<b;i++)
#define llfld(i,a,b) for(auto i=a;i>b;i--)
#define test int s2; cin>>s2;while(s2--)
#define lltest ll s2; cin>>s2;while(s2--)
#define fla(v,i) for(auto i: v)
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
const int m = 1000000007;
using namespace std;

// A common misconception to clear is that using DP doesnt mean that we are using array all the tim3
// DP basically means to use prev result to calculate next result , 
// Its upto you how you store the result .
// 3 diff ways :-

// 1. Use a var to keep only the reqd max/min value ( kadane's algo) 
// 2. A 1-D/2-D array to keep track of stored values for particular soln of 1-D /2-Darray / memoization
// 3. A 2-D array for same  										 / TABULATION 

// DP -> coin 
// Coin prob 
// Rec approach 
int coinSearchRec(vector<int> coins,int x){
	// Base Case
	if(x<1) return 0 ;
	int ans = inf ;
	fla(coins,i){
		if(x-i>=0)
			ans = min(ans,1+coinSearchRec(coins,x-i)) ;
	}
	return ans ;
}
// Below 2 codes are to identify no. of min coins to sum up to make the denomination
// Rec using mem 
int coinSearch(vector <int> coins ,int x, int *arr){
	if(x==1) return 1 ; 
	if(x==0) return 0 ; 
	if(x<0)  return inf ; 
	if(arr[x]) return arr[x] ; 
	
	int out = inf ;
	for_it(coins,it) out = min(out,1+coinSearch(coins,+x- (*it),arr)) ; 
	arr[x] = out; 
	return out;  
}

void coinSearch(vector <int> coins , int x){
	int *arr = new int [x+1] ; 
	fli (i,0,x+1) arr[i] = 0 ;
	int out = coinSearch(coins,x, arr) ; // x+1 size to handle the case for x  =  0 as well 
	cout<<out<<endln;
	delete [] arr ;
}

void coinSearchiT(vector <int> coins , int x){
	int* arr = new int [x+1] ;
	arr[0] = 0 ;
	fli(i,1,x+1){
		arr[i] = inf ;
		for_it(coins,it) 
			if(i - (*it) >= 0)	// hanldes if denom value is lesser than coin val to avoid neg nos. 
				arr[i] = min (arr[i],arr[i-(*it)]+1) ; 
	} 
	cout<<arr[x]<<endln ; 
	delete [] arr ;
}

// Below 2 codes are to identify those coins whose total no .of min coins to sum up to make the denomination
// Idea is to have a an array named first[x] by name it suggest stores the first coin for ith used to make/ appeared in sum of i
// Lets say i=10, so we need to print sum= 3+3+4  ;
// first [10] = 3 // lowest/first coin to appear 
// now we have printed 3 out of 3,3,4 , we need to print 3,4 bascially we did 10 - 3 = 7
// so now we need first [7 ]  = 3
// now we need to print first [ 7- first[7]] = first [4] = 4
// At last we printed 3,3,4 just by storing first values , 
// we basically used old values to print current vlaue  

int coinSearchPrint(vector <int> coins , int x , int * arr, int *first){
	if(x==1) return 1 ; 
	if(x==0) return 0 ; 
	if(x<0)  return inf ; 
	if(arr[x]) return arr[x] ; 
	
	int out  = inf ;	
	for_it(coins,it){
		if(x - (*it) >=0 ) {
			out = min (out,1+coinSearchPrint(coins,x-(*it),arr,first)) ; 
			first[x] = (*it) ; 
		}
	} 
	arr[x] = out ;
	return arr[x] ; 
}

void coinSearchPrint(vector<int> coins,int x){
	int arr[x+1] ,first[x+1] ; 
	fli(i,0,x+1) arr[i] = 0 ;
	fli(i,0,x+1) first[i] = 0 ;
	arr[0] = 0 ;
	arr[1] = 1 ;
	coinSearchPrint(coins,x,arr,first) ; 
	first[0] = 0 ;
	first[1] = 1 ;
	
	int sum = x ;
	while(sum >=1){
		cout<<first[sum]<<" ";
		sum-=first[sum]; 
	} 
	cout<<endln;
} 

void coinSearchPrintiT(vector<int> coins,int x){
	int* arr = new int [x+1] ; 
	int * first = new int [x+1] ; 
	arr[0]=0;
	arr[1]=1;
	first[0]=0;
	first[1]=1;
	fli(i,1,x+1){
		arr[i] = inf ;
		first[i]=  _inf ; 
		for_it(coins,it){
			if(i-(*it)>=0){
				arr[i] = min (arr[i],1+arr[i-(*it)])  ;
				first[i] = max(first[i],(*it))  ;
			}
		}
	} 
	
	int sum = x ;
	while(sum >=1){
		cout<<first[sum]<<" ";
		sum-=first[sum]; 
	} 
	cout<<endln;
}

// All no. Solutions using  rec

int printHelper(vector<int>coins, int x,int *arr){
	if(x==1) return 1 ;
	if(x<=0) return 0 ;
	if(arr[x]) return arr[x] ; 
	
	int ans = 0;
	for_it(coins,it){
		ans+=printHelper(coins,x-(*it),arr)  ;
	} 
	arr[x] = ans%m ;
}

void printAllCoinSol(vector<int>coins, int x){
	int * arr =new int [x+1];
	fli(i,0,x+1) arr[i]= 0; 
	arr[0] = 1 ;
	arr[1] = 1 ;
	printHelper(coins, x,arr) ; 
	cout<<arr[x]<<endln;
	return;
}
 
// All Solutions using  it
void printAllCoinSolIT(vector<int>coins,int x){
	int* arr = new int [x+1] ; 
	fli(i,0,x+1) arr[i] = 0 ;
	arr[0] = 1 ;
	fli(i,1,x+1){
		for_it(coins, it){ 
			if(i-(*it)>=0)
				arr[i]+=arr[i-(*it)],arr[i];
			arr[i]%=m ; 
		}
	} 
	cout<<arr[x]<<endln;
}

// fibo
//// THis is memoization in O(n)
//ll fib(int n ,ll* arr){
//	// base case 
//	if(n<=1) return n ;
//	
//	ll n_1 ,n_2; 
//	
//	if (arr[n-1]) n_1 = arr[n-1] ;
//	else{
//		n_1 = fib ( n-1 ,arr) ;
//		arr[n-1] = n_1  ; 
//	}
//	
//	if (arr[n-2]) n_2 = arr[n-2] ;
//	else{
//		n_2 = fib ( n-2 ,arr) ;
//		arr[n-2] = n_2 ; 
//	} 
//	
//	return n_1 + n_2 ; 
//}
//
//// THis is bottom up 
//void fib(int n){
//	
//	ll* arr = new ll [n+1] ;
//	fli(i,0,n) arr[i] = 0 ; 
//	arr[0] = 0 ;
//	arr[1] = 1 ;
//	fli(i,2,n+1) arr[i] = arr[i-1] + arr[i-2]  ;
//	cout<<arr[n]<<endln;
//} 

// Backtracking for grid Search
// Time Complexity is O(2^n) coz every function is calling 2 functions
void gridSearchBackTrackHelper(int** arr,int r,int c,int currX,int currY,int currSum, int& maxSum){
	// Base Case 
	if(currX==r-1 && currY==c-1){
		currSum+=arr[currX][currY] ;
		maxSum= max(currSum,maxSum);
		return ;
	} 
	// func body
	if(currX<r-1){
		currSum+=arr[currX][currY];
		gridSearchBackTrackHelper(arr,r,c,currX+1,currY,currSum,maxSum) ;
		currSum-=arr[currX][currY];
	}
	if(currY<c-1){
		currSum+=arr[currX][currY];
		gridSearchBackTrackHelper(arr,r,c,currX,currY+1,currSum,maxSum) ;
		currSum-=arr[currX][currY];
	}
}

int gridSearchBackTrack(int ** arr , int r ,int c){
	int maxsum = _inf ;
	gridSearchBackTrackHelper(arr,r,c,0,0,0,maxsum) ;
	return maxsum ;
} 

// Using Iterative DP 
int gridSearchitDP(int ** arr , int r ,int c){
	int **sum = new int *[r] ;
	fli(i,0,c) sum [i]= new int [c] ;
	sum[r-1][c-1] = arr[r-1][c-1] ; 
	fld(i,r-2,0)
		sum[i][c-1] = sum[i+1][r-1] + arr[i][r-1] ; 
	fld(i,c-2,0)
		sum[r-1][i] = sum[r-1][i+1] + arr[r-1][i] ; 
	fld(i,r-2,0)
		fld(j,c-2,0)
			sum[i][j] = arr[i][j] + max(sum[i+1][j],sum[i][j+1]) ;
	return sum[0][0] ;
} 

// MAX 2-D SUM ARRAY using DP by creating a 1-D arry 
// So idea is :

// 1 Create a 1-D array that will store sum of recatngular matrix from a sub-rectangular matrix from Left to Right for all rows.
// 2 Take 2 pointers L and R and move them with n^2 complexity over all colms of matrix
// 3 For each rectangle b/w L and R keep compute of sum of whole rectangle by storing it in DP from point no. 1
// 4 Using Kadane find out max sum array in DP array, this will tell top and bottom of rectangle and you already have L and R
// 5 Thus now you have maxSum 

int maxSum2Darr(int** arr, int r , int c){
//	int maxL=0,maxR=0,maxU=0,maxD=0 ; 
	int maxRecSum = _inf ;
	// 2 L   
	fli(i,0,c){
		// 1 
		int *dp = new int [r] ;
		fli(k,0,r)
			dp[k] = 0;
		// 2 R
		fli(j,i,c){
			// 3 
			fli(k,0,r)
				dp[k]+=arr[k][j] ; 
			// 4 
			int currSum = 0 ,maxSum=_inf ;
			fli(k,0,r) {
				currSum+=dp[k] ;
//				deb(currSum) ;
				maxSum=max(currSum,maxSum) ;
//				deb(maxSum);
				currSum=max(currSum,0) ; 
			} 
//			deb(maxRecSum);
			maxRecSum = max(maxRecSum,maxSum) ;
		} 
		delete [] dp ;
	}
	return maxRecSum ;
} 

// BitMasking Technique for DP (see mislaneous to understand its concept ) USED FOR FINDING REQD PERMUTATION
// So the problem is given 3 person and 3 candies with given that whether that person like that candy or not
// eg : let p1,p2,p3 and c1,c2,c3
// 		c1 c2 c3
// p1	1  1  1
// p2	1  0  1
// p3	1  1  1 
// So tell no. of ways we can distrubute them 
// eg(from above):- c1,c3,c2; 	c2,c1,c3; 	c2,c3,c1;	c3,c1,c2 =>	4
//
//	Solution :- 
//	Lets put a mask on these bits :- 
//	c3	c2	c1	 as 1/0 1/0 1/0 giving us 8 possibilities 
//	such that if there are n bits and m bits are 1's then that means n-m persons are given to canides and left over candie's number is represented by 0
//	So here we would be fousing on left over 0's to see that the position(lets say i) at which bit is 0 meaning Ci and we have to check if Ci can be given to (n-m+1)th person or not ,
//	if yes , then we will increment count for that particular bitset by filling 1 at ith bit . Or we can say the ans will be same as count for that particular bitset by filling 1 at ith bit
//	And what it suggests:-
//	111	-> p1,p2,p3 all are given candies 	as 	c3	c2 c1	so count = 1
//	110	-> c3 & c2 are given candies to 2 p1 and p2 and we have to check to give c1 to p3 & yes we can , thus making 111 & count same as 111 , count=1
//	101	-> c3 & c1 are given candies to 2 p1 and p2 and we have to check to give c2 to p3 & yes we can , thus making 111 & count same as 111 , count=1
//	011	-> c2 & c1 are given candies to 2 p1 and p2 and we have to check to give c3 to p3 & yes we can , thus making 111 & count same as 111 , count=1
//	100	-> c3 		is given candy 	 to   p1 		and we have to check to give c2 or c1 to p2 , but we cant give c2 to p2 (left over given to p3) thus making 101 & so count same as 101 , count=1
//	010	-> c2 		is given candy 	 to   p1 		and we have to check to give c3 or c1 to p2 (left over given to p3) thus making 110 & 011 & so count same as 110 + 011 , count=2
//	001	-> c1 		is given candy 	 to   p1 		and we have to check to give c3 or c2 to p2 , but we cant give c2 to p2 (left over given to p3) thus making 101 & so count same as 101 , count=1
//	At Last:-
//	000	-> no candy is given ,so we have to give c1 or c2 or c3 to p1 (left over given to p1) , 100 or 010 or 001 ( now left over given to p2, and then left over given to p3) thus count(100) + count(010) + count(001)=1+2+1=4
//	If we see we covered all perumtations here
//														111	(o)
//												 c2        c1      c3
//												 /		   |		 \
//											  (o)		  (o)		 (o)		
//											101			  110		  011					p3
//										c3     c1  		c2  c3      c1     c2
//										/		\		/	\		/		\
//									  (o)		(o)    (x)  (o)   (o)		(x)
//									  001       100    100  010    010      001				p2
//									   c1		c3	         c2    c2        
//									   |		 |			 |		|		 
//
//									  000		000	        000	   000	 					p1
// Total Count => 4 

void candySolve(){
	int n =3 ;
	int ** arr = new int* [n];
	fli(i,0,n) arr[i] = new int[n] ;
	
	arr[0][0]=1;arr[0][1]=1;arr[0][2]=1;
	arr[1][0]=1;arr[1][1]=0;arr[1][2]=1;
	arr[2][0]=1;arr[2][1]=1;arr[2][2]=1;
	
	int * dp = new int [1<<n] ;	// size of 1000 = 8
	fli(i,0,(1<<n)-1) dp[i] =0;
	dp[(1<<n)-1] = 1 ;
	
	fld(i,((1<<n)-2),0){
		int person_id=0;
//		 counting no. of 1's in our bitmask (i)
//		int temp = i;
//		fli(j,0,n){
//			int last_bit_mask = (temp&1) ;
//			person_id+=last_bit_mask;
//			i/=2;
//		}

//		ALT
		person_id = __builtin_popcount(i);	// counts in log(n)
		fli(j,0,n){
			if(arr[person_id][j] && !((1<<j)&i))
				dp[i]+=dp[ i | (1<<j) ] ;
		}
	}
	cout<<dp[0]<<endln;
	delete [] dp ;
	fli(i,0,n) delete arr[i] ;
	delete [] arr ;
}

// 0/1 Knapsacks ( The logic of code is almost same as Coin prob )
// 1) Recursion O(2^n)
int knapsackRec(vector <int> wts,vector <int> cost, int w, int i ){
	// Base Case
	if(i<0 || w<0){
		return 0 ;
	}
	// Logic Code
	if(wts[i]<=w)
		return max(cost[i]+knapsackRec(wts,cost,w-wts[i],i-1),knapsackRec(wts,cost,w,i-1)) ;
	else
		return knapsackRec(wts,cost,w,i-1) ;
}

// 0/1 Knapsacks ( The logic of code is almost same as Coin prob )
// 2) Memoization O(n^2)
int knapsackRecmemHelper(int**arr, vector <int> wts,vector <int> cost, int w, int i ){
	// Base Case
	if(i<0 || w<0){
		return 0 ;
	}
	if(arr[i][w]>=0)
		return arr[i][w];
	// Logic Code
	if(wts[i]<=w){	
		int ans = max(cost[i]+knapsackRec(wts,cost,w-wts[i],i-1),knapsackRec(wts,cost,w,i-1)) ;
		arr[i][w] = ans ; 
		return ans ;
	}
	else{
		int ans = knapsackRec(wts,cost,w,i-1) ;
		arr[i][w] = ans ; 
		return ans ;
	}
} 

int ** newArr(int n,int m){
	int ** arr = new int* [n] ;
	fli(i,0,m) arr[i] = new int [m];
	return arr ;
}


int knapsackMemo(vector <int> wts,vector <int> cost, int w, int i ){
	int** arr = newArr(wts.size()+1,100) ;
	fli(i,0,wts.size()+1){
		fli(j,0,100){
			arr[i][j]=-1;
		}
	}
	int ans = knapsackRecmemHelper(arr,wts,cost,w,i) ;
	delete [] arr ;
	return ans ;
}

int knapsackIt(vector <int> wts,vector <int> cost, int w){
	int ** dp = newArr(wts.size()+1,w+1);
	fli(i,0,wts.size()+1) dp[i][0]=0;
	fli(i,0,w+1) dp[0][i]=0;
	fli(i,1,wts.size()+1){
		fli(j,1,w+1){
			if(j>=wts[i-1])
				dp[i][j]= max(cost[i]+ dp[i-1][j-wts[i-1]],dp[i-1][j]) ;
			else 
				dp[i][j]= dp[i-1][j] ;
		}
	}
	int ans= dp[wts.size()][w];
	return ans ;
}

int main(){ 
	
//	 yaar index represents ki iss sub problem ke liye kya ans hai !
	
	// FIBONACCI 
//  THis is memoization in O(n)
//	ll *arr = new ll [51]  ;
//	llfli(i,0,50) arr[i]=0; 	
//	arr[0]= 0ll ;
//	arr[1]= 1ll ; 
//	fli(i,0,50) cout<<i<<" ",deb (fib(i,arr)) ,cout<<endln; 	
	
//  THis is bottom-up in O(n)
//	fli(i,0,50) fib(i) ; 
	
	
	// COINS PROBLEM
//	vector <int> coins = {1,3,4};
//	cout<<endln<<"For no. of min coins Using rec we have : "<<endln;
//	fli(i,0,20) deb(i),coinSearch(coins,i) ;
//	cout<<endln<<"For no. of min coins Using it we have : "<<endln;
//	fli(i,0,20) deb(i),coinSearchiT(coins,i) ;
//	cout<<endln<<"For those actual print of no. of min coins Using rec we have : "<<endln;
//	fli(i,0,20) deb(i),coinSearchPrint(coins,i) ; 
//	cout<<endln<<"For those actual print of no. of min coins Using it we have : "<<endln;
//	fli(i,0,20) deb(i),coinSearchPrintiT(coins,i) ; 
//	cout<<endln<<"For Total no. of ways to use coins Using it we have : "<<endln;
//	fli(i,0,20) deb(i),printAllCoinSol(coins,i) ; 	
//	cout<<endln<<"For Total no. of ways to use coins Using it we have : "<<endln;
//	fli(i,0,20) deb(i),printAllCoinSolIT(coins,i) ; 	


	// MAX COST GRID PROBLEM
//	int ** arr = new int* [5];
//	fli(i,0,5) arr[i] = new int [5] ;
//	arr[0][0]=3;
//	arr[0][1]=7;
//	arr[0][2]=9;
//	arr[0][3]=2;
//	arr[0][4]=7;
//	
//	arr[1][0]=9;
//	arr[1][1]=8;
//	arr[1][2]=3;
//	arr[1][3]=5;
//	arr[1][4]=5;
//	
//	arr[2][0]=1;
//	arr[2][1]=7;
//	arr[2][2]=9;
//	arr[2][3]=8;
//	arr[2][4]=5;
//	
//	arr[3][0]=3;
//	arr[3][1]=8;
//	arr[3][2]=6;
//	arr[3][3]=4;
//	arr[3][4]=10;
//	
//	arr[4][0]=6;
//	arr[4][1]=3;
//	arr[4][2]=9;
//	arr[4][3]=7;
//	arr[4][4]=8;
//	
//	cout<<gridSearchBackTrack(arr,5,5)<<endln ; 
//	cout<<gridSearchitDP(arr,5,5) ; 
	
	
	//MAX-SUM 2-D ARRAY PROBLEM / MAX-RECTANGLE SUM PROBLEM 
	
//	int ** arr = new int* [4];
//	fli(i,0,5) arr[i] = new int [5] ;
//	arr[0][0]=2;
//	arr[0][1]=1;
//	arr[0][2]=-3;
//	arr[0][3]=-4;
//	arr[0][4]=5;
//	
//	arr[1][0]=0;
//	arr[1][1]=6;
//	arr[1][2]=3;
//	arr[1][3]=4;
//	arr[1][4]=1;
//	
//	arr[2][0]=2;
//	arr[2][1]=-2;
//	arr[2][2]=-1;
//	arr[2][3]=4;
//	arr[2][4]=-5;
//	
//	arr[3][0]=-3;
//	arr[3][1]=3;
//	arr[3][2]=1;
//	arr[3][3]=0;
//	arr[3][4]=3;
//	
//	cout<<maxSum2Darr(arr,4,5) ;
	
//	candySolve();
	int n ;cin>>n;vector<int> wts (n);fli(i,0,n)cin>>wts[i];
	vector<int> cost (n);fli(i,0,n)cin>>cost[i];
//	cout<< knapsackRec(wts,cost,50,n-1)<<endln ;
//	cout<< knapsackMemo(wts,cost,50,n-1)<<endln ;	
	cout<< knapsackIt(wts,cost,50)<<endln ;		
	return 0;
}
