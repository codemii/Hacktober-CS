
"""
This is a pure Python implementation of Dynamic Programming solution to the fibonacci
fib problem.
"""


def fibonacci(index: int):
    fib = [0, 1]
    """
    Get `index` number of fibbonacci number.

    >>> fibbonacci(10)
    [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
    >>> fibbonacci(5)
    [0, 1, 1, 2, 3]
    """
    if (difference := index - (len(fib) - 2)) >= 1:
        for _ in range(difference):
            fib.append(fib[-1] + fib[-2])
    return fib[:index]


def main():
    print(
        "Fibonacci Series Using DP\n",
        "Enter a number for the Fibonacci numbers count you want to calculate ",
        "in the prompt below. (To exit enter exit or Ctrl-C)\n",
        sep="",
    )
    

    prompt = input(">> ")
    index = eval(prompt)
    print(fibonacci(index))


if __name__ == "__main__":
    main()