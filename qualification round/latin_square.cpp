#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
bool rowcheck(int ** matrix, int n, int j){
	unordered_map<int, bool> occured;

	for(int i=0;i<n;i++){
		if(occured[matrix[i][j]]){
			return 0;
		}
		occured[matrix[i][j]]=1;
	}
return true;
}

bool colcheck(int ** matrix, int n, int j){
	unordered_map<int, bool> occured;

	for(int i=0;i<n;i++){
		if(occured[matrix[j][i]]){
			return 0;
		}
		occured[matrix[j][i]]=1;
	}
return true;
}

int trace(int** matrix, int n){
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=matrix[i][i];
	}
	return ans;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tmain;
	cin>>tmain;
	int t=tmain;
	while(t--){
		int n;
		cin>>n;
		int ** matrix= new int*[n];
		for(int i=0;i<n;i++){
			matrix[i]= new int[n];
			for(int j=0;j<n;j++){
				cin>>matrix[i][j];
			}
		}
		int r=0,c=0,k=0;
		for(int i=0;i<n;i++){
			if(!rowcheck(matrix,n,i))
				c++;
			if(!colcheck(matrix,n,i)){
				r++;
			}
		}
		k=trace(matrix,n);
		cout<<"Case #"<<tmain-t<<": "<<k<<" "<<r<<" "<<c<<"\n";

		for(int i=0;i<n;i++){
			delete [] matrix[i];
		}
		delete [] matrix;
	}
//code here

return 0;
}