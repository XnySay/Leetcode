def isPalindrome(x: int) -> bool:
    # 负数 或 末尾为0且不是0，直接False
    if x < 0 or (x % 10 == 0 and x != 0):
        return False
    
    reverse_half = 0
    while x > reverse_half:
        reverse_half = reverse_half * 10 + x % 10
        x = x // 10
    
    # 偶数位相等 / 奇数位去掉中间数字相等
    return x == reverse_half or x == reverse_half // 10

# 测试
print(isPalindrome(1221))  # True
print(isPalindrome(12321)) # True
print(isPalindrome(-123))  # False
print("这个数字是回文数吗？")