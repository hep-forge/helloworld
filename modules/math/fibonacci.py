import numpy as np

def fibonacci(n):
    if n < 0:
        raise ValueError("Input should be a non-negative integer.")
    elif n == 0:
        return 0
    elif n == 1:
        return 1
    
    # Initialize an array with size n + 1
    fib_sequence = np.zeros(n + 1)
    fib_sequence[0] = 0
    fib_sequence[1] = 1
    
    for i in range(2, n + 1):
        fib_sequence[i] = fib_sequence[i - 1] + fib_sequence[i - 2]
    
    return fib_sequence[n]
