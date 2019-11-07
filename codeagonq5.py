# Implement Fenwick Tree
class onlineQuery:
    def __init__(self, A):
        self.n = len(A) + 1
        self.data = [0] * self.n
        self.presum = [0] * self.n
        for i, x in enumerate(A, 1):
            self.add(i, x)

    def add(self, i, k):
        if k == 0:
            return
        self.data[i] += k
        while i < self.n:
            self.presum[i] += k
            i += i & (-i)

    def sum(self, i):
        ans = 0
        while i > 0:
            ans += self.presum[i]
            i -= i & (-i)
        return ans

    def change_value(self, x, v):
        self.add(x + 1, v - self.data[x + 1])

    def sum_no_greater(self, x):
        return self.sum(x + 1)


print('Q5')
A = [1, 2, 3, 4, 5]
queries = [
    ('C', [0, 3]),
    ('S', [4]),
    ('C', [2, -1]),
    ('C', [4, 0]),
    ('S', [4]),
    ('S', [2])
]
oq = onlineQuery(A)
for cmd, args in queries:
    if cmd == 'C':
        oq.change_value(*args)
        print('change', args, oq.data[1:])
    else:
        ans = oq.sum_no_greater(*args)
        print('sum', args, ans)
print(' ')