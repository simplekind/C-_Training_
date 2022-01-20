#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
typedef vector<int> vi;
typedef vector<int> pi;
#define fli(i,a,b) for(auto i=a;i<b;i++)
#define fld(i,a,b) for(auto i=a;i>=b;i--)
#define llfli(i,a,b) for(auto i=a;i<b;i++)
#define llfld(i,a,b) for(auto i=a;i>b;i--)
#define test int t; cin>>t;while(t--)
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
#define in_array(a,n) int n ;cin>>n;int a[n];fli(i,0,n)cin>>a[i];
#define in_vec(v,n) int n ;cin>>n;vector<int> v (n);fli(i,0,n)cin>>v[i];
#define print_array(a,n)  fli(i,0,n) cout<<a[i]<<" ";
#define for_it(v,it) for (auto it= v.begin(); it!=v.end();it++)
using namespace std;
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endln '\n'

// THis is a step by step moving algo kind of , where unlike in n queens you cannot just place rat at a posn like we used to in n queens 

// Approach 1
void rat_in_a_maze_util(int**maze,int**vis, int n ,int x, int y ){
	
	// Finaally when it reaches 
	if(x==n-1 && y==n-1) { 
		vis[n-1][n-1] =  1;
		fli(i,0,n){
			fli(j,0,n){
				cout<<vis[i][j]<<" ";
			} 
			cout<<endln;
		} 
		cout<<endln; 
		return ;
	}
	
	//Constraints 
	if(x<0 || y<0 || x>=n || y>=n || vis[x][y]  || !maze[x][y]) {
		return ;
	}
	
	//MoveSet 
	vis[x][y] = 1;
	rat_in_a_maze_util( maze,vis,n,x,y+1) ;
	rat_in_a_maze_util( maze,vis,n,x+1,y) ;
	rat_in_a_maze_util( maze,vis,n,x,y-1) ;
	rat_in_a_maze_util( maze,vis,n,x-1,y) ; 
	vis[x][y] = 0;	 
}

void rat_in_a_maze(int** maze ,int n ){
	int** vis = new int* [n] ;
	fli (i,0,n) {
		vis[i] = new int* [n] ; 
	} 
	rat_in_a_maze_util( maze,vis,n,0,0 ) ;
}

int main(){	
	fastio
	int n ; cin>>n;
	int** maze = new int * [ n];
	fli(i,0,n){
		maze[i] = new int *  ;
	}
	fli(i,0,n){
		fli(j,0,n){
			cin>>maze[i][j];
		}
	}
	cout<<endln;
	rat_in_a_maze(maze,n);
}






















