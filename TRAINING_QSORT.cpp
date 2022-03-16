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

// here we used partition for end element for each 
int partition(vi& v, int start, int end);

// we can use a random partition/pivot techq for better results
int partition_random(vi& v, int start, int end){
	srand(time(NULL));
    int random = start + rand() % (end - start);
    swap(v[random], v[end]);
    return partition(v,start,end);
}

// QUICKSELECT
// non-recursive
void divide_it (vi &v , int start, int end,int k){
	if(start>=end) return;
	while(start<=end){
		int p = partition(v, start,end);
		if(p<k)
			start=p+1;
		else
			end=p-1;
	}
}

// recursive
void divide (vi &v , int start, int end,int k){
	if(start>=end) return;
	int p = partition(v, start,end);
	if(p==k) return;
	else if(p>k) divide(v,start,p-1,k);
	else 		 divide(v,p+1,end,k);
}

// QUICKSORT
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

// using dnf partition to handle the duplicate keys
vi partitiondnf(vi& v, int start, int end){
	int pivot = v[end];
	int startPivot = start, endPivot = end-1, i = start;
	while(i<=endPivot){
		if(pivot>v[i]){
			swap(v[startPivot],v[i]);
			i++;
			startPivot++;
		}else if (pivot==v[i]){
			i++;
		}else if (pivot<v[i]){
			swap(v[endPivot],v[i]);
			endPivot--;
		}
	}
	return {startPivot,endPivot};
}

void divide_nlogn_space_insert_sort_3_way_part_dnf(vi& v, int start, int end){
	if (start-end<=11) {
		InsertionSort(v,start,end);
		return;		
	}
	while(start<end){
		swap(v[(start+end)/2],v[end-1]);
		if(v[start]>v[end-1]) swap(v[start],v[end-1]);
		if(v[start]>v[end]) swap(v[start],v[end]);
		if(v[end-1]>v[end]) swap(v[end-1],v[end]);
		vi a = partitiondnf(v,start+1,end-1);
		int startPivot = a[0],endPivot = a[1];
		if(startPivot - start < end - endPivot)
			divide_nlogn_space_insert_sort_3_way_part_dnf(v,start,startPivot-1),start=endPivot+1;
		else
			divide_nlogn_space_insert_sort_3_way_part_dnf(v,endPivot+1,end),end=startPivot-1;
	}
}

int partition(vi& v, int start, int end){
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
//		int pivotIndex = partition(v,start+1,end-1);
		int pivotIndex = partition_random(v,start+1,end-1);
		if(pivotIndex - start < end - pivotIndex)
			divide_nlogn_space_insert_sort_3_way_part(v,start,pivotIndex-1),start=pivotIndex+1;
		else
			divide_nlogn_space_insert_sort_3_way_part(v,pivotIndex+1,end),end=pivotIndex-1;
	}
}


// helps to reduce stack size from worst case of n to worst case of nlgn
void divide_nlognspace (vi& v, int start, int end){
	if (start>=end) return;
//	int count = 0; this is just to check how many time loop ran
	while(start<end){
//		deb(count++);
		int pivotIndex = partition(v,start,end);
		// sorting first smaller files will help to improve worst space complexity(not time)
		if(pivotIndex - start < end - pivotIndex)
			divide_nlognspace(v,start,pivotIndex-1),start=pivotIndex+1;
		else
			divide_nlognspace(v,pivotIndex+1,end),end=pivotIndex-1;
	}
}

void divide (vi &v, int start, int end){
	if(start>=end) return;
	int p = partition(v,start,end);
	divide(v,start,p-1);
	divide(v,p+1,end);
}

void qsort(vi& v){
	divide_nlogn_space_insert_sort_3_way_part(v,0,v.size()-1);
//	divide_nlognspace(v,0,v.size()-1);
//	divide(v,0,v.size()-1);
//	divide_nlogn_space_insert_sort_3_way_part_dnf(v,0,v.size()-1);
}

// if k is small then use selection sort 
void qselect(vi & v,int k){
//	divide(v,0,v.size()-1,k);
//	deb(v[k-1]);
	divide_it(v,0,v.size()-1,k);
	deb2(k,v[k-1]);
}

void solve(){
//	vi v = {1,2,3,4,5,6,7};
	vi v1= {7,5,11,2,1,3,12,5,4,1,10,12};
	vi v= {7,5,11,2,1,3,12,5,4,1,10,12};
//	vi v = {1,2,3,4}; 
	qselect(v1,10);
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

