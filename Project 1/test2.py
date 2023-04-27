def binary_search_deluxe(arr, n):
    left = binary_search_deluxe_left(arr, n)
    right = binary_search_deluxe_right(arr, n)
    return [left, right]

def binary_search_deluxe_left(L, target):
    left = 0
    right = len(L) - 1
    while left <= right:
        mid = (left + right) // 2
        if L[mid][0:len(target)] < target:
            left = mid + 1
        else:
            right = mid - 1
    return left

def binary_search_deluxe_right(L, target):
    left = 0
    right = len(L) - 1
    while left <= right:
        mid = (left + right) // 2
        if L[mid][0:len(target)] <= target:
            left = mid + 1
        else:
            right = mid - 1
    return right

print(binary_search_deluxe(["Shanghai", "Torino", "Toronto"], "Tor"))