import random

with open('rand.txt', 'w') as file:
    quantity = int(input('Ile liczb losowych wygenerować: '))
    file.write(str(quantity) + '\n')
    for i in range(0, quantity):
        file.write(str(random.randrange(0, 100000)) + '\n')
