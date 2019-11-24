from pynq.overlays.base import BaseOverlay
base = BaseOverlay("base.bit")
base.select_rpi()


%%microblaze base.RPI

#include "xio_switch.h"
#include "circular_buffer.h"
#include "uart.h"

unsigned int get_value() {
    uint8_t data[1];
    uart device = uart_open(14,15);
    uart_read(device, data, 1);
    return data[0];
}

def run(i):

    tcp_socket = socket(AF_INET, SOCK_STREAM)

    tcp_ip = "192.168.1.103"

    tcp_port = 5555

    tcp_socket.connect((tcp_ip, tcp_port))
    
    ##
    pack_data  = struct.pack('i',i)
    print(pack_data)
    tcp_socket.send(pack_data)
    
    ## 
    time.sleep(1)
    file_name = r"screenshot.jpg"
    tcp_socket.send(file_name.encode())
    new_file = open(file_name, "wb")
   
    time1 = 0

    while True:

            mes = tcp_socket.recv(65536)

            if mes:

                new_file.write(mes)


                time1 += len(mes)

            else:

                if time1 == 0:

                    new_file.close()

                    os.remove(file_name)
                    print("no file")
                else:

                    print("ok")

                break

    tcp_socket.close()
	from pynq.overlays.base import BaseOverlay
from pynq.lib.video import *
from pynq import Overlay
import cv2
import os
import time
from socket import *
import struct


hdmi_out = base.video.hdmi_out
Mode = VideoMode(1280,720,24)
hdmi_out.configure(Mode,PIXEL_RGB)

hdmi_out.start()
print("1")
img = cv2.imread('screenshot.jpg')

outframe = hdmi_out.newframe()

print("ok")


while True:
    i = get_value()
    
    if i > 0 :
        print(i)
        run(i)

        if os.access("screenshot.jpg",os.F_OK):
            img = cv2.imread('screenshot.jpg')
            outframe [:]= img
            hdmi_out.writeframe(outframe)
	