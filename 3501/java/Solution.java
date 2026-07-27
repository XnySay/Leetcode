import java.util.*;

public class Solution {
    
    public List<Integer> maxActiveSectionsAfterTrade(String s, int[][] queries) {
        
        // 字符串转数组，方便使用
        int idx = 0;
        int[] temp = new int[s.length()];
        for (int k = 0; k < s.length(); k++) {
            //char数字转int
            temp[idx++] = s.charAt(k) - '0';
        }

        List<Integer> val = new ArrayList<>();

        for (int i = 0; i < queries.length; i++) {
            int[] temp1 = new int[queries[i][1] - queries[i][0] + 1];
            int idxtemp = 0;

            for (int j = queries[i][0]; j <= queries[i][1]; j++) {
                temp1[idxtemp++] = temp[j];
            }

            maxActiveSectionsAfterTrade(temp1);
            int totalOne = countOne(temp);
            int cutOne = countOne(temp1);
            
            val.add(maxActiveSectionsAfterTrade(temp1)+totalOne - cutOne);

        }

        return val;

    }

    public static int countOne(int[] arr) {
        int cnt = 0;
        for(int num : arr){
            if(num == 1) cnt++;
        }
        return cnt;
    }

    private int maxActiveSectionsAfterTrade(int[] s) {
        int allOne = 0;
        int preZero = 0;//记录1块前0块的长度
        int curZero = 0;//记录当前0块的长度
        int maxSum = 0;
        // 标记是否已经收集到两段0
        boolean hasTwoZeroSeg = false;
        
        //遍历数组，不断更新1块前0块的长度，然后再记录1块后0块的长度，一直找这两个长度的最大值
        for (int c : s) {
            if (c == 1) {
                allOne++;
                if (curZero > 0) {
                    // 当前一段0结束
                    if (preZero > 0) {
                        // 存在前一段0，说明现在有两段0
                        hasTwoZeroSeg = true;
                        maxSum = Math.max(maxSum, preZero + curZero);
                    }
                    preZero = curZero;
                    curZero = 0;
                }
            } else {
                curZero++;
            }
        }
        // 最后一段0收尾
        if (preZero > 0 && curZero > 0) {
            hasTwoZeroSeg = true;
            maxSum = Math.max(maxSum, preZero + curZero);
        }

        // 如果不足两段独立0，不能执行操作，增益直接归零
        int gain = hasTwoZeroSeg ? maxSum : 0;
        return allOne + gain;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String input1 = "0100";
        int[][] queries1 = {{0,3},{0,2},{1,3},{2,3}};
        String input2 = "1000100";
        int[][] queries2 = {{1,5},{0,6},{0,4}};
        System.out.println(solution.maxActiveSectionsAfterTrade(input1,queries1));
        System.out.println(solution.maxActiveSectionsAfterTrade(input2,queries2));
    }

}
