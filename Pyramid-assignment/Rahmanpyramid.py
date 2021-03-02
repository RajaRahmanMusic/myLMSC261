stacks = int(input("How tall would you like the pyramid to be? (Please choose a number between 1 and 8)\n"))
if stacks < 1:
    print("Sorry your number is too low!")
elif stacks > 8:
    print("Sorry your number is too high!")
else:
    for i in range(0, stacks+1):
        for j in range(stacks+2, i, -1):
            print((" "), end="")
        print(i*("#"))
