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

// 0*x+ (x-1 +x-2) + (x-2 + x-3) + (x-3 + x-4) + (x-3 + x-4) + (x-4+x-5) + .. . 
// 0*x + x-1 + 2*(x-2) + 3*(x-3) +4*(x-4) ... (x-1)*(1)
// 0*x 	  + S0
// 1*x-1  + S1
// 2(x-2) + S2
// 3(x-3) + S3
// 4(x-4) + S4

// (x-2)2 + S(x-2)
// S(x-2) = x-1    + S(x-1)
				 // where y is always equals to x
int solve(int x,int y){
	// base case 
	if(x<0) return 0 ;
	
	return x*(y-x) + solve(x-1,y) ; 
}

// x + (x-1 +x-2) + (x-2 + x-3) + (x-3 + x-4) + (x-3 + x-4) + (x-4+x-5) + .. . 
// x-1+x-2 + S0 + S1 
// 
int solve_fast_quesmark(int x1,int x2){
	// base case 
	if(x1<0 || x2<0) return 0 ;	
	return x1+x2+solve_fast_quesmark(x1-1,x1-2)+solve_fast_quesmark(x2-1,x2-2) ; 
} 


using namespace std;
// 4 + 3*2 + 2*3 + 1*4 = 4+ 6+ 6+4 = 20
// 5*1 + 4*2 + 3*3 + 2*4 + 1*5 = 5+8+9+8+5=35 !
int main(){
	cout<<solve_fast_quesmark(5,4)<<endln;
	cout<<solve(6,6);
	return 0;
}
