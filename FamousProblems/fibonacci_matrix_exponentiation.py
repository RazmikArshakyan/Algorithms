def multiply(a, b):
    mul = [[0 for x in range(3)]
              for y in range(3)]

    for i in range(3):
        for j in range(3):
            mul[i][j] = 0
            for k in range(3):
                mul[i][j] += a[i][k] * b[k][j]

    for i in range(3):
        for j in range(3):
            a[i][j] = mul[i][j]
    return a

def power(f, n):
    matrix = [[1, 1, 0], [1, 0, 0], [0, 1, 0]]

    if (n == 1):
        return f

    power(f, int(n // 2))
    
    f = multiply(f, f)

    if (n % 2 != 0):
        f = multiply(f, matrix)

    return f

def find_nth_num(n):
    f = [[1, 1, 0], [1, 0, 0], [0, 1, 0]]
    
    if n <= 1:
        return n

    result_matrix = power(f, n - 1)

    return result_matrix[0][0]

if __name__ == '__main__':
    print(find_nth_num(7))
    print(find_nth_num(8))
    print(find_nth_num(9))










