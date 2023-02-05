from re import I
from typing import List


def longest(num: List[int]):
    index = 0
    while index < len(num):
        result = longest(num[index+1:])
        final_result = max(result, index)