//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
       int fillingBucket(int n) {

     if(n<=2)return n;

     int first=1;

     int second=2;

     for(int i=3;i<=n;i++)

     {

         int next=(first+second)%100000000;

         first=second;

         second=next;

     }

     return second%100000000;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends