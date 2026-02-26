#1
name = input("What is your name? ")
print( "Hello"+" "  + name)
id=input("What is your Student id?")
print("your id is: "+ id)

#2
total_number=int(input("a total number of seconds"))
hours=total_number/3600
remaining_seconds = total_number % 3600
minutes = remaining_seconds // 60
seconds = remaining_seconds % 60
print(f"{total_number} seconds is {hours} hours, {minutes} minutes, and {seconds} seconds.")


#3
import math

x1 = float(input("Enter x1: "))
y1 = float(input("Enter y1: "))

x2 = float(input("Enter x2: "))
y2 = float(input("Enter y2: "))

distance = math.sqrt((x2 - x1)**2 + (y2 - y1)**2)


print(f"Distance = {distance}")


#4
print("*******\n *****\n  ***\n   *")
