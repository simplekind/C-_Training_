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
// INFIX ->
//	B	O		D		M	A	S
// 	   R->L 	L->R

// The good thing about prefix and postfix expressions is that
// we don't need the f' rules of precedence and parenthesis
// as an operand can be associated with only 1 operator 

// PREFIX ->
// POLISH NOTATION
//	<op> <op1> <op2>

// Easiest to evaluate and easy 
// POSTFIX ->
// REVERSE POLISH NOTATION
// <op1> <op2> <op> 

bool isOperatator(char ch){
	if (ch=='+' || ch=='-' || ch=='*' || ch=='/' ) return 1;
	return 0;
}

bool isOperand(char ch){
	if (ch>='0' && ch<='9' ) return 1;
	return 0;
}

int eval (int a , char ch , int b){
	if(ch=='+') return a+b;
	else if(ch=='-') return a-b;
	else if(ch=='*') return a*b;
	else if(ch=='/') return a/b;
	else if(ch=='^') return mpow(a,b);
}

int getWeightOfOperator(char ch){
	if (ch=='-') return 0;
	else if (ch=='+') return 1;
	else if (ch=='*') return 2;
	else if (ch=='/') return 3;
	else if (ch=='^') return 4;
}

bool hasHigherPredence(char ch1 , char ch2){
	int w1 = getWeightOfOperator(ch1);
	int w2 = getWeightOfOperator(ch2);
	return w1>w2;
}

void postfix (vt<char> ch){
	if (!ch.size()) return ;
	stack<int> st ;
	fli(i,0,ch.size()){
		if(isOperatator(ch[i])){
			int b = st.top();
			st.pop();
			int a = st.top();
			st.pop();
			st.push(eval(a,ch[i],b) ) ;
		}else{
			st.push(ch[i]-'0');
		}
	}
	int ans = st.top();
	st.pop();
	cout<<ans<<endln;
}

void prefix(vt <char> ch ){
	if (!ch.size()) return;
	stack<int> st;
	fld(i,(int)ch.size()-1,0){
		if(isOperatator(ch[i])){
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			st.push(eval(a,ch[i],b));
		}else{
			st.push(ch[i]-'0');
		}
	}
	int ans = st.top();
	st.pop();
	cout<<ans<<endln;
}

vt<char> infixToPostfix(vt<char> infix){
	if(!infix.size()) return {};
	vt<char> post ;
	stack <char> operatorSt;
	fli(i,0,infix.size()){
		if(infix[i]=='('){
			operatorSt.push(infix[i]);
		}else if(isOperand(infix[i])){
			post.pb(infix[i]);
		}else if(isOperatator(infix[i])){
			while(!operatorSt.empty() && operatorSt.top()!='(' && hasHigherPredence(operatorSt.top(),infix[i])){
				char ch  = operatorSt.top();
				operatorSt.pop();
				post.pb(ch);
			}
			operatorSt.push(infix[i]);
		}else if(infix[i]==')'){
			while(!operatorSt.empty() && operatorSt.top()!='('){
				post.pb (operatorSt.top() );
				operatorSt.pop();
			}
			if(!operatorSt.empty())	operatorSt.pop();
		}else continue;
	}
	while(!operatorSt.empty()){
		post.pb(operatorSt.top());
		operatorSt.pop();
	}
	fli(i,0,post.size()) cout<<post[i]<<" ";
	cout<<endln;
	return post;
}

// This is same as above just with a change that instead of starting we start from ending
// And instead of pushing '(' we push ')' since we started in reverse
vt<char> infixToPrefix(vt<char> infix){
	if(!infix.size()) return {};
	stack <char> operatorSt ;
	vt <char> pre;
	fld(i,(int)infix.size()-1,0){
		if(infix[i]==')'){
			operatorSt.push(infix[i]);
		}else if(isOperand(infix[i])){
			pre.pb(infix[i]);
		}else if(isOperatator(infix[i])){
			while(!operatorSt.empty() && operatorSt.top()!=')' && hasHigherPredence(operatorSt.top(),infix[i])){
				pre.pb(operatorSt.top());
				operatorSt.pop();
			}
			operatorSt.push(infix[i]);
		}else if(infix[i]=='('){
			while(!operatorSt.empty() && operatorSt.top()!=')'){
				pre.pb(operatorSt.top());
				operatorSt.pop();
			}
			if(!operatorSt.empty()) operatorSt.pop();
		}else continue;
	}
	while(!operatorSt.empty()){
		pre.pb(operatorSt.top());
		operatorSt.pop();
	}
	reverse(pre.begin(),pre.end());
	fli(i,0,pre.size()) cout<<pre[i]<<" ";
	cout<<endln;
	return pre;
}

// As an exercise try rest of 4 conversions

void solve(){
	vt<char> ch1 = {'2','3','*','5','4','*','+','9','-'};
	vt<char> ch2 = {'-','+','*','2','3','*','5','4','9'};
	vt<char> ch3 = {'(','(','(','(','2','+','3',')','*','5',')','-','5',')','/','5',')'};
	postfix(ch1);
	prefix(ch2);
	vt<char> ch4 = infixToPostfix(ch3);
	postfix(ch4);
	vt<char> ch5 = infixToPrefix(ch3);
	prefix(ch5);
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

