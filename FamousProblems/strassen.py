class Strassen:
    def split(self, P, C, iB, jB):
        for i1 in range(len(C)):
            for j1 in range(len(C)):
                C[i1][j1] = P[iB + i1][jB + j1]
    
    def join(self, C, P, iB, jB):
        for i1 in range(len(C)):
            for j1 in range(len(C)):
                P[iB + i1][jB + j1] = C[i1][j1]

    def add(self, A, B):
        n = len(A)
        C = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n):
            for j in range(n):
                C[i][j] = A[i][j] + B[i][j]
        return C
    
    def sub(self, A, B):
        n = len(A)
        C = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n):
            for j in range(n):
                C[i][j] = A[i][j] - B[i][j]
        return C

    def multiply(self, A, B):
        n = len(A)
        R = [[0 for _ in range(n)] for _ in range(n)]

        if n == 1:
            R[0][0] = A[0][0] * B[0][0]
        else:
            A11 = [[0 for _ in range(n // 2)] for _ in range(n // 2)]
            A12 = [[0 for _ in range(n // 2)] for _ in range(n // 2)]
            A21 = [[0 for _ in range(n // 2)] for _ in range(n // 2)]
            A22 = [[0 for _ in range(n // 2)] for _ in range(n // 2)]
            B11 = [[0 for _ in range(n // 2)] for _ in range(n // 2)]
            B12 = [[0 for _ in range(n // 2)] for _ in range(n // 2)]
            B21 = [[0 for _ in range(n // 2)] for _ in range(n // 2)]
            B22 = [[0 for _ in range(n // 2)] for _ in range(n // 2)]

            self.split(A, A11, 0, 0)
            self.split(A, A12, 0, n // 2)
            self.split(A, A21, n // 2, 0)
            self.split(A, A22, n // 2, n // 2)

            self.split(B, B11, 0, 0)
            self.split(B, B12, 0, n // 2)
            self.split(B, B21, n // 2, 0)
            self.split(B, B22, n // 2, n // 2)

            M1 = self.multiply(self.add(A11, A22), self.add(B11, B22))
            M2 = self.multiply(self.add(A21, A22), B11)
            M3 = self.multiply(A11, self.sub(B12, B22))
            M4 = self.multiply(A22, self.sub(B21, B11))
            M5 = self.multiply(self.add(A11, A12), B22)
            M6 = self.multiply(self.sub(A21, A11), self.add(B11, B12))
            M7 = self.multiply(self.sub(A12, A22), self.add(B21, B22))

            # P = M2+M3-M6-M7
            C11 = self.add(self.sub(self.add(M1, M4), M5), M7)
            # Q:=M4+M6
            C12 = self.add(M3, M5)
            # R:=M5+M7
            C21 = self.add(M2, M4)
            # S:=M1−M3−M4−M5
            C22 = self.add(self.sub(self.add(M1, M3), M2), M6)

            self.join(C11, R, 0, 0)
            self.join(C12, R, 0, n // 2)
            self.join(C21, R, n // 2, 0)
            self.join(C22, R, n // 2, n // 2)

        return R

if __name__ == "__main__":
    s = Strassen()

    N = 4
    A = [[1, 2, 3, 4],
         [4, 3, 0, 1],
         [5, 6, 1, 1],
         [0, 2, 5, 6]]
    
    B = [[1, 0, 5, 1],
         [1, 2, 0, 2],
         [0, 3, 2, 3],
         [1, 2, 1, 2]]

    C = s.multiply(A, B)

    for i in range(N):
        for j in range(N):
            print(C[i][j], end=" ")
        print()