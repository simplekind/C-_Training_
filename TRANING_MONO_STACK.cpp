#include <bits/stdc++.h>

#define fli(i,a,b) for(auto i=a;i<b;i++)
#define fld(i,a,b) for(auto i=a;i>=b;i--)
#define llfli(i,a,b) for(auto i=a;i<b;i++)
#define llfld(i,a,b) for(auto i=a;i>b;i--)
#define fla(i,v) for(auto i: v)
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
#define deb2(x,y) cout << #x << " = " << x << " , "<<#y << " = " << y <<endl
#define endln '\n'
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define sortall(x) sort(all(x))
#define vt vector
#define m 1000000007
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

template <typename t> // cin>> vector<t>
istream &operator>> (istream &istream, vt<t> &v){
	for (auto & i : v) cin>>i;
	return istream;
}

template <typename T> // cout << vector<t>
ostream &operator<<(ostream &ostream, const vector<T> &c){
	for (auto &i : c)
		cout << i << " ";
	return ostream;
}

// MONO Stacck:
// 
// It finds prev/next less/great (basically in monotonous order) ele of each ele in a given vector A in O(n) time
//
// a typical way of solving mono stack prob
//	for(int i = 0; i < A.size(); i++){
//	  while(!in_stk.empty() && in_stk.top() > A[i]){
//	    in_stk.pop();
//	  }
//	  in_stk.push(A[i]);
//	}
//
// we generally push index instead of ele  it helps in avoiding duplicate cases and somtimes to calculate lengths
// 
// 1 ) STORING PREV LESSER ELEMENT  FOR EACH ELEMENT IN A VECTOR
//
// previous_less[i] = j means A[j] is the previous less element of A[i].
// previous_less[i] = -1 means there is no previous less element of A[i].
//	vector<int> previous_less(A.size(), -1);
//	for(int i = 0; i < A.size(); i++){
//	  while(!in_stk.empty() && A[in_stk.top()] > A[i]){
//	    in_stk.pop();
//	  }
//	  previous_less[i] = in_stk.empty()? -1: in_stk.top();
//	  in_stk.push(i);
//	}
//
// 2 ) STORING NEXT LESSER ELEMENT  FOR EACH ELEMENT IN A VECTOR
//
// next_less[i] = j means A[j] is the next less element of A[i].
// next_less[i] = -1 means there is no next less element of A[i].
//	vector<int> previous_less(A.size(), -1);
//	for(int i = 0; i < A.size(); i++){
//	  while(!in_stk.empty() && A[in_stk.top()] > A[i]){
//	    auto x = in_stk.top(); in_stk.pop();
//	    next_less[x] = i;
//	  }
//	  in_stk.push(i);
//	}
//
// you can try some other vars like next greater and prev greater
// Just try this one , it contains all varities
// https://leetcode.com/problems/sum-of-subarray-ranges/

// https://leetcode.com/problems/largest-rectangle-in-histogram/
// Use stack to store incr order
//
// if curr height is lesser than the height present in the top of stack then pop the heights from stack until you get height lower than the curr height, and while popping out elements keep on calc area
//          Calc for area:- 
//                      take out the top most element from the stack and while popping out elements calc the area with them
//
// else just add it to the stack
// 
// If stack is already empty then when you took out the top most element from stack then area = height*(curr index) beacause that means all elements before than curr index are greater than curr index
//

//https://leetcode.com/problems/sum-of-subarray-minimums/submissions/

void prevsmaller(vector<int>& v, vector<int>& prevSmaller){
    int n = v.size();
    stack<int> s ;
    for ( int i =0 ;i<n;i++){
        while(!s.empty() && v[s.top()]>=v[i] )
            s.pop();
        prevSmaller[i]= s.empty() ? -1 : s.top() ; 
        s.push(i);
    }
}

void nextsmaller(vector<int>& v, vector<int>& nextSmaller){
    int n = v.size();
    stack<int> s ;
    for ( int i =n-1 ;i>=0;i--){
        while(!s.empty() && v[s.top()]>v[i] )
            s.pop();
        nextSmaller[i]= s.empty() ? n : s.top() ; 
        s.push(i);
    }
}

int sumSubarrayMins(vector<int>& v) {
    // We are trying to find when each element will be min for itself
    // those subarrays will be the one which are all larger than the curr element 
//	that means all elements in that subarray just before an element which is just smaller than the curr element
// And to find that we used the above knowledge of finding next smaller and preev smaller
    int n = v.size();
    vector<int> prevSmaller (n,0);    
    vector<int> nextSmaller (n,0);
    prevsmaller(v,prevSmaller);
    nextsmaller(v,nextSmaller);
    // cout<<prevSmaller<<endl<<nextSmaller<<endl;
    int ans = 0;
    // so how do u combine these 2 cases ? 
    // take one case multiply it with another 
    for ( int i =0 ; i<n;i++){
    	// for those cases on left side and for those cases on right side 
    	// we need also those cases which kind includes both of sides
    	// so for each left side take right side
    	// basically left side * right side
        ans=(ans+(v[i]*((long long)(i-prevSmaller[i])*(nextSmaller[i]-i)))%m)%m;
    }
    return ans;
}

int largestRectangleArea(){
	int n ;
	cin>>n;
	vi v (n,0);
	cin>>v;
    stack<int> s ;
    int ans=0 ;
    for ( int i =0 ;i<n ;i++){
        while(!s.empty() && v[s.top()]>v[i]){
            int top = s.top();
            s.pop();
            if(s.empty()){
                ans=max(ans,(i)*(v[top]));
            }else{
                ans=max(ans,(i-s.top()-1)*(v[top]));
            }
        }
        s.push(i);
    }
    while(!s.empty()){
        int top = s.top();
        s.pop();
        if(s.empty()){
            ans=max(ans,(n)*(v[top]));
        }else{
            ans=max(ans,(n-s.top()-1)*(v[top]));
        }
    }
    return ans;
}

void solve(){
	largestRectangleArea();
}

int main(){
	fastio
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	int t=1;
	cin >> t;
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

