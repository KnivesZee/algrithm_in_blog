def getIndexOf(str1, str2):
    if len(str1) < len(str2):
        return [-1]
    next = getNext(str2)
    i = 0
    j = 0
    while i < len(str1) and j < len(str2):
        if str1[i] == str2[j]:
            i += 1
            j += 1
        elif next[j] == -1:
            i += 1
        else:
            j = next[j]
    return i - j if j == len(str2) else -1

def getNext(str2):
    if(len(str2) == 1):
        return [-1]
    next = [0] * len(str2)
    next[0] = -1
    next[1] = 0
    i = 2
    cn = 0
    while i < len(str2):
        if str2[i-1] == str2[cn]:
            cn += 1
            next[i] = cn
            i += 1
        else:
            if cn == 0:  #跳无可跳的时候
                next[i] = 0
                i += 1
            else:
                cn = next[cn]
    return next