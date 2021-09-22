import sys
import random

del sys.argv[0:1]
random.shuffle(sys.argv)

print(sys.argv)
