#!/usr/bin/python3
""" Count Method
"""
from collections import Counter, defaultdict
import requests


def count_words(subreddit, word_list, count=None, after=None):
    headers = {"User-Agent": ""}
    url = "https://www.reddit.com/r/{}}/hot.json".format(subreddit)
    response = requests.get(url, headers=headers, allow_redirects=False)
    if response.status_code == 200:
        if count is None:
            count = defaultdict(int)
        data = response.json().get('data')
        page = Counter(
            word for article in data.get('children')
            for word in article.get('data').get('title').casefold().split()
        )
        for word in word_list:
            if word.casefold() in page:
                count[word.casefold()] += page.get(word.casefold())
        if data.get('after') is None:
            by_key = sorted(count.items(), key=lambda x: x[0])
            for key, value in sorted(by_key, key=lambda x: x[1], reverse=True):
                print('{}: {}'.format(key, value))
        else:
            count_words(subreddit, word_list, count, data.get('after'))

    