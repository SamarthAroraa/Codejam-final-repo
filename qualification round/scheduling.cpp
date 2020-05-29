#include<bits/stdc++.h>
#define deb(x) cerr<<#x<<" "<<x<<endl;
#define ll long long
using namespace std;
class event{
public:
  ll time;
  char type;
  ll idx;
};
bool comp(event a, event b){
  if(a.time!=b.time)
  return a.time<b.time;
else{
    return a.type=='d';
  }
}


void solution(event arr[], ll n,ll hn){
sort(arr,arr+n,comp);
bool j=0,c=0;
std::vector<char> ans(hn);
ll curr=0;
for(ll i=0;i<n;i++){
    // cerr<<arr[i].time<<' '<<arr[i].type<<endl;

  if(arr[i].type=='a'){
    curr++;
    if(j==0){
      ans[arr[i].idx]='J';
      j=1;
    }
    else if(c==0){
      ans[arr[i].idx]='C';
      c=1;
    }
    else{
      cout<<"IMPOSSIBLE\n";
      return;
    }
  }

  else{
    curr--;
    if(ans[arr[i].idx]=='J')
      j=0;
    else if(ans[arr[i].idx]=='C')
      c=0;
  }
  // deb(curr)
  // deb(ans)

}
for(ll i=0;i<hn;i++){
  cout<<ans[i];
}
cout<<"\n";
return;
}

int main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // time_t start, end; 
  // time(&start);
  ll t;
  cin>>t;
  ll k=1;
  while(k<=t){
    ll n;
    cin>>n;
    event arr[2*n];
    ll o=0;
    ll sz=0;
    for(ll i=0;i<n;i++){
      ll st,et;
      cin>>st>>et;
      arr[sz].time=st;
      arr[sz].type='a';
      arr[sz].idx=i;
      sz++;
      arr[sz].time=et;
      arr[sz].type='d';
      arr[sz].idx=i;
      sz++;
    }
    // for(ll i=0;i<sz;i++){
    //   cout<<arr[i].time<< " "<<arr[i].idx<<endl;
    // }
    // cout<<"\n";

    cout<<"Case #"<<k<<": ";
    solution(arr,sz,n);
    k++;
  }

//code here

  // time(&end);
  // double time_taken = double(end - start); 
  // cerr << "Time taken by program is : " << fixed 
  //        << time_taken << setprecision(5); 
  //   cerr << " sec " << endl; 
return 0;
}