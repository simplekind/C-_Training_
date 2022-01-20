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

using namespace std;
//int solve_helper (vector<int> coins , int x,int * arr){
//	// BaSE CASE 
//	if(x==1)  return 1 ;
//	if (x==0)  return 0 ;
//	if (x<0)  return inf ;
//	if(arr[x]) return arr[x]  ;
//	
//	int ans = inf ;
//	
//	for(auto i: coins) {
//		ans = min (ans,1+ solve_helper(coins,x-i,arr)) ; 
//	}
//	arr[x] = ans ;
//	return ans ;
//}

int solve_helper(vector<int> code,int end  ){
	//  base case 
	if(end<=0) return 1 ;
	int ans = solve_helper(code,end -1) ;
	
//	cout<<end<<" "<<end-1<<" "<<end-2<<"	";
//	deb(ans) ;
//	for(int i=0;i<=end;i++) cout<<code[i]<<" ";
	if(end-2>=0 && (code[(end-2)*10] + code[end-1]) <=26){  
	 	ans+=solve_helper(code,end -2); 
	} 
//	cout<<endln<<endln;
	return ans ;
}
 
int solve(vector<int> code ){
	return solve_helper(code,code.size()-1) ;
}

int main(){
	vector<int> code = { 4,1,2,3 };
	cout<<solve(code);
}
