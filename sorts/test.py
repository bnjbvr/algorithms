import subprocess
import sys
from random import randint as rand

def Exec(args):
    o = subprocess.check_output(args, stderr=subprocess.STDOUT)
    return o.decode("utf-8")

def TestArray(prog, v):
    res = '[no output]'
    sortedAsString = ' '.join([str(val) for val in sorted(v)])

    try:
        args = [prog]
        args += [str(len(v))]
        args += [str(i) for i in v]

        res = Exec(args)
        assert(res == sortedAsString)
    except Exception as e:
        print "Error: ", e
        print res
        print sortedAsString
        return False
    return True

def Basics(prog):
    arrays = [
            [],
            [1, 2, 3, 42, 51, 69],
            [2, 7, 4, 1, 7, 3, 8, 5, 10, 6, 7, 8],
            [10, 9, 7, 5, 3, 2, 1],
            [10, 9, 7, 3, 6, 2, 1],
            ]
    for a in arrays:
        if not TestArray(prog, a):
            return False
    return True

def Randoms(prog, n = 1000):
    for i in range(21):
        a = [rand(0, n) for i in range(n)]
        assert(len(a) == n)
        if not TestArray(prog, a):
            return False
    return True

if __name__ == '__main__':
    if len(sys.argv) != 2:
        sys.exit('Please indicate the path to the program you would like to test')

    prog = sys.argv[1]
    if not Basics(prog) or not Randoms(prog):
        print "Some tests failed"
