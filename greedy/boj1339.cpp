#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n;
    int hash[26]={0,};
    string arr[10];

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n;i++)
    {
        int size = arr[i].size();
        for(int j=0;j<size;j++)
        {
            hash[arr[i][j]-'A']+=pow(10,size-j-1);
        }
    }

    sort(hash,hash+26);
    int res=0;
    int times=9;
    for(int i=26-1;i>=0;i--)
    {
        if(hash[i]!=0){
            res+=(times*hash[i]);
            times--;
        }
    }
    cout<<res<<endl;
}
