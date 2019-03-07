import random

with open('rand.txt','w') as file:
	for i in range(0,10):
		file.write(str(random.randrange(0,1000000)) + '\n')
