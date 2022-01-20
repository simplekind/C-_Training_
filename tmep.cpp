#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef vector<vector<bool>> vvb;
typedef vector<long long> vll;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);cout<<fixed;srand(time(0));
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(ll i = a; i < b; i++)
#define DEB(a) cout<<#a<<" = "<<a<<"\n";

bool comparator(const vll& a1, const vll& a2){
	return (a1[1] >= a2[1]);
}

int main(){
	fastio;

	int T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		vvll stud(n,vll(2));
		REP(i,0,n){
			cin>>stud[i][0];
		}
		REP(i,0,n){
			cin>>stud[i][1];
		}
		sort(stud.begin(),stud.end(),comparator);
		vvll adj(n,vll(0));
		REP(i,0,n){
			adj[(stud[i][0]-1)].PB(stud[i][1]);
		}
		REP(i,0,n){
			for(ll j = 1; j < adj[i].size(); j++){
				adj[i][j] += adj[i][j-1];
			}
		}
		vll answer(n,0);
		REP(i,0,n){
			ll len = adj[i].size();
			for(ll k = 1; k <= len; k++){
				ll sub = len % k;
				answer[k-1] += adj[i][len-1-sub];
			}
		}
		REP(i,0,n){
			cout<<answer[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
