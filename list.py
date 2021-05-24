import random
list = list(range(100))
random.shuffle(list)
s = ' '.join(map(str, list))
print(s)