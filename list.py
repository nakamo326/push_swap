import random
import sys
list = list(range(int(sys.argv[1])))
random.shuffle(list)
s = ' '.join(map(str, list))
print(s)