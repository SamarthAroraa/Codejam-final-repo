#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<#x<<" "<<x<<endl;
typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<pii> vii; 
typedef vector<ll> vl; 
typedef vector<vl> vvl; 
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define REP(i, n) FOR(i, 0, n) 
#define REPN(i, n) FORN(i, 1, n)
#define FOREACH(a, b) for (auto&(a) : (b)) 
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a)) 
#define RESET(a, b) memset(a, b, sizeof(a)) 
#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back 
#define TC(t) while (t--)

int minlen; string ans;

bool solve(int x, int y,int i,string path, int dx,int dy){
	// cout<<x<<" "<<y<<endl;
	if(x==dx and y==dy){
		if(minlen>path.length()){
			minlen=path.length();
			ans=path;
		}
		return 1;
	}
	if(i>10 or path.length()>40){
		return 0;
	}
	bool north=0,south=0,east=0,west=0;
	east= solve(x+(1<<i),y,i+1,path+'E',dx,dy);
	west= solve(x-(1<<i),y,i+1,path+'W',dx,dy);
	north= solve(x,y+(1<<i),i+1,path+'N',dx,dy);

	south= solve(x,y-(1<<i),i+1,path+'S',dx,dy);
	return north + south + east + west;

}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	int temp=t;
	TC(t){
		int x, y;
		cin>>x>>y;
		minlen=INT_MAX;
		ans="";
		solve(0,0,0,"",x,y);
		// cerr<<"*********************\n";
		if(ans==""){
			ans="IMPOSSIBLE";
		}
		cout<<"Case #"<<temp-t<<": "<<ans<<"\n";
		// cout<<ans<<"\n";

	}
	



	 
return 0;
}