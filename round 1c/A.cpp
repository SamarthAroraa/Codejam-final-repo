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
#define bitcount __builtin_popcount
#define gcd __gcd
#define se second 
#define mp make_pair 
#define pb push_back 
#define TC(t) while (t--)
class point
{
public:
	int dist,idx;

	
	
};
bool comp(point a, point b){
	return a.idx<b.idx;
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
 	int m=t;
 	TC(t){
 		int x,y;
 		cin>>x>>y;
 		string s;
 		cin>>s;
 		int n = s.length();
 		int ans=-1;
 		point points[n+1];
 		point p;
 		int d= abs(x)+abs(y);
 		deb(d)
 			// point p;
 			p.dist=d;
 			p.idx=0;
 		points[0]=p;
 		
 		// else{
 		FOR(i,0,n){
 			if(s[i]=='N'){
 				y+=1;
 			}
 			if(s[i]=='S'){
 				y-=1;
 			}
 			if(s[i]=='W'){
 				x-=1;
 			}
 			if(s[i]=='E'){
 				x+=1;
 			}
 			cerr<<x<<" "<<y<<" "<<i+1<<endl;
 			int d= abs(x)+abs(y);
 			point p;
 			p.dist=d;
 			p.idx=i+1;
 			points[i+1]=p;
 		}

 		sort(points,points+n+1, comp);
 		for(int i=0;i<=n;i++){
 			// cerr<<points[i].idx<<" "<<points[i].dist<<endl; 
 			if(points[i].idx>=points[i].dist){
 				ans=points[i].idx;
 				break;
 			}
 		}
 		cerr<<"*****************\n";
 		cout<<"Case #"<<m-t<<": ";
 		if(ans==-1){
 			cout<<"IMPOSSIBLE\n";
 		}
 		else{
 			cout<<ans<<"\n";
 			}
 	// }
 }


	 
return 0;
}

