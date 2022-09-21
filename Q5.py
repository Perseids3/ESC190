import numpy as np

def construct_D_arr(L1,L2):
    ArrayList = []

    for i in range(len(L1)+1):
        ArrayList.append([])
        for j in range(len(L2)+1):
            ArrayList[i].append(0)

    for i in range(len(L1)+1):
        for j in range(len(L2)+1):

            countsame = 0
            List = []
            difflist = []

            list1 = L1[:i]
            list2 = L2[:j]
    

            m=len(list1)
            n=len(list2)

            if m>n:
                zipobject = zip(list1,list2)
                for i,j in zipobject:
                    difflist.append(i-j)

                for k in difflist:
                    if k == 0:
                        countsame += 1
                countdiff = n-countsame

            else:
                zipobject = zip(list2,list1)
                for i,j in zipobject:
                    difflist.append(i-j)
                    
                for k in difflist:
                    if k == 0:
                        countsame += 1
                countdiff = m-countsame

            for i in range(m+1):
                List.append([])
                for j in range(n+1):
                    List[i].append(0)

            for i in range(m+1):
                for j in range(n+1):
                    if(i==0 or j==0):
                        List[i][j] = 0
                    elif(list1[i-1]==list2[j-1]):
                        List[i][j] = List[i-1][j-1]+1
                    else:
                        List[i][j] = max(List[i-1][j],List[i][j-1])
            
            count = m+n - 2*List[m][n]-countdiff
            
            ArrayList[i][j] = count
            
    array = np.array(ArrayList)
    return array


def min_dist(L1,L2):
    m=len(L1)
    n=len(L2)
    countsame = 0
    List = []
    difflist = []


    if m>n:
        zipobject = zip(L1,L2)
        for i,j in zipobject:
            difflist.append(i-j)

        for k in difflist:
            if k == 0:
                countsame += 1
        countdiff = n-countsame

    else:
        zipobject = zip(L2,L1)
        for i,j in zipobject:
            difflist.append(i-j)
            
        for k in difflist:
            if k == 0:
                countsame += 1
        countdiff = m-countsame
 
    
    for i in range(m+1):
        List.append([])
        for j in range(n+1):
            List[i].append(0)

    for i in range(m+1):
        for j in range(n+1):
            if(i==0 or j==0):
                List[i][j] = 0
            elif(L1[i-1]==L2[j-1]):
                List[i][j] = List[i-1][j-1]+1
            else:
                List[i][j] = max(List[i-1][j],List[i][j-1])
    
    count = m+n - 2*List[m][n]-countdiff
    return count
