/*
Approach :
Intution 1 : At first I thought, i should try checking every element between low and high , then check.
But after seeing the constraints, I found it would not be the right solution. Constraints ae very high, so its approach would be very simpler that it seems.

Intution 2: All the elements would contain only 1 to 9 numbers. Then I thought instead of searching I would create the nos in sequential order and then will check the bounds. Then, my friends this approach worked.

Time Complexity : O(1)
Space Complexity : O(n) , where n is no. of sequential digits between the bound.
*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        int num = 0;
        for(int i = 1; i<10 ; i++)
        {
            num = i;
            for(int j = i+1;j<10;j++)
            {
                num = num*10 + j;
                if(num >= low && num <= high)
                {
                    result.push_back(num);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};