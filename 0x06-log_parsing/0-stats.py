#!/usr/bin/python3
"""
script that reads stdin line by line and computes metrics
"""
import sys

size = 0
counter = 0
status_code = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}
try:
    for line in sys.stdin:
        items = line.split(" ")
        if len(items) > 2:
            code = items[-2]
            size += int(items[-1])
            if code in status_code:
                status_code[code] += 1
            counter += 1
        if counter == 10:
            print("File size: {}".format(size))
            for status in sorted(status_code.keys()):
                if status_code[status]:
                    print("{}: {}".format(status, status_code[status]))
            counter = 0

except KeyboardInterrupt:
    pass

finally:
    print("File size: {}".format(size))
    for status in sorted(status_code.keys()):
        if status_code[status]:
            print("{}: {}".format(status, status_code[status]))
