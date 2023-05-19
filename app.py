tc = int(input())

for i in range(tc):
    nq = list(map(int, input().split()))
    n = nq[0]
    q = nq[1]
    for i in range(q):
        num_x = list(map(int, input().split()))
        num = num_x[0]
        x = num_x[1]
        if num == 1:
            n = n*x
        else:
            root = pow(n, 1/x)
            if root == int(root):
                print("Integer")
            else:
                print("Not integer")
