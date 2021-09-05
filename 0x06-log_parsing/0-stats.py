#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics
"""
import sys

sizes = 0
counter = 0

status_codes = {'200': 0, '301': 0, '400': 0, '401': 0,
                      '403': 0, '404': 0, '405': 0, '500': 0}

try:
    for line in sys.stdin:
        line_list = line.split(" ")
        if len(line_list) > 2:
            code = line_list[-2]
            size = int(line_list[-1])
            if code in dict_codes_counter.keys():
                dict_codes_counter[code] += 1
            sizes += size
            counter += 1

        if counter == 10:
            print("File size: {:d}".format(sizes))
            for k, v in sorted(status_codes.items()):
                if v != 0:
                    print("{}: {:d}".format(k, v))
            counter = 0

except Exception:
    pass

finally:
    print("File size: {}".format(sizes))
    for k, v in sorted(status_codes.items()):
        if v != 0:
            print("{}: {}".format(k, v))
