class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = -1, high = letters.size();
        
        while(low + 1 < high){
            int mid = (high + low)/2;
            if(letters[mid] <= target){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        if(high == letters.size()) return letters[0];
        return letters[high];
    }
};