package main;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class Solution{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("输入行数m：");
        int m = sc.nextInt();
        System.out.print("输入列数n：");
        int n = sc.nextInt();
        int[][] grid = new int[m][n];
        for (int i = 0; i < m; i++) {
            System.out.print("第"+(i+1)+"行：");
            for (int j = 0; j < n; j++) grid[i][j] = sc.nextInt();
        }
        System.out.print("输入平移k：");
        int k = sc.nextInt();
        sc.close();
        methods1 sol = new methods1();
        List<List<Integer>> ans = sol.shiftGrid(grid, k);
        System.out.println(ans);
    }
}


//解法一：把二维数组转换成一维数组，然后按照每个元素向后移动一位移动k次
class methods1 {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length;        // 行数
        int n = grid[0].length;     // 列数
        int total = m * n;
        k = k % total;

        //数组按行转化成1维
        int[] yiWei = new int[total];
        int idx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                yiWei[idx++] = grid[i][j];
            }
        }

        // 移动
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                // 计算平移后对应一维数组下标
                int pos = (total - k + i * n + j) % total;
                row.add(yiWei[pos]);
            }
            res.add(row);
        }
        return res;
    }
}

//解法二：
class methods2 {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int len = m * n;
        int off = k % len;

        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            List<Integer> line = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                // 当前结果一维位置
                int curIdx = i * n + j;
                // 算出对应原数组的一维位置
                int srcIdx = (curIdx - off + len) % len;
                // 转回原二维行列
                int r = srcIdx / n;
                int c = srcIdx % n;
                line.add(grid[r][c]);
            }
            res.add(line);
        }
        return res;
    }
}
