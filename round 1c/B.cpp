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
	set<char> valid;
	TC(t){
		int u;
		cin>>u;
		int cand[26][10];
		for(int i=0;i<26;i++){
			for(int j=0;j<10;j++){
				cand[i][j]=1;
			}
		}
		FOR(i,0,1e4){
			int q;
			string r;
			cin>>q;
			cin>>r;
			int n=r.length();
			if(q==-1)
				continue;
			for(int j=0;j<n;j++){
				valid.insert(r[j]);
				int p=r.length()-1-j;
				int lr,rr;
				int mult=pow(10,p);
				int res=q/mult;
				if(res>=10){
					lr=0;
					rr=9;
				}
				else if(p!=0){
					lr=1;rr=res;

				}
				else{
					lr=0;rr=res;
				}
				if(n>1 and p==0){
					lr=0,rr=9;
				}
				// cout<<lr<<" "<<rr<<" "<<r[j]<<endl;
				int key=r[j]-65;
				for(int k=0;k<=9;k++){
					if(k<lr or k>rr)
						cand[key][k]=0;
				}
				q-=res*mult;

			}
		}
		// REP(i,26){
		// 	if(valid.find((char)(65+i))!=valid.end())
		// 	cout<<(char)(65+i)<<" ";
		// 	REP(j,10){
		// 		if(valid.find((char)(65+i))!=valid.end())
		// 		cout<<cand[i][j]<< " ";
		// 	}
		// 	if(valid.find((char)(65+i))!=valid.end())
		// 	cout<<endl;
		// }
		vii freq_let;
		int freq;
		string ans="0000000000";
		for(int j=0;j<10;j++){
			freq=0;	
			for(int i=0;i<26;i++){
				if(cand[i][j]==1 and valid.find((char)(65+i))!=valid.end()){
					freq++;
				}
			}
			freq_let.pb({freq, j});
		}
		unordered_map<char, bool> done;
		FOREACH(k, valid){
			done[k]=1;
		}
		sort(freq_let.begin(),freq_let.end());
		FOREACH(m, freq_let){
			// cout<<m.se<<" "<<m.fi<<endl;
			for(int z=0;z<26;z++){
				if(cand[z][m.se]==1 and valid.find((char)(65+z))!=valid.end() ){
					if(done[(char)(65+z)]==1){
					// deb(z)

						
					// deb(m.fi)
					// deb(m.se)
					ans[m.se]=(char)(65+z);
					done[(char)(65+z)]=0;
					// cerr<<ans<<endl;
					break;
				}
				}
			}
		}
		

		

cout<<"Case #"<<temp-t<<": "<<ans<<endl;
	
}
	



	 
return 0;
}