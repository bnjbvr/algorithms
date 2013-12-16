"""Given "n", generate all valid parenthesis strings of length "2n".

Example:
Given n=2

Output:
(())
()()

http://www.careercup.com/question?id=6234634354425856
"""

def generate(toOpen, toClose):
    results = []

    if toOpen == 0 and toClose == 0:
        return ['']

    if toOpen > 0:
        for r in generate(toOpen - 1, toClose + 1):
            results += ['(' + r]

    if toClose > 0:
        for r in generate(toOpen, toClose - 1):
            results += [')' + r]

    return results

def solution(n):
    return generate(n, 0)

print solution(0)
print solution(1)
print solution(2)
print solution(3)

s4 = solution(4)
print s4
assert(len(s4) == 14)

