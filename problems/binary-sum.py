"""You have two numbers decomposed in binary representation, write a function that sums them and returns the result.

Input: 100011, 100100
Output: 1000111

http://www.careercup.com/question?id=4892713614835712
"""

b1 = '100011'
b2 = '100100'

maxLength = max(len(b1), len(b2))
bb1 = '0'*(maxLength - len(b1)) + b1
bb2 = '0'*(maxLength - len(b2)) + b2

carry = 0
r = ''
for i in range(maxLength):
    j = maxLength - i - 1
    bit1 = int(bb1[j])
    bit2 = int(bb2[j])
    sumbits = bit1 + bit2 + carry
    r = str(sumbits % 2) + r
    carry = sumbits // 2
if carry:
    r = '1' + r
print r
