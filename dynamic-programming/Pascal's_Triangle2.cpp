class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>res(1,1);

        long long prev = 1;
        
        for(int k = 1; k <= rowIndex; k++){
            long long next_val = prev * (rowIndex-k+1) / k;
            res.push_back(next_val);
            prev = next_val;
        } 

        return res;
    }
};

// APPROACH:
// Each row of Pascal's Triangle can be represented using the sequence of combinations:
// C(r,0),C(r,1),C(r,2),…,C(r,r)
// where C(n,k) is the binomial coefficient, defined as:
// C(n,k)= 
// k!(n−k)! / n!
// ​
 

// The row's first element is always 1. Given the previous element in the row (prev), the next element can be calculated using:
// next_val=prev * (rowIndex−k+1)/k
// ​
 
// This formula is derived from the relationship between consecutive binomial coefficients in the same row.

// Iterating from k = 1 to k = rowIndex, we can directly generate the elements for the desired row without building the entire triangle.

// COMPLEXITY:
// Time complexity: O(rowIndex)
// This is because we are directly computing the rowIndex-th row without iterating through all previous rows.

// Space complexity: O(rowIndex)
// The only significant space used is for the result list, which has a length of rowIndex + 1.