#include<bits/stdc++.h>
using namespace std;


int count(int a[],int n,int m){

    //recursive approach

/*    int dp[n+1][m+1];
    memset(dp,-1,sizeof(dp));
    if(m==0)
        return 1;
    if(m<0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(n<=0 && m>=1)
        return 0;
    return dp[n][m] = count(a,n-1,m)+count(a,n,m-a[n-1]);*/

  // Iterative approach

/*    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j==0)
                dp[i][j]=1;
            else if(i==0)
                dp[i][j]=0;

            else if(a[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-a[i-1]];
        }
    }

    return dp[n][m];*/


    // most optimal soln in o(m) space

       int dp[m+1];

    for(int i=0;i<=m;i++)
        dp[i]=0;
    dp[0]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            if(a[i]<=j)
                dp[j] += dp[j-a[i]];

        }
    }
    return dp[m];
    
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m;
    cin>>m;
    cout<<count(a,n,m);
    return 0;
}

