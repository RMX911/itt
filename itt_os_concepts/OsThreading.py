import threading
import time
import math
import os
import random
import re
import sys

count = 0
def add():
  global count
  for x in range(100000):
       count = count + 1
  time.sleep(1)


if __name__ == '__main__':
    input = int(input().strip())
    threads = [] 
    steps = input//100000
    for i in range(steps):
        threads.append(threading.Thread(target=add))
    for thread in threads:
        thread.start()
        thread.join()

print(count)

