# Long time no python~
# 2. In Python, write a function find(L, e) that takes in a sorted list L and an element e, and returns the lowest index in L such that L[i] == e. (-1 if there is no such index)
#    Write a function that takes in a sorted linst L and an element e, and returns the index of the highest index in L such that L[i] == e. (-1 if there is no such index).
#    The function should run in O(log(n)) time.
#    This should help you with Project 1.


def first(arr, x, n): # Internet
     
    low = 0
    high = n - 1
    res = -1
     
    while (low <= high):
         
        # Normal Binary Search Logic 
        mid = (low + high) // 2
         
        if arr[mid] > x:
            high = mid - 1
        elif arr[mid] < x:
            low = mid + 1
             
        # If arr[mid] is same as x, we 
        # update res and move to the left 
        # half. 
        else:
            res = mid
            high = mid - 1
 
    return res

# def find_first(L,e):
#     mid_point = len(L)//2
#     if L[mid_point] == e:
#         return len(L[:mid_point]) - find_first(L[:mid_point],e)
#     elif L[mid_point] < e:
#         return mid_point+find_first(L[mid_point:],e)
#     else:
#         return mid_point - find_first(L[:mid_point],e)
#     if len(L)==1:
#         if L[0] == e:
#             return 0
#         else:
#             return -1
#     return -1

def find_2(L, e):
    first = 0
    last = len(L)-1
    index = -1
    while (first <= last) and (index == -1):
        mid = (first+last)//2
        if L[mid] == e:
            if mid == 0:
                index = mid
            elif L[mid-1] == e:
                pass
            else:
                index = mid
    
        elif L[mid]>e:
            last = mid
        else:
            first = mid

    return index


def find_last(L,e):


    
    # L = L[::-1]
    return


if __name__ == "__main__":
    a = [1, 4, 4, 4, 4, 4, 5]
    find_2(a, 4)
    # find_first(a, 0)
    # find_last(a, 4)
    # find_last(a, 0)