import random

n = 100000
w = 1000
peso_min = 1
peso_max = 1000000
val_min = 1
val_max = 100000000

print(f'{int(n)} {int(w)}')
for i in range(n):
  peso = random.randint(peso_min, peso_max)
  valor = random.randint(val_min, val_max)
  print(f'{peso} {valor}')