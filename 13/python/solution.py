def romanToInt(s: str) -> int:
    roman_map = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }
    total = 0
    n = len(s)
    for i in range(n):
        # 如果不是最后一位，且当前数字小于后面数字，做减法
        if i < n - 1 and roman_map[s[i]] < roman_map[s[i+1]]:
            total -= roman_map[s[i]]
        else:
            total += roman_map[s[i]]
    return total

# 测试示例
if __name__ == "__main__":
    print(romanToInt("III"))      # 3
    print(romanToInt("IV"))       # 4
    print(romanToInt("IX"))       # 9
    print(romanToInt("LVIII"))    # 58
    print(romanToInt("MCMXCIV"))  # 1994