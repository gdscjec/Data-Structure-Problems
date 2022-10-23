// 1. Deleting k digits means keeping n - k digits, where n is the total number of digits.

// 2. Use a stack that you keep sorted ascendingly. You remove elements from it as long as you can still make it to n - k digits,
// and your current element is smaller than the top of the stack:

// push(2) => 2
// push(4) because 2 < 4 => 24
// push(6) because 4 < 6 => 246
// pop() because 3 < 6 and we can still end up with 2 digits => 24
// pop() for the same reason => 2
// push(3) => 23
// push(5) => 235
// Then just take the first k digits => 23. Or you can make sure never to push more than k digits, and then the final stack is your solution.

// 3. Note that you cannot pop elements if that means you will not be able to build a solution of k digits.
// For this, you need to check the current number of elements in the stack and the number of digits to the right of your current position on the input number.


#include<bits/stdc++.h>
using namespace std;

string rmvKdigits(string num, int k) {
    // number of operation greater than length we return an empty string
    if(num.length() <= k)   
        return "0";
        
    // k is 0 , no need of removing /  preforming any operation
    if(k == 0)
        return num;
        
    string res = "";// result string
    stack <char> s; // char stack
        
    s.push(num[0]); // pushing first character into stack
        
    for(int i = 1; i<num.length(); ++i)
    {
        while(k > 0 && !s.empty() && num[i] < s.top())
        {
             // if k greater than 0 and our stack is not empty and the upcoming digit,
             // is less than the current top than we will pop the stack top
            --k;
            s.pop();
        }
            
        s.push(num[i]);
            
        // popping preceding zeroes
        if(s.size() == 1 && num[i] == '0')
            s.pop();
    }
        
    while(k && !s.empty())
    {
        // for cases like "456" where every num[i] > num.top()
        --k;
        s.pop();
    }
        
    while(!s.empty())
    {
        res.push_back(s.top()); // pushing stack top to string
        s.pop(); // pop the top element
    }
        
    reverse(res.begin(),res.end()); // reverse the string 
        
    if(res.length() == 0)
    return "0";
        
    return res;
        
        
}

int main(){
    // we need to take two inputs;
    //num = string of non-negative integers
    //k = number of allowed removals;

    int k;
    string num;
    cin>>num>>k;
    cout<<rmvKdigits(num,k);
    return 0;
}