import numpy as np

def kok(D):
    return D[np.where(D[1:] == D[:1])]
a = np.array([1,2,2,2])
print(kok(a))