def func(n):
    grow(n)
    print(n)
    shrink(n)


def f_then_g(f, g, n):
    if n:
        f(n)
        g(n)


def grow(n):
    f_then_g(grow, print, n//10)


def shrink(n):
    f_then_g(print, shrink, n//10)


# 写一个冒泡排序
def bubble_sort(lst):
    for i in range(len(lst)):
        for j in range(i+1, len(lst)):
            if lst[i] > lst[j]:
                lst[i], lst[j] = lst[j], lst[i]
