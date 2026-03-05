#Task 1 (Hailstone Sequence (Collatz Conjecture)

n = int(input("Please Enter greater than 1: "))
steps=0
print(n, end="")
while n != 1:
    if n % 2 == 0:
        n = n // 2
    else:
        n = n * 3 + 1
    print(f" -> {n}", end="")
    steps += 1

print( "\nTotal steps: ", steps)


#Task 2 (FizzBuzz Counter)

while True:
    n = int(input("Please enter a number between 10 and 100: "))
    if 10 <= n <= 100:
        break
    print("İnvalid input.")

fizz, buzz, fizzbuzz = 0, 0, 0

for i in range(1, n + 1):
    if i % 7 == 0:
        print("(7 is skipped)")
        continue

    if i % 3 == 0 and i % 5 == 0:
        print("FizzBuzz")
        fizzbuzz += 1
    elif i % 3 == 0:
        print("Fizz")
        fizz += 1
    elif i % 5 == 0:
        print("Buzz")
        buzz += 1
    else:
        print(i)

print(f"Summary - Fizz: {fizz}, Buzz: {buzz}, FizzBuzz: {fizzbuzz}")

#Task 3
n = int(input("Please enter a number between 3 and 9: "))

for i in range(1, 2 * n):
    yildiz_sayisi = n - abs(n - i)
    print("*" * yildiz_sayisi)
