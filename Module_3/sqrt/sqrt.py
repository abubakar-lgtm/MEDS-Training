def sqrt_binary_search(x, precision=1e-7):
    if x < 0:
        raise ValueError("Cannot compute square root of negative number")
    if x == 0 or x == 1:
        return x

    low = 0
    high = x
    if x < 1:
        high = 1  

    while high - low > precision:
        mid = (low + high) / 2
        if mid * mid < x:
            low = mid
        else:
            high = mid

    return (low + high) / 2

num = 25
print(f"Square root of {num} ≈ {sqrt_binary_search(num)}")
