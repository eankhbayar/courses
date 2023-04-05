#! /bin/python3 ™
#
# Complete the 'getMaxBarrier' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#

def getMaxBarrier(initialEnergy, th):
    n = len(initialEnergy)
    sum = 0
    for i in range(0, n):
        sum += initialEnergy[i]
    initialEnergy.sort()
    tmp = 0
    ans = 0
    last_res = 0
    # for i in range(0, n):
    #     if (last_res >= th) and (sum - tmp) - (n-i) * initialEnergy[i] <= th:
    #         for j in range(initialEnergy[i], initialEnergy[i-1], -1):
    #             if (sum - tmp) - (n-i) * j >= th:
    #                 ans = j
    #                 return ans

    #     if (sum - tmp) - (n-i) * initialEnergy[i] >= th:
    #         last_res = (sum - tmp) - (n-i) * initialEnergy[i]
    #         ans = initialEnergy[i]

    #     tmp += initialEnergy[i]

    # reverse for loop
    for i in range(n-1, -1, -1):
        tmp += initialEnergy[i]
        if tmp - (n-i) * initialEnergy[i] >= th:
            ans = initialEnergy[i]
            last_res = tmp - (n-i) * initialEnergy[i]
            res = (n-i) * initialEnergy[i] - th
            # print(tmp - (n-i) * initialEnergy[i], (n-i), initialEnergy[i])
            print(tmp)
            # print(res)
            # for j in range(initialEnergy[i], initialEnergy[i+1]):

            # return ans
    return ans


if __name__ == '__main__':
    print(getMaxBarrier([4, 8, 7, 1, 2], 9))
    # print(getMaxBarrier([5, 3, 13, 10], 8))
