#include <iostream>
#include <vector>

void find_student_positions(int n, std::vector<int>& heights, int k, std::vector<int>& queries, std::vector<int>& results) {
    int lo,hi,mid;
    while(k--){
        lo = 0;
        hi = n-1;
        if(queries[k] > heights[hi]){
            results[k] = hi+1;
            continue;
        }else if(queries[k] < heights[lo]){
            results[k] = lo;
            continue;
        }else{
            while(lo<hi){
                mid = lo + (hi-lo)/2;
                if(heights[mid] == queries[k]){
                    results[k]=mid;
                    break;
                }else if(heights[mid] > queries[k]){
                    hi = mid-1;
                }else{
                    lo = mid+1;
                }
            }
            if(!results[k]){
                results[k] = lo;
            }
        }

    }
}

int main() {
    int n, k;
    std::cin >> n;
    std::vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> heights[i];
    }
    std::cin >> k;
    std::vector<int> queries(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> queries[i];
    }
    std::vector<int> results(k);
    find_student_positions(n, heights, k, queries, results);
    for (int i = 0; i < k; ++i) {
        std::cout << results[i] << std::endl;
    }
    return 0;
}
