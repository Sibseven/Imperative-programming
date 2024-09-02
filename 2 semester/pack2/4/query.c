extern long long Sum(int l, int r);
extern int NN;
int Query(int l, long long sum) {
    int low = l, high = NN; 
    
    while (low <= high && low<NN) {
        int mid = low + (high - low) / 2;
        if (Sum(l, mid) <= sum) { 
            if(Sum(l, mid+1) > sum){
                return mid+1;
            }
            else{
                low = mid+1;
            }
        } 
        else {
            high = mid-1;
        }
    }
    
    return low;
}
