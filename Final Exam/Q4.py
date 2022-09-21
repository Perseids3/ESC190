import numpy as np
from numpy.linalg import norm


def func(v, u1, u2, u3):
    length = len(u1)
    w1 = [0] * length
    w2 = [0] * length
    w3 = [0] * length
    for i in range(length):
        w1[i] = v[i]-u1[i]
        w2[i] = v[i]-u2[i]
        w3[i] = v[i]-u3[i]
    
    f = (norm(w1))**2+(norm(w2))**2+(norm(w3))**2
    return f

def grad(v, u1, u2, u3):
    length = len(u1)
    grad_f = np.array([0]*length)
    for i in range(length):
        grad_f[i] = 2*(v[i]-u1[i]+ v[i]-u2[i] + v[i]-u3[i])
    return grad_f

def grad_descent(f, gradf, init_t, alpha):
    EPS = 1e-5
    prev_t = init_t-10*EPS
    t = init_t.copy()

    while norm(t - prev_t) >  EPS:
        prev_t = t.copy()
        t -= alpha * gradf(t[0], t[1],)
        print(t, f(t[0], t[1]), gradf(t[0], t[1]))

    return t

def min_dist(u1, u2, u3):
    length = len(u1)
    v = np.array([0]*length)
    alpha = 0.001
    grad_descent(func, grad, v, alpha)
    # return t


min_dist([1,3,4], [0,0,0], [9,8,7])
  
    




