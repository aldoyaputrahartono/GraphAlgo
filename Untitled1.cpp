#include<bits/stdc++.h>
using namespace std;

int main(){
	int y,k,n,x;
	cin>>y>>k>>n;
	x=k-(y%k);
	n=n-y;
	if(x>n) cout<<"-1"<<endl;
	else{
		while(x<=n){
			cout<<x<<" ";x+=k;
		}
		cout<<endl;
	}
    return 0;
}
