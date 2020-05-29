#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;

void computeLPSArray(string pat, int M, int* lps) 
{ 
    // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 
bool KMPSearch(string pat, string txt) 
{ 
    int M = pat.length(); 
    int N = txt.length(); 
  
    // create lps[] that will hold the longest prefix suffix 
    // values for pattern 
    int lps[M]; 
  
    // Preprocess the pattern (calculate lps[] array) 
    computeLPSArray(pat, M, lps); 
  
    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) { 
            return 1 ;
            j = lps[j - 1]; 
        } 
  
        // mismatch after j matches 
        else if (i < N && pat[j] != txt[i]) { 
            // Do not match lps[0..lps[j-1]] characters, 
            // they will match anyway 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
return 0;} 
  
// Fills lps[] for given patttern pat[0..M-1] 

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
		int n;
		cin>>n;
		string ans="";
		std::vector<string> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		for(int i=0;i<n;i++){
			string res="";
			for(int j=0;j<arr[i].length();j++){
				if(arr[i][j]!='*')
					res+=arr[i][j];
				}
				arr[i]=res;
		}
		int j;
		for(int i=0;i<n;i++){
			bool flag=1;
			for( j=0;j<n;j++){
				if(j==i)
					continue;
				if(!KMPSearch(arr[j],arr[i])){
					flag=0;
					break;
					
				}
					
			}
					deb(arr[i])
					deb(arr[j])
					deb(flag)
			if(flag==1 and arr[i].length()>ans.length()){
				ans= arr[i];
			}
		}
		cout<<"Case #"<<k<<": "<<ans;
		if(ans==""){
			cout<<"*";
		}
		cout<<"\n";
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