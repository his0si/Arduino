# 1
print((8+17)//8)

#2
n = int(input())
for i in range(1,10):
    print(f"{n}*{i}={int(n)*i}")

# 3
class Mod:
    def add(self, a, b):
        return a + b

    def sub(self, a, b):
        return a - b
    
    def mul(self, a, b):
        return a * b

    def div(self, a, b):
        if b == 0:
            return "0으로 나눌 수 없습니다."
        return a / b

calculator = Mod()

num1, num2 = map(int, input().split())

print(f"{num1} + {num2} = {calculator.add(num1, num2)}")
print(f"{num1} - {num2} = {calculator.sub(num1, num2)}")
print(f"{num1} * {num2} = {calculator.mul(num1, num2)}")
print(f"{num1} / {num2} = {calculator.div(num1, num2)}")