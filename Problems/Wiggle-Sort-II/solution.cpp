#include<bits/stdc++.h>
using namespace std;

void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans(n,0);
        int k=1;
        int i=n-1;
        while(k<n)
        {
            
            ans[k]=nums[i];
            i--;
            k=k+2;
            
        }
        int j=0;
        while(j<n)
        {
            ans[j]=nums[i];
            i--;
            j=j+2;
        }
        nums=ans;
}

int main(){
    int n; //size of input
    cin>>n;
    vector<int> arr(n); //arr to store input;
    for(int i=0;i<n;i++) cin>>arr[i];
    wiggleSort(arr);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}
