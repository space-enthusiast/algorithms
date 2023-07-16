#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	priority_queue<int, vector<int>, greater<int> > pq;
	long long res=0;
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		pq.push(temp);
	}
	
	if(n==1){
		res=0;
		pq.pop();
	}
	while(!pq.empty()){
		int tempa,tempb,temp;
		
		tempa=pq.top();
		pq.pop();
		tempb=pq.top();
		pq.pop();
		temp=tempa+tempb;
		res+=temp;
		
		if(pq.empty()){
			break;
		}
		
		pq.push(temp);
	}
	cout<<res;
}
