//Code by Arunika Bhattacharya
//Largest Number Problem

#include<bits/stdc++.h>
using namespace std;

string largestNumber(vector<int>& nums) {
        int x =0 ;
        //Checking for zeroes in the array
        for(int i=0 ;i<nums.size();i++){
            if(nums[i]==0){
                x++ ;
            }
        }
        if(x == nums.size()){
            return  "0";
        }
        //converting integer vector to string vector
        vector<string> s(nums.size());
        for(int i =0 ;i<nums.size();i++){
            s[i] = to_string(nums[i]);
        }
        //sorting the vector
        sort(s.begin(),s.end(),[](string X,string Y){
	        string XY = X.append(Y);
	        string YX = Y.append(X);
	        return XY.compare(YX)>0 ? 1 : 0;
	    });
	    
        //empty string
	    string ans="" ;
	    for(int i=0 ;i<nums.size();i++){
	        ans+=s[i];
	    }
	 return ans;
 }
int main(){
    int n ;
    cin>>n;
    //InputVector
    vector<int> arr(n);
    for(int i=0 ;i<n;i++){
        cin>>arr[i];
    }
   
    auto res =largestNumber(arr);
    cout<<res<<"\n";

    return 0 ;
}