#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
typedef vector<int> vi;
typedef vector<int> pi;
#define fli(i,a,b) for(auto i=a;i<b;i++)
#define fld(i,a,b) for(auto i=a;i>=b;i--)
#define llfli(i,a,b) for(auto i=a;i<b;i++)
#define llfld(i,a,b) for(auto i=a;i>b;i--)
#define test int s2; cin>>s2;while(s2--)
#define lltest ll s2; cin>>s2;while(s2--)
#define endln '\n'
//#define ll long long 
#define ld long double
#include <typeinfo>
#define pb push_back
#define pop pop_back
#define mp make_pair
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);cout<<fixed;srand(time(0));
#include <bits/stdc++.h>
#define F first
#define S second
#define intu unsigned int 
#define inf 0x3f3f3f3f
#define _inf 0xcfcfcfcf
#define in_arr(a,n) int n ;cin>>n;int a[n];fli(i,0,n)cin>>a[i];
#define in_vec(v,n) int n ;cin>>n;vector<int> v (n);fli(i,0,n)cin>>v[i];
#define cout_arr(a,n)  fli(i,0,n) cout<<a[i]<<" ";
#define for_it(v,it) for (auto it= v.begin(); it!=v.end();it++)
using namespace std;
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endln '\n'
int max (const int& x ,const int& y,const int& z){
	return  ( ( x>y ) ? ( (x>z) ? x : z ) : ( (y>z) ? y : z ) ) ;
}

int sieve ( bool prime[] , int n ) {
	fill_n(prime,n,1) ;		//	from <algorithm> 
	prime[0]=prime[1]= 0 ;
	
	fli(i,2,n+1)
		if(prime[i]) 	// base case for starting from 2
			for(int j  =  i*i ; j <=n;j+=i) //for (int j = i ; j*i<n;j++) prime[j*i] = 0 ; 
				prime[j] = 0 ; 
	
	int count_of_primes = 0 ;
	
	fli(i,0,n) 
		if(prime[i])	
			count_of_primes++;
			
	return count_of_primes;	
} 

int heads(){ 
	return rand() < RAND_MAX/2	; }

int main(int argc, char *argv [ ] ) {	
	int i,j,cnt;
//	int N = atoi(argv[1] ) , M = atoi (argv[2]) ; // argv[0] is the name of file name 
	int N ,M;
	cin>>N>>M;
	int *f = new int [N+1] ;
	fli(j,0,N+1) f[j]=0;
	for(i = 0;  i<M;i++,f[cnt]++){
		for (cnt= 0 , j =0 ; j<=N;j++) {
			if(heads()) cnt++;
		} 
	}
	for (j =0 ; j <=N ;j++){
		if(f[j]==0) cout<<".";
		for (i = 0;i<f[j];i+=10) cout<<"*";
		cout<<endln;
	}
}
