def fizzbuzz(i):
    if (i % 3 == 0) and (i % 5 == 0):
        print("FizzBuzz")
    else:
        if (i % 3 == 0):
            print("Fizz")
        elif (i % 5 == 0):
            print("Buzz")
for i in range(1, 101, 1):
    if (i % 3 == 0) or (i % 5 == 0):
        fizzbuzz(i)
    else:
        print(i)
