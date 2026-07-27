package main;
public class Solution {
    public boolean isPalindrome(int x) {
        // 负数 或 末尾为0且不是0，直接false
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reverseHalf = 0;
        // 只反转后半段
        while (x > reverseHalf) {
            reverseHalf = reverseHalf * 10 + x % 10;
            x = x / 10;
        }

        // 偶数位：x == reverseHalf；奇数位：x == reverseHalf / 10（去掉中间数字）
        return x == reverseHalf || x == reverseHalf / 10;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.isPalindrome(121));   // true
        System.out.println(sol.isPalindrome(-121));  // false
        System.out.println(sol.isPalindrome(10));    // false
    }
}