

def construct_D_arr(L1, L2):

    m = len(L1)
    n = len(L2)
    d = [[0 for i in range(m)]for i in range(n)]
    for i in range(m):
        for n in range(n):
            if n == 0:
                d[i][n] == i
            construct_D_arr(L1[:i-1][:n-1])
    return d

def min_dist(L1, L2):
    cur_min = -1
    m = len(L1) 
    n = len(L2)
    d = construct_D_arr(L1, L2)
    for i in range(m):
        for n in range(n):
            if d[m][n] < cur_min:
                cur_min = d[m][n]

    return cur_min

def recover_path(L1, L2):
    path = 
