#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int no_of_ones_before_n(int n);
int no_of_ones_before_n(int n)
{

 int count1 = 0;
    for (int i = 1; i <= n; i++) 
    {
        string str = to_string(i);
        count1 += count(str.begin(), str.end(), '1');
    }
    return count1;

}
int main()
{
    int n;
    cin>>n;
    cout<<no_of_ones_before_n(n);
    return 0;
}