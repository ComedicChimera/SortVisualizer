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


def merge_sort(arr):
    def merge(a, b):
        odd = None
        if len(a) > len(b):
            odd = a.pop()
        elif len(a) < len(b):
            odd = b.pop()

        merged_set = []

        for i, j in zip(a, b):
            if i > j:
                merged_set.extend([j, i])
            else:
                merged_set.extend([i, j])

        if odd:
            if merged_set[-1] < odd:
                merged_set.append(odd)
            else:
                merged_set.extend([odd, merged_set.pop()])

        return merged_set

    pool = list(map(list, zip(*[iter(arr)] * 2)))
    if len(arr) % 2 != 0:
        pool[-1].append(arr[-1])

    while len(pool) > 1:
        for i in range(0, len(pool), 2):
            if i + 1 < len(pool):
                pool[i] = merge(pool[i], pool[i+1])

        pool = [pool[i] for i in range(0, len(pool)) if i % 2 != 0]
