class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr_1 = m-1;
        int ptr_2 = n-1;
        int end = m+n-1;
        while(ptr_1>=0 && ptr_2>=0){

            if(nums1[ptr_1] < nums2[ptr_2]){
                nums1[end--] = nums2[ptr_2--];
            }
            else {
                nums1[end--] = nums1[ptr_1--];
            }
        }

        // edge case : when nums1 has 0 elements
        // then copy from nums2
        while(ptr_2 >= 0){
            nums1[end--] = nums2[ptr_2--];
        }
        
    }
};