#include <climits>
#include <iostream>
using namespace std;
 
int maxProfit(int price[], int n, int k)
{
    
  
    int profit[k + 1][n + 1];
 
    for (int i = 0; i <= k; i++)
        profit[i][0] = 0;
 
    
    for (int j = 0; j <= n; j++)
        profit[0][j] = 0;
 
  
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < n; j++) {
            int max_so_far = INT_MIN;
 
            for (int m = 0; m < j; m++)
                max_so_far = max(max_so_far,
                                 price[j] - price[m] + profit[i - 1][m]);
 
            profit[i][j] = max(profit[i][j - 1], max_so_far);
        }
    }
 
    return profit[k][n - 1];
}
 
int main()
{
    int n,k;
    cin>>n>>k;
    int price[n];
    for(int i=0;i<n;i++)
        cin>>price[i];
 
    cout<<maxProfit(price, n, k);
 
    return 0;
}
