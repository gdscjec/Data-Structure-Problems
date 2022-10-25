class Solution {
public:
    int countDistinct(vector<int>& arr, int k, int p) {
        int n=arr.size();
        int ans = 0 ,ct=0;
        
        unordered_map<string,int> mp;
        
        for(int i=0;i<n;i++){
            int ct=0;
            string s="";      // subarry represent into string format
            
            for(int j=i;j<n;j++){
                
                s = s + "$" + to_string(arr[j]);   // '$'  is used to make unique representaion of subarray
                
                if(arr[j]%p == 0) ct++;
                
                if(ct <= k) mp[s]++;      // stored in map to avoid duplicate
            }  
        }
        
        return mp.size();
    }
};