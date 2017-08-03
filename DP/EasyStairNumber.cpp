#include <iostream>
 
using namespace std;
 
int main(void)
{
    int digit;
    cin>>digit;
    long long dp[101][10]={0};
    for(int i=0;i<=9;i++)
    {
        dp[0][i]=1;
    }
    for(int i=1;i<digit;i++)
    {
        for(int j=0;j<=9;j++)
        {
          if(j==0)
              dp[i][j]=dp[i-1][j+1];
 
          else if(j==9)
                dp[i][j]=dp[i-1][j-1];
 
           else
           {
              dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1]);
 
           }
            dp[i][j]%=1000000000;
         }
    }
    long long count=0;
 
    for(int i=1;i<=9;i++)
    {    
        count+=dp[digit-1][i];
         count%=1000000000;
 
    }
        cout<<count;;
 
}