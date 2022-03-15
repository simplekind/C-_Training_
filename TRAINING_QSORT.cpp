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

int partition(vi& v, int start, int end){
	deb2(start,end);
	fli(i,start,end+1) cout<<v[i]<<" ";
	cout<<endln;
	int pivot = v[end],pivotIndex = start;
	fli(i,start,end){
		if(v[i]<=pivot){
			swap(v[i],v[pivotIndex]);
			pivotIndex++;
		}
	}
	swap(v[pivotIndex],v[end]);
	return pivotIndex;
}

void InsertionSort(vi& A, int start,int end){
  	int i, key, j;  
    for (i = start; i <=end; i++) {  
        key = A[i];  
        j = i - 1;  
        while (j >= 0 && A[j] > key) {  
            A[j + 1] = A[j];  
            j = j - 1;  
        }  
        A[j + 1] = key;  
    }  
}

// helps to reduce time for sorting small items M<=11 and by partitioning for 3 elements
// left, mid and right
void divide_nlogn_space_insert_sort_3_way_part(vi& v, int start, int end){
	if (start-end<=11) {
		InsertionSort(v,start,end);
		return;		
	}
	while(start<end){
		swap(v[(start+end)/2],v[end-1]);
		if(v[start]>v[end-1]) swap(v[start],v[end-1]);
		if(v[start]>v[end]) swap(v[start],v[end]);
		if(v[end-1]>v[end]) swap(v[end-1],v[end]);
		int pivotIndex = partition(v,start+1,end-1);
		deb(pivotIndex);
		if(pivotIndex - start < end - pivotIndex)
			deb(1),divide_nlogn_space_insert_sort_3_way_part(v,start,pivotIndex-1),start=pivotIndex+1;
		else
			deb(2),divide_nlogn_space_insert_sort_3_way_part(v,pivotIndex+1,end),end=pivotIndex-1;
	}
}


// helps to reduce stack size from worst case of n to worst case of nlgn
void divide_nlognspace (vi& v, int start, int end){
	if (start>=end) return;
//	int count = 0; this is just to check how many time loop ran
	while(start<end){
//		deb(count++);
		int pivotIndex = partition(v,start,end);
		deb(pivotIndex);
		// sorting first smaller files will help to improve worst space complexity(not time)
		if(pivotIndex - start < end - pivotIndex)
			deb(1),divide_nlognspace(v,start,pivotIndex-1),start=pivotIndex+1;
		else
			deb(2),divide_nlognspace(v,pivotIndex+1,end),end=pivotIndex-1;
	}
}

void divide (vi &v, int start, int end){
	if(start>=end) return;
	int p = partition(v,start,end);
	deb2(start,p-1);
	divide(v,start,p-1);
	deb2(p+1,end);
	divide(v,p+1,end);
}

void qsort(vi& v){
	divide_nlogn_space_insert_sort_3_way_part(v,0,v.size()-1);
//	divide_nlognspace(v,0,v.size()-1);
//	divide(v,0,v.size()-1);
}

void solve(){
//	vi v = {1,2,3,4,5,6,7};
	vi v = {7,5,11,2,1,3,5,4,1,10,12};
//	vi v = {1,2,3,4}; 
	qsort(v);
	cout<<v;
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

