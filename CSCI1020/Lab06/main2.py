def getPerfectPairsCount(arr):
    count = 0
    for i in range(len(arr)):
        for j in range(i):
            if min(abs(arr[j] - arr[i]), arr[j]+arr[i]) <= min(abs(arr[i]), abs(arr[j])) and max(abs(arr[j] - arr[i]), arr[j]+arr[i]) >= max(abs(arr[i]), abs(arr[j])):
                count += 1
            print(i, j)
    return count


if __name__ == '__main__':
    print(getPerfectPairsCount([-9, 6, -2, 1]))
    print(getPerfectPairsCount([2, 5, -3]))
