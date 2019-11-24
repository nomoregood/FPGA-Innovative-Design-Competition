import os
from socket import *
import struct


def main():

    tcp_socket = socket(AF_INET, SOCK_STREAM)

    tcp_ip = "192.168.1.103"

    tcp_port = 5555

    tcp_socket.connect((tcp_ip, tcp_port))
    
    ##
    i = 1
    pack_data  = struct.pack('i',i)
    print(pack_data)
    tcp_socket.send(pack_data)
    ##
   
    file_name = r"screenshot.jpg"
    tcp_socket.send(file_name.encode())
    new_file = open(file_name, "wb")

    time = 0

    while True:

            mes = tcp_socket.recv(65536)

            if mes:

                new_file.write(mes)


                time += len(mes)

            else:

                if time == 0:

                    new_file.close()

                    os.remove(file_name)
                    print("no file")
                else:

                    print("ok")

                break

    tcp_socket.close()


if __name__ == '__main__':
    main()
