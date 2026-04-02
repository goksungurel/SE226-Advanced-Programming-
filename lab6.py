def factorial(n):
    if n==0:
        return 1
    else:
        return n*factorial(n-1)


calculate=lambda x,n:(x**n) /factorial(n)


def exp_x(x, n):
    total = 0
    for i in range(n):
        total +=calculate(x,i)
    return total


xvalue=float(input("X değerini giriniz: "))
nvalue=float(input("Terim sayısı n giriniz: "))

print(calculate(xvalue, nvalue))


result= 0

def solve_series(n):
    """ RECUSİVE OLARAK İŞLEMİ HESAPLIYORUZ HER AŞAMADA TOPLAMI RESULT DEĞERİNE EŞİTLİCEM"""
    global result
    if n<1:
        return 1
    sign = 1 if n % 2 != 0 else -1
    result += sign * (1 / n)

    solve_series(n - 1)
