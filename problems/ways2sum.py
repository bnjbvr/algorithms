"""Given a number N, write a program that returns all possible combinations of numbers that add up to N, as lists. (Exclude the N+0=N)

For example, if N=4 return {{1,1,1,1},{1,1,2},{2,2},{1,3}}

http://www.careercup.com/question?id=6321181669982208"""

class ComputeSolution:
    def __init__(self):
        self.results = []

    def generate(self, n, maxValue, sol):
        for i in range(1, maxValue + 1):
            if n > i:
                self.generate(n - i, i, sol + [i])
            elif n == i:
                self.results += [sol + [i]]

def solution(n):
    cs = ComputeSolution()
    cs.generate(n, max(1, n - 1), [])
    return cs.results

def check_solution(n, s):
    i = 0
    print n,
    for array in s:
        print '=', ' + '.join([str(k) for k in array]),
        assert(sum(array) == n)
        i = 1
    print

def autotest():
    for i in range(7):
        sol = solution(i)
        check_solution(i, sol)

def stats():
    pl = float(1)
    i = 1
    while True:
        l = len(solution(i))
        print l / pl
        pl = float(l)
        i += 1

if __name__ == '__main__':
    autotest()
    stats()

