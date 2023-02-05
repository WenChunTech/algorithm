from typing import List


def max_cross_sub_array(arr: List[int], low: int, mid: int, high: int) -> tuple[int, int, int]:
    sum = 0
    left_sum = 0
    left_index = mid
    right_mid = mid + 1
    right_index = right_mid
    while mid >= low:
        sum += arr[mid]
        if sum > left_sum:
            left_sum = sum
            left_index = mid
        mid -= 1

    sum = 0
    right_sum = 0
    while right_mid <= high:
        sum += arr[right_mid]
        if sum > right_sum:
            right_sum = sum
            right_index = right_mid
        right_mid += 1

    return left_index, right_index, left_sum + right_sum


def sub_array_max_sum(arr: List[int], low: int, high: int):
    if low == high:
        return low, high, arr[low]

    mid = (low + high) // 2

    left_low, left_high, left_sum = sub_array_max_sum(arr, low, mid)
    right_low, right_high, right_sum = sub_array_max_sum(arr, mid + 1, high)
    cross_low, cross_high, cross_sum = max_cross_sub_array(arr, low, mid, high)

    if left_sum >= right_sum >= cross_sum:
        print(1)
        return left_low, left_high, left_sum
    elif right_sum >= left_sum >= cross_sum:
        print(2)
        return right_low, right_high, right_sum
    else:
        print(3, cross_sum)
        return cross_low, cross_high, cross_sum

if __name__ == "__main__":
    arr = [-1, 3, 2, -3, 8]
    result = sub_array_max_sum(arr, 0, len(arr) - 1)
    print(result)