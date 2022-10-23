///////////////Approach/////////////////////////
// Sort nums in increasing order.
// We fix nums[i], nums[j] by iterating the combination of nums[i], nums[j], then the problem now become to very classic problem 1. Two Sum.
// By using two pointers, one points to left, the other points to right, remain = target - nums[i] - nums[j].
// If nums[left] + nums[right] == remain
// Found a valid quadruplets
// Else if nums[left] + nums[right] > remain
// Sum is bigger than remain, need to decrease sum by right -= 1
// Else:
// Increasing sum by left += 1.


//TC- O(N^3)+O(NlogN) SC-O(N)
////////////////////Solution///////////////////

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> func(vector<int> &arr,int n,int sum){
    set<string> s;// to keep track of duplicates
    sort(arr.begin(),arr.end()); //sorting the input;
    vector<vector<int>> ans; 
    for(int i=0;i<n-3;i++){// for first number
        for(int j=i+1;j<n-2;j++){ //for second number
            //using 2 sum solution to select remaining 2 numbers
            int k = j+1;
            int l = n-1;
            while(k<l){
                int sum1 = arr[i]+arr[j]+arr[k]+arr[l];
                if(sum==sum1){
                    string temp = to_string(arr[i])+to_string(arr[j])+to_string(arr[k])+to_string(arr[l]);
                    if(s.find(temp)==s.end()){
                        s.insert(temp);
                        ans.push_back({arr[i],arr[j],arr[k],arr[l]});
                    }
                    k++;
                    l--;
                }else if(sum1<sum){
                    k++;
                }else{
                    l--;
                }
            }
        }
    }
    return ans;
}
int main(){
    
    int n,sum; //size of input, sum which needs to be achieved
    cin>>n>>sum;
    vector<int> arr(n); //store input;
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<vector<int>> ans; //storing the ans in group of 4 elements
    ans = func(arr,n,sum);
    for(auto &i:ans){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;

}