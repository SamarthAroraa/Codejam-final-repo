#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	time_t start, end; 
	time(&start);
	int t;
	cin>>t;
	int k=1;
	while(k<=t){
		string str;
		cin>>str;
		string ans="";
		int nest=0;
		int n = str.length();
		for(int i=0;i<n;i++){
			int d= str[i]-'0';
			while(nest>d){
				ans+=")";
				nest--;
			}
			while(nest<d){
				ans+="(";
				nest++;
			}
			ans+=str[i];
		}
		while(nest>0){
			ans+=')';
			nest--;
		}
		cout<<"Case #"<<k<<": "<<ans<<"\n";
		k++;
	}

//code here

	time(&end);
	double time_taken = double(end - start); 
	cerr << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cerr << " sec " << endl; 
return 0;
}