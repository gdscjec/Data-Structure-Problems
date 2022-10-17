#include <iostream>
using namespace std;
int Ret_Max(int a,int b)
{
    if(a>=b)
    {
        return a;
    }
    else{
        return b;
    }
}
 int Ret_Min(int a,int b)
{
    if(a<=b)
    {
        return a;
    }
    else{
        return b;
    }
}
int CountFreq_Of_1(int number)
{
    int count1 = 0;
    for (int i = 1; i <= number; i *= 10) {
        int temp = i * 10;
        count1 += (number / temp) * i +
               Ret_Min(Ret_Max(number % temp - i + 1, 0), i);
    }
    return count1;
}
 
// driver function
int main()
{
    int n;
    cin>>n;
    cout << CountFreq_Of_1(n) << endl;
   
}