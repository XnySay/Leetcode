public class solution {
    public int maxActiveSectionsAfterTrade(String s) {
        int allOne = 0;
        int preZero = 0;//记录1块前0块的长度
        int curZero = 0;//记录当前0块的长度
        int maxSum = 0;
        // 标记是否已经收集到两段0
        boolean hasTwoZeroSeg = false;
        
        //遍历数组，不断更新1块前0块的长度，然后再记录1块后0块的长度，一直找这两个长度的最大值
        for (char c : s.toCharArray()) {
            if (c == '1') {
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
        String input1 = "01";
        String input2 = "01010";
        solution test = new solution();
        System.out.println(input1 + " 最大活跃区段数为：" + test.maxActiveSectionsAfterTrade(input1));
        System.out.println(input2 + " 最大活跃区段数为：" + test.maxActiveSectionsAfterTrade(input2));
    }
}
