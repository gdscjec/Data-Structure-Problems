class Solution {

   // starting Index of encoding string
   int start = 0;

   string Solve(string &s )
   {
       // Variable To store our answer
       string ans = "";



       while( start < s.length() && s[start] >= 'a' && s[start]<= 'z' && s[start] != ']' )
       ans.push_back(s[start++]);
    
       if(start >= s.length() || s[start] == ']')
       return ans;
    
     // We have reach the numerical character
       string num = "";
     
     // store the number to be repeated
       while(s[start] != '[' )
       num.push_back(s[start++]);
       int n = stoi(num) ;
     
       start++;
    
       string repeat = Solve(s );

     for(int k = 0 ; k< n ; k++)
           ans+= repeat;

       start++;
     
     //Return ans
        return ans + Solve(s);
        
}

public:
    string decodeString(string s) {
        
        return Solve(s);
    }
};
