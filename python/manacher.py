def handleString(str):
    res = ""
    index = 0
    i = 0
    while i < 2 * len(str) + 1:
        if i%2 == 0:
            res += '#'
        else:
            res += str[index]
            index += 1
        i += 1
    return res

def getMaxcpsLength(str):
    if str == '':
        return 0
    str = handleString(str)
    pArr = [0] * len(str)
    C = -1
    R = -1
    theMax = -1
    i = 0
    while i < len(str):
        pArr[i] = min(pArr[2 * C - i], R - i) if R > i else 1 #（2*c-i）为i'的位置，谁离我更近，谁就是瓶颈
        while i + pArr[i] < len(str) and i - pArr[i] > -1: #接下来要验证的区域没越界，并且我左边区域也没越界
            if str[i + pArr[i]] == str[i - pArr[i]]:
                pArr[i] += 1
            else:
                break
        if i + pArr[i] > R:
            R = i + pArr[i]
            C = i
        theMax = max(theMax, pArr[i])
        i += 1
    return int(theMax/2)