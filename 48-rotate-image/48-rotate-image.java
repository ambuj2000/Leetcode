class Solution {
    public void rotate(int[][] arr) {
                int n = arr.length;
        for(int i = 0; i<n ; i++){
            for(int j = i; j<n; j++){
                int tmp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = tmp;
            }
        }
        for(int i = 0; i<n ; i++){
            int li = 0;
            int ri = n-1;
            
            while(li<=ri){
                int tmp = arr[i][li];
                arr[i][li] = arr[i][ri];
                arr[i][ri] = tmp;
                
                li++;
                ri--;
            }
            
        }
    }
}