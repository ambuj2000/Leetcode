//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
     int b=-1,p=0;
    for(int i=0;i<n;i++)
    {
            if(b==-1)
            b=i;
            else if(price[i]<price[b])
            b=i;
            else if(price[i]>price[b])
            {
               if(i+1<n && price[i]>price[i+1])
               {
                   p+=price[b]-price[i];
                   cout<<"("<<b<<" "<<i<<")"<<" ";
                   b=-1;
               }
               else if(i==n-1)
               {
                   cout<<"("<<b<<" "<<i<<")"<<" ";
                   p+=price[i]-price[b];
               }
            }
    }
    if(!p)
    cout<<"No Profit";
    cout<<endl;

}