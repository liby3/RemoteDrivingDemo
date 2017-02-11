# RemoteDrivingDemo
基于mjpg-streamer的远程驾驶简单demo

##1.Introduction
在小车上搭建了两个服务器，一个是使用mjpg­streamer采集摄像头视频，建立的网页服务器，使用了8080端口；另一个是在小车上接收网页返回的post请求，提取post中的内容，并根据内容向底层arduino下达指令；

##2.VideoServer
跑在PI上，基于mjpg-streamer，占用8080端口，客户端则在网页端根据小车摄像头拍摄的视频按方向键控制小车；

##3.CommandServer.py
跑在PI上，基于python的串口通信，使用http协议，占用8000端口，接收到Post请求后，通过串口向底层arduino写指令，arduino接到指令发出高低电平控制小车；

##4.Car.ino
跑在arduino上面，与作为master的PI通过串口通信；连接电路时需要根据实际小车轮子电机的情况连线：保证前进时两个前轮前进，两个后轮作为从动轮；后退时，两个后轮后退，前轮作为从动轮。
