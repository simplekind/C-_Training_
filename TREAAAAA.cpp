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
#define endln '\n'
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define sortall(x) sort(all(x))

using namespace std;
//
//ll findMedian(ll* a, int n)
//{  
//    if (n % 2 == 0) {
//        nth_element(a.begin(),a.begin() + n / 2,a.end());
//        nth_element(a.begin(),a.begin() + (n - 1) / 2,a.end());
//        return (a[(n - 1) / 2]+ a[n / 2])/ 2.0;
//    }
//    else {
//        nth_element(a.begin(),
//                    a.begin() + n / 2,
//                    a.end());
//        return a[n / 2];
//    }
//}

int main(){ 
	fastio
	int t ; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

