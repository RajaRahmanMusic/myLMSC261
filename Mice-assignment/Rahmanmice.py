months = int(input("How many months are in a year? "))
while months != 12:
    months = int(input("Wrong number, try again! How many months are in a year? "))
beatles = int(input("How many members did the Beatles have? "))
while beatles != 4:
    beatles = int(input("Wrong number, try again! How many members did the Beatles have? "))
print(f"{int(months/beatles)}\n\tBlind\n\t\tMice")
