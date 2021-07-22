#!/usr/bin/python3
""" canUnlockAll function"""


def canUnlockAll(boxes):
    """ determines if all the boxes can be opened."""
    KeysLs = [0]
    for key in KeysLs:
        for value in boxes[key]:
            if value not in KeysLs and value < len(boxes):
                KeysLs.append(value)
    if len(boxes) != len(KeysLs):
        return False
    return True
