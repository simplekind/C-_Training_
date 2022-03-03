#include <bits/stdc++.h>

#define fli(i,a,b) for(auto i=a;i<b;i++)
#define fld(i,a,b) for(auto i=a;i>=b;i--)
#define llfli(i,a,b) for(auto i=a;i<b;i++)
#define llfld(i,a,b) for(auto i=a;i>b;i--)
#define fla(v,i) for(auto i: v)
#define endln '\n'
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);cout<<fixed;srand(time(0));
#define intu unsigned int
#define inf 0x3f3f3f3f
#define _inf 0xcfcfcfcf
#define deb(x) cout << #x << " = " << x << endl
#define endln '\n'
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define sortall(x) sort(all(x))
#define vt vector

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
int ** newArr(int n,int m)  ;

const int mod = 1000000007;
struct node {
	int item ;
	node* l , *r;
	node(int item , node*l, node*r){
		this->item=item;
		this->l=l;
		this->r=r;
	}
};
typedef node* link;
#define null nullptr
// Counting number of binary trees using CATLAN NUMBERS AND DP
// Idea is for 3 noded binary: 
// left part will have 2 nodes and right 0 
// left part will have 1 nodes and right 1
// left part will have 0 nodes and right 2 
// So total combn: Bt(2)*Bt(0) + Bt(1)*Bt(1) + Bt(0)*Bt(2)
// This is called catlan numbers as this turns out to be 
// (2*3)!/((4!)(3!)) = 5
// basically (2n!)/((n!)(n+1)!) = 2nCn * 1/(n+1) 
// Formula is proved via Taylor series
class Solution {
public:
    vector<int>dp;
    Solution():dp(20,0){}
    int numTrees(int n) {
        if(n==0) return 1;
        int ans = 0;
        if(dp[n]) return dp[n];
        for (int i =0;i<n;i++)
            ans+=numTrees(n-i-1)*numTrees(i);
        dp[n]=ans;
        return ans;
    }
    
    vector<link> helper(int start,int end){
        // base case
        if(start>end){
            vector<link> v ={null};
            return v;
        }
        vector<link> ans;
        for(int i = start;i<=end;i++){
            vector<link> vl = helper(start,i-1);
            vector<link> vr = helper(i+1,end);
            for (link l: vl){
                for (link r: vr){
                    link root = new node(i,0,0);
                    root->l=l;
                    root->r=r;
                    ans.push_back(root);
                }            
            }
        }
        return ans;
    }
    
    vector<link> generateTrees(int n) {
       return helper(1,n);
    }
};

// some questions to look out for
/// https://leetcode.com/submissions/detail/650073927/
/// https://leetcode.com/submissions/detail/650034768/
/// https://leetcode.com/submissions/detail/652449293/

void solve(){

}

int main(){
	fastio
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	int t ; cin >> t;
	while(t--){
		solve();
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

int ** newArr(int n,int m){
	int ** arr = new int* [n] ;
	fli(i,0,m) arr[i] = new int [m];
	return arr ;
}

