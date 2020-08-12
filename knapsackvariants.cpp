static int t[max n+1 +1][max w+1 +1];
memset(t, -1, sizeof(t));
int knapsack(int w, int val[], int wt[], int n){
	//memoized, recursize, top down? 
	if(w==0||n==0) return 0;
	if(t[n][w]!=-1) return t[n][w];
	if(w>=wt[n-1])
    	return t[n][w] = max( val[n-1]+knapsack(w-wt[n-1], val, wt, n-1), 
		 								knapsack(w, val, wt, n-1) );
	elseif(wt[n-1]>w) return t[n][w] = knapsack(w, val, wt  , n-1);
		

}


//bottom up(cus u start from base case), omit recursive call, make them iterative
//initialize, make the iterative calls (iterative makes base consdition--> initialization)

int knapsack(int w, int val[], int wt[], int n){
  if(n==0||w==0)
  	t[][]
  
  for (int i = 0; i < n+1; i++) 
  	for (int j = 0; j < w+1; j++) 
  		if(i==0||j==0) t[i][j]=0;
  
  for (int i = 1; i < n+1; i++) 
  	for (int j = 1; j < w+1; j++){
  		if(w>=wt[n-1])
  		  t[i][j] = max(val[i-1]+t[i-1 ][j-wt[i-1]], t[i-1][j]);
  		elseif(wt[n-1]>w) t[i][j] = t[i-1][j];
  		}

  return t[n][w];
}

//if only when array goven consider it as weight array
//submatrix denotes which subproblem?


bool subsetsum(int sum; int* arr){
	for (int i = 1; i < n+1; i++) 
  	for (int j = 1; j < w+1; j++){ 
  		  if(i==0) t[i][j]=false;
  		  if(j==0) t[i][j]=true;
  		}
  for (int i = 1; i < n+1; i++) 
  	for (int j = 1; j < w+1; j++){
	if(arr[i-1]<=j)
		t[i][j]= t[i-1][j]||t[i-1][j-arr[i-1]]; 
	else t[i][j]= t[i-1][j];	
	}	

return t[n][sum];  

}

int minSubsetSumDiff(int sum; vector<int>& arr){
	int t[ n/2 +1 +1][ w/2 +1 +1];
	int sum, n;
    memset(t, -1, sizeof(t));
	n=arr.size();
for (int i = 0; i < ; i++) sum+=arr[i];
  	
	for (int i = 1; i < n/2 +1; i++) 
  	for (int j = 1; j < w/2 +1; j++){ 
  		  if(i==0) t[i][j]=false;
  		  if(j==0) t[i][j]=true;
  		} //init

  for (int i = 1; i < n/2 +1; i++) 
  	for (int j = 1; j < w/2 +1; j++){
	
	if(arr[i-1]<=j)
		t[i][j]= t[i-1][j]||t[i-1][j-arr[i-1]]; 
	else t[i][j]= t[i-1][j];	
	
	}	//only need to fill till half

  for (int j=sum/2; j>=0; j--) 
    { 
        // Find the  
        if (dp[n][j] == true) 
        { 
            diff = sum-2*j; 
            break; 
        } 
    } 
    return diff; 

return mn;  

}

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < s || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1); 
    }   

    int subsetSum(vector<int>& nums, int s) {
        int dp[s + 1] = { 0 };
        dp[0] = 1; 
        for (int n : nums)
            for (int i = s; i >= n; i--)
                dp[i] += dp[i - n];
        return dp[s];
    }
};