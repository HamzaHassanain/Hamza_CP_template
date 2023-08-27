ts = int(input())


def nc2(n):
    return n * (n - 1) // 2


for _ in range(ts):
    n = int(input())
    low = 1
    high = 10 ** 12
    ans = n
    while low <= high:
        mid = (low + high) // 2
        if nc2(mid) >= n:
            high = mid - 1
            ans = mid
        else:
            low = mid + 1

    if (nc2(ans) == n):
        print(ans)
    else:
        ans = ans-1
        n -= nc2(ans)
        print(n+ans)
