import itertools


def bubble_sort(arr):
    for mx in range(len(arr) - 1, 1, -1):
        for i in range(len(arr[:mx])):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]

                yield arr, [i, i + 1]


def selection_sort(arr):
    for i in range(len(arr)):
        min_ndx = arr.index(min(arr[i:]))
        arr[i], arr[min_ndx] = arr[min_ndx], arr[i]
        yield arr, [i]


def radix_sort(arr):
    it = 0
    mx = max(arr)

    while 10 ** it < mx:
        buckets = [[] for _ in range(10)]

        for item in arr:
            digit = (item // (10 ** it)) % 10

            buckets[digit].append(item)

        arr = list(itertools.chain.from_iterable(buckets))
        yield arr, []

        it += 1
