

#include <bits/stdc++.h>
using namespace std;

long f(int i, int t, int *a, vector<vector<long>>& dp) {
    if (i == 0)
        return (t % a[0] == 0);
    if (dp[i][t] != -1)
        return dp[i][t];
    long notake = f(i - 1, t, a, dp);
    long take = 0;
    if (a[i] <= t)
        take = f(i, t - a[i], a, dp); // Fix the index here
    return dp[i][t] = take + notake;
}

long countWaysToMakeChange(int *denominations, int n, int value) {
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return f(n - 1, value, denominations, dp); // Pass n - 1 instead of n
}
#include <bits/stdc++.h>
using namespace std;
long countWaysToMakeChange(int *denominations, int n, int value) {
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));

    for(int i=0;i<=value;i++){
        dp[0][i]=(i%denominations[0]==0);
    }

    for(int i=1;i<n;i++){
        for (int j = 0; j <= value; j++) {
          long notake = dp[i - 1][j];
          long take = 0;
          if (denominations[i] <= j)
            take = dp[i][j - denominations[i]];
          dp[i][j] = take + notake;
        }
    }
    return dp[n - 1][value];
}
#include <bits/stdc++.h>
using namespace std;
long countWaysToMakeChange(int *denominations, int n, int value) {
    vector<long>prev(value + 1, 0),curr(value+1,0);

    for(int i=0;i<=value;i++){
        prev[i]=(i%denominations[0]==0);
    }

    for(int i=1;i<n;i++){
        for (int j = 0; j <= value; j++) {
          long notake =prev[j];
          long take = 0;
          if (denominations[i] <= j)
            take = curr[j - denominations[i]];
          curr[j] = take + notake;
        }
        prev=curr;
    }
    return prev[value];
}
