def binary_search_deluxe(arr, n):
    left = binary_search_deluxe_left(arr, n)
    right = binary_search_deluxe_right(arr, n)
    return [left, right]

def binary_search_deluxe_left(L, target):
    '''Return the index of the first occurrence of target in L.'''
    left = 0
    right = len(L) - 1
    while left <= right:
        mid = (left + right) // 2
        if L[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return left

def binary_search_deluxe_right(L, target):
    '''Return the index of the last occurrence of target in L.'''
    left = 0
    right = len(L) - 1
    while left <= right:
        mid = (left + right) // 2
        if L[mid] <= target:
            left = mid + 1
        else:
            right = mid - 1
    return right

print(binary_search_deluxe([1, 2, 3, 10, 10, 10, 12, 12], 10))