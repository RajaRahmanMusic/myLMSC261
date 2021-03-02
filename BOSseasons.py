season = int(input("Please input a number between 1 ~ 12: "))
while season < 1 or season > 12:
    season = int(input("The number you entered is not between 1 ~ 12. Please input a number between 1 ~ 12: "))
else:
    if season <= 4 or season >= 11:
        if season < 7:
            print("Boston is in Spring.")
        elif season > 9:
            print("Boston is in Autumn.")
        else:
            print("Boston is in Summer.")
    else:
        print("Boston is in Winter.")
