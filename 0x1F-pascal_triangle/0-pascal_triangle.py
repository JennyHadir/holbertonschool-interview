#!/usr/bin/python3
"""pascal triangle"""


def pascal_triangle(n):
    """pascals_triangle function"""
    res = []

    for i in range(n):
        a = [None for _ in range(i + 1)]
        a[0], a[-1] = 1, 1
        for j in range(1, len(a) - 1):
            a[j] = res[i - 1][j - 1] + res[i - 1][j]
        res.append(a)

    return
