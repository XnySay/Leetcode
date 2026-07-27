import java.util.HashMap;
import java.util.Map;

public class solution {
    public static void main(String[] args) {
        solution a = new solution();
        System.out.println(a.romanToInt("MCMXCIV"));
        System.out.println(a.romanToInt("LVIII"));
    }

    public int romanToInt(String s) {

        Map<Character, Integer> map = new HashMap<>();
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);

        // int sum = 0;
        // int len = s.length();
        // for (int i = 0; i < len; i++) {
        //     int cur = map.get(s.charAt(i));
        //     // 如果不是最后一位，且当前值小于下一位，做减法
        //     if (i < len - 1 && cur < map.get(s.charAt(i + 1))) {
        //         sum -= cur;
        //     } else {
        //         sum += cur;
        //     }
        // }
        // return sum;
        int sum = 0;
        int prev = 0; // 记录上一个（右侧）字符的值
        // 倒着循环，i从最后一位到0
        for (int i = s.length() - 1; i >= 0; i--) {
            int curr = map.get(s.charAt(i));
            if (curr >= prev) {
                sum += curr;
            } else {
                sum -= curr;
            }
            prev = curr;
        }
        return sum;
    }
}
