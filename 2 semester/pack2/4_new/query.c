extern long long Sum(int l, int r);
extern int NN;
int Query(int l, long long sum) {
    int low = l, high = NN; 
    int res = l;
    
    while (low <= high) {
        int mid = (high + low) / 2;
        
        if (Sum(l, mid) <= sum) {
            res = mid;
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    
    return res;
}
