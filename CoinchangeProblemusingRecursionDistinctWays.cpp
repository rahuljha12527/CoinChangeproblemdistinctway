#include<iostream>

using namespace std;

int count(int S[],int n,int N)
{   
	// if total is 0,return 1(solution found)
	if(N==0)
		return 1;

	// return 0(solution do not exist ) if total become negative or
	// no element are left

	if(N<0 || n<0)
		return 0;
	//Case 1. include current coin S[n] in solution and recur
	// with remaining change (N-S[n]) with same number of coins
	int include=count(S,n,N-S[n]);

	//Case 2.exclude current coin S[n] from solution and recur
	//for remaining coins(n-1)
    int exclude=count(S,n-1,N);
	return include + exclude;
}

int main(){
   
   // n coins of given denominations
	int S[]={1,2,3};
	int n=sizeof(S)/sizeof(S[0]);

	int N=4;

	cout << "Total number of ways to get desired change is "
	                  <<count(S,n-1,N);

    return 0;
}