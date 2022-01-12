#!/usr/bin/python3
"""Get request to reddit API"""
import requests


def count_words(subreddit, word_list, first_call=True, after="", dic={}):
    """Cound # of keywords"""
    if first_call:
        word_list = list(set(word_list))
        for i, e in enumerate(word_list):
            word_list[i] = e.lower()
        d = count_words(subreddit, word_list, False)
        if d:
            for key, value in sorted(d.items(), key=lambda x: (-x[1], x[0])):
                print("{}: {}".format(key, value))
        elif d is None:
            return None
    else:
        base_url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
        h = {'User-Agent': 'Reddit API test'}
        params = {'limit': 200, 'after': after}
        r = requests.get(base_url, headers=h,
                         allow_redirects=False, params=params)
        if r.status_code != 200:
            return None
        d = r.json()
        if after is None:
            return dic
        l = d.get('data', {}).get('children')
        for i in l:
            title = i.get('data', {}).get('title').lower().split()
            for j in word_list:
                for t in title:
                    if j == t:
                        if j not in dic:
                            dic[j] = 1
                        else:
                            dic[j] += 1
        p = d.get('data', {}).get('after')
        return count_words(subreddit, word_list, False, p, dic)
