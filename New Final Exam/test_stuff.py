import numpy as np

def construct_D_arr(L1, L2):
    len_l1 = len(L1)
    len_l2 = len(L2)
    D = np.zeros((len_l1+1,len_l2+1))
    for i in range(len_l1+1):
        for j in range(len_l2+1):
            if j == 0:
                D[i][j] = i
            elif i == 0:
                D[i][j] = j
            elif L1[:i] == L2[:j]:
                D[i][j] = 0
            elif i > j:
                D[i][j] = D[i-1][j] + 1
            elif j > i:
                D[i][j] = D[i][j-1] + 1
            elif L1[:i] != L2[:j]:
                D[i][j] = D[i-1][j-1] +1
    return D
print(construct_D_arr([1, 2], [1, 3]))
