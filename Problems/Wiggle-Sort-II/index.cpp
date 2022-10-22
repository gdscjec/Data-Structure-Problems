#include<bits/stdc++.h>
using namespace std;
//with TC- O(N) and SC- O(N);
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
//With O(1) space and O(N) tc;
void wiggleSort2(vector<int>& nums) {
		if (nums.empty()) {
			return;
		}    
		int n = nums.size();
		
		// Step 1: Find the median    		
		vector<int>::iterator nth = next(nums.begin(), n / 2);
		nth_element(nums.begin(), nth, nums.end());
		int median = *nth;

		// Step 2: Tripartie partition within O(n)-time & O(1)-space.    		
		auto m = [n](int idx) { return (2 * idx + 1) % (n | 1); };    		
		int first = 0, mid = 0, last = n - 1;
		while (mid <= last) {
			if (nums[m(mid)] > median) {
				swap(nums[m(first)], nums[m(mid)]);
				++first;
				++mid;
			}
			else if (nums[m(mid)] < median) {
				swap(nums[m(mid)], nums[m(last)]);
				--last;
			}				
			else {
				++mid;
			}
		}
	}    

int main(){
    int n; //size of input
    cin>>n;
    vector<int> arr(n); //arr to store input;
    for(int i=0;i<n;i++) cin>>arr[i];
    wiggleSort2(arr);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}