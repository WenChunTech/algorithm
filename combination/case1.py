"""
List<List<Integer>> res = new LinkedList<>();
// 记录回溯算法的递归路径
LinkedList<Integer> track = new LinkedList<>();

// 主函数
public List<List<Integer>> subsets(int[] nums) {
    backtrack(nums, 0);
    return res;
}

// 回溯算法核心函数，遍历子集问题的回溯树
void backtrack(int[] nums, int start) {

    // 前序位置，每个节点的值都是一个子集
    res.add(new LinkedList<>(track));

    // 回溯算法标准框架
    for (int i = start; i < nums.length; i++) {
        // 做选择
        track.addLast(nums[i]);
        // 通过 start 参数控制树枝的遍历，避免产生重复的子集
        backtrack(nums, i + 1);
        // 撤销选择
        track.removeLast();
    }
}
"""
from typing import List

final_result = []


def helper(arr: List[int], target: int, start: int, track: List[int]):
    count = sum(track)
    if count > target:
        return
    elif target == count:
        final_result.append(track.copy())
        return
    while start < len(arr):
        track.append(arr[start])
        helper(arr, target, start, track)
        track.pop()
        start += 1


def combinator(arr: List[int], target: int):
    helper(arr, target, 0, [])


if __name__ == '__main__':
    candidates = [1, 2, 3]
    target = 3
    combinator(candidates, target)
    print(final_result)