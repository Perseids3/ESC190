import numpy
def OPT(i, j, energies, L):

    if i == 0:
        return energies[i][j]
    elif L[i][j] != 0:
        return L[i][j]
    elif j == 0:
        L[i][j] = energies[i][j] + min(OPT(i-1,j,energies,L),OPT(i-1,j+1,energies,L))
      
    elif j == len(energies[0])-1:
        L[i][j] = energies[i][j] + min(OPT(i-1,j-1,energies,L), OPT(i-1,j,energies,L))

    else:
        L[i][j] = energies[i][j] + min(OPT(i-1,j-1,energies,L), OPT(i-1,j,energies,L),OPT(i-1,j+1,energies,L))

    return L[i][j]



energies = [[24, 22, 30, 15, 18, 19],
            [12, 23, 15, 23, 10, 15],
            [11, 13, 22, 13, 21, 14],
            [13, 15, 17, 28, 19, 21],
            [17, 17, 7, 27, 20, 19]]


L = numpy.zeros((len(energies),len(energies[0])))


for i in range(0, 5):#lines
    for j in range(0, 6):#rows
        L[i][j] = OPT(i, j, energies, L)

print(min(L[-1]))
