#!/usr/bin/python3
"""
Rotate a 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """
    rotate 2D matrix 90 degrees clockwise.
    """
    [[matrix[j][i] for j in range(len(matrix))] for i in range(len(matrix[0]))]
