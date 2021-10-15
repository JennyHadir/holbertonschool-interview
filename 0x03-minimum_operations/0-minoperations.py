#!/usr/bin/python3
"""Minimum operations"""


def minOperations(n):
    """Minimum operations"""
    if type(n) is not int or n <= 1:
        return 0
    cp = 1
    num = 1
    operation = 1
    while num < n:
        if n % num == 0 and num != cp:
            copy = num_h
            operation += 1
        num = num + cp
        operation += 1
    if num == n:
        return operation
    return 0
