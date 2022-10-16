#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int no_of_ones_before_n(int n);
int no_of_ones_before_n(int n)
{
int i,cnt=0;
int num;
for (i= 1; i <= n; i++)
{
  num=i;
  while(num>0)
   { int ld=num%10;
    if(ld==1)
    {
        cnt++;
    }

    num/=10;
}
}
    return  cnt;
}
int main()
{
    int n;
    cin>>n;
    cout<<no_of_ones_before_n(n);
    return 0;
}