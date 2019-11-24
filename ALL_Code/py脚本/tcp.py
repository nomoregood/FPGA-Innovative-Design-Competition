import win32gui
import socket
import struct
from pymouse import *
from pykeyboard import *


m = PyMouse()
k = PyKeyboard()

def file_deal(file_name):
    # 定义函数用于处理用户索要下载的文件
    try:
        # 二进制方式读取
        print(file_name.decode())
        files = open(file_name.decode(), 'rb')
        mes = files.read()
        print(type(mes))
    except:


        print("没有该文件")

    else:

        files.close()

        return mes

def main():
    # 创建套接字
    tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # 固定端口号
    tcp_socket.bind(("",5555))
    # 将主动套接字转为被动套接字
    tcp_socket.listen(128)

    while True:
        # 利用accept获取分套接字以及客户端的地址
        client_socket,client_addr = tcp_socket.accept()
        # 接收客户端的数据
        ##
        pack_data = client_socket.recv(4)
        if pack_data:
            data = struct.unpack('i',pack_data)[0]
            print(data)
            if data:
                if data == 51:
                    k.tap_key(k.up_key)
                if data == 54:
                    k.tap_key(k.down_key)
                if data == 52:
                    k.tap_key(k.left_key)
                if data == 65:
                    k.tap_key(k.right_key)
                    
                if data == 50:
                    k.tap_key(k.space_key)
                if data == 56:
                    k.tap_key(k.function_keys[3])
                if data == 49:
                    k.press_key(k.shift_key)
                    k.tap_key(k.enter_key)
                    k.release(k.shift_key)
        ##22264444222666666664444222244444444444


        
        file_name = client_socket.recv(4096)
        # 调用函数处理用户下载的文件
        mes = file_deal(file_name)

        if mes:
            # 如果文件不为空发送

            client_socket.send(mes)
        #关闭分套接字

        client_socket.close()



if __name__ == "__main__":
    main()
