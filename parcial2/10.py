# Let f(x) be numbers of positive integers a,b,c,d such that a*b + c*d = X
# find the maximun f(x) such that x is between 1 and N
def f(x):
    count = 0
    for a in range(1, x):
        for b in range(1, x):
            for c in range(1, x):
                for d in range(1, x):
                    if a*b + c*d == x:
                        count += 1
    return count


for i in range(1,50):
    print(f(i))