def insertion_sort(B):
    """Sort using insertion method

    >>> insertion_sort([5, 4, 3, 2, 1])
    [1, 2, 3, 4, 5]

    >>> insertion_sort([])
    []
    """
    A = B[:]
    for j in range(1, len(A)):
        key = A[j]
        i = j - 1
        while i >= 0 and A[i] > key:
            A[i + 1] = A[i]
            i -= 1
        A[i + 1] = key
    return A


def merge(A, B):
    """Merge two lists in order:

    >>> merge([1, 2, 3], [4, 5, 6])
    [1, 2, 3, 4, 5, 6]

    >>> merge([1, 3, 5], [2, 4])
    [1, 2, 3, 4, 5]

    >>> merge([], [])
    []
    """
    i = 0
    j = 0
    C = []
    while i < len(A) and j < len(B):
        if A[i] < B[j]:
            C.append(A[i])
            i += 1
        else:
            C.append(B[j])
            j += 1
    if i < len(A):
        C.extend(A[i:])
    elif j < len(B):
        C.extend(B[j:])
    return C


def merge_sort(B):
    """Merge two lists in order:

    >>> merge_sort([5, 4, 3, 2, 1])
    [1, 2, 3, 4, 5]

    >>> merge_sort([])
    []
    """
    if len(B)>1:
        a = merge_sort(B[:len(B)//2])
        b = merge_sort(B[len(B)//2:])
        return merge(a, b)
    else:
        return B
