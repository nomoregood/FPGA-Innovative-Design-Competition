import socket
import struct
import urllib3
import os
from PIL import Image
from io import BytesIO
import numpy as np

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

s.bind(('192.168.1.108',9999))
buffer = 65536*4
flag = 1
while flag:
    #receive
    #data,addr = s.recvfrom(1024)
    pack_len = s.recv(16)
    print(pack_len)
    if pack_len:
        flag = 0
        data_len = struct.unpack('Q',pack_len)[0]
        print(data_len)
        
        content = b''
        while data_len > 0:
            print(data_len)
            if data_len >= buffer:
                content_temp = s.recv(buffer)
                content += content_temp
                data_len -= buffer
            else:
                content_temp = s.recv(data_len)
                content += content_temp
                data_len = 0
                break

print(type(content))                
bytes_stream = BytesIO(content)                
img1 = Image.open(bytes_stream)           
img = np.array(img1)        
    #print('receive from %s:%s.' % addr)
