#!/usr/bin/python3
"""
determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    """
    Return: True if data is a valid UTF-8 encoding, else return False
    """
    try:
        bytes(number & 0xFF for number in data).decode()
        return True
    except UnicodeDecodeError:
        return False