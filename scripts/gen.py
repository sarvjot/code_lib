import random

t = 1
print(t)

for _ in range(3):
	for i in range(3):
		print(random.choice(['X', 'O', '_']), end = '')
	print()

print()