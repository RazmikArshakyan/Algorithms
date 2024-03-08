def multiply(x, y):
    n = max(len(x), len(y))
    x = x.zfill(n)
    y = y.zfill(n)

    if n == 0:
        return 0
    if n == 1:
        return int(x[0]) * int(y[0])

    lh = n // 2
    rh = n - lh

    xl = x[:lh]
    xr = x[lh:]

    yl = y[:lh]
    yr = y[lh:]

    p_1 = multiply(xl, yl)
    p_2 = multiply(xr, yr)
    p_3 = multiply(str(int(xl, 2) + int(xr, 2)), str(int(yl, 2) + int(yr, 2)))

    return p_1 * (1 << (2 * rh)) + (p_3 - p_2 - p_1) * (1 << rh) + p_2

if __name__ == '__main__':
    print(multiply("111", "111")) # should print 49
    print(multiply("1100", "1010")) # should print 120
