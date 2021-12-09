#!/usr/bin/python3
""" Count Method
"""

import requests


def count_words(subreddit, word_list):
    headers = {"User-Agent": ""}
    url = "https://www.reddit.com/r/{}}/hot.json".format(subreddit)
    response = requests.get(url, headers=headers, allow_redirects=False).json()