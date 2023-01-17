class Solution {
    public int minFlipsMonoIncr(String s) {
        int needToConvertToZero = 0, needToConvertToOne = 0;
        for(int i = 0 ; i < s.length() ; i++)
        {
            int cur = s.charAt(i) - '0';

            needToConvertToOne = Math.min(needToConvertToOne, needToConvertToZero) + (cur == 0 ? 1 : 0);
            needToConvertToZero += cur;
        }
        return Math.min(needToConvertToZero, needToConvertToOne);
    }
}