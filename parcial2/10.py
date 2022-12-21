# Let f(x) be numbers of positive integers a,b,c,d such that a*b + c*d = X
# find the maximun f(x) such that x is between 1 and N
from math import sqrt

def f(x):
	count = 0
	for a in range(1, x):
		for b in range(1, x):
			for c in range(1, x):
				for d in range(1, x):
					if a*b + c*d == x:
						print(a,b,c,d)
						count += 1
	return count

def max_f(N):
  F = [0] * (N + 1)  # Initialize array F to 0
  P = [True] * (N + 1)  # Initialize array P to True
  P[0] = P[1] = False  # Set P[0] and P[1] to False
  for x in range(2, N + 1):
    if P[x]:  # If x is a prime
      F[x] = 1  # Increment F[x] by 1
      # Mark all multiples of x as composite
      for i in range(2, N // x + 1):
        P[x * i] = False
    # Iterate through the values of a and b such that a * b <= x
    for a in range(1, int(sqrt(x)) + 1):
      for b in range(1, int(sqrt(x)) + 1):
        if a * b <= x and P[a] and P[b]:  # If a and b are both prime
          F[x] += 1  # Increment F[x] by 1
  return F  
  
if __name__ == '__main__':
	a = max_f(10)
	b = [f(i) for i in range(1, 11)]
	print(a)
	print(b)