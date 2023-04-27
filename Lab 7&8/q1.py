'''
a) Suppose you have computed OPT(0), OPT(1), OPT(2), ..., OPT(n-1), the numbers of coins that are needed to make up 0c, 1c, 2c, ..., (n-1)c.
Write down an expression for OPT(n), in terms of the denominations and OPT(0), ...., OPT(n).
Hint: if you want to use the 5c coin, the total number of coins you'll need is OPT(n-5)+1

OPT(n) = min{1+OPT(n-list[i])}, 0<= i <= n
OPT(n) = 1 + min{OPT(n-list[0]), OPT(n-list[1]) ... OPT(n-list[n])}
'''

'''
b) Write code to compute OPT(0), then OPT(1), then OPT(2), ..., then OPT(n). You should write a function
that takes in the denominations list and the target amount, and returns the OPT list.
'''

import numpy as np
def make_change(denom, target):
    OPT = np.inf * np.ones(target+1)
    OPT[0] = 0
    for amount in range(1, target + 1):
        # check all denomiantions
        for d in denom:
            if amount-d >= 0:
                if OPT[amount-d] + 1 < OPT[amount]:
                    OPT[amount] = OPT[amount-d] + 1
    return OPT[target]

'''
c) Write code that returns a list of the coins you need to make up a target amount, when the least possible
number of coins is used. (For example, the function would return [4, 4], if the denominations are
[1c, 4c, 5c] and the target is 8).
Follow the example from houses.py. The first coin used, denom, should be such that 1 + OPT(n-denom)
is as small as possible. To determine the next coin, denom2, make 1 + 1 + OPT(n-denom-denom2) as
small as possible.
'''

def make_change(denom, target):
    OPT = np.inf * np.ones(target+1)
    OPT[0] = 0

    OPT_soln = {}
    OPT_soln[0] = []

    for amount in range(1, target + 1):
        # check all denomiantions
        for d in denom:
            if amount-d >= 0:
                if OPT[amount-d] + 1 < OPT[amount]:
                    OPT[amount] = OPT[amount-d] + 1
                    OPT_soln[amount] = OPT_soln[amount-d] + [d]
    return OPT[target], OPT_soln.get(target, None)
