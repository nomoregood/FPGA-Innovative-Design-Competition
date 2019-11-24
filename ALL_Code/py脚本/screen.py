import os
import time
while 1:
  t_n = time.time()
  os.system("python 1.py")
  t_l = time.time()
  t = t_l - t_n
  print(t)

    
