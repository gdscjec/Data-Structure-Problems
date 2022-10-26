#include<iostream>
using namespace std;

int main()
{
	long long i,j,cnt,n;
	cin>>n;
	while(n--)
	{
		cin>>i>>j;
		cnt=0;
		while(i!=j)
		{
			if(i>j)
				i>>=1;
			else
				j>>=1;
			cnt++;
		}
		cout<<cnt<<"\n";
	}
}