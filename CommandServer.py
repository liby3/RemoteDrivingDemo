#!/usr/bin/env python
#coding=utf-8
import web
import serial

urls = (
    '/', 'index'
)
app = web.application(urls, globals())

class index:
    def GET(self):
    	print 'get request'
    def POST(self):
    	i = web.input()
    	command = i.get('command')
    	ser = serial.Serial('/dev/ttyACM0', 9600) # start serial to arduino
        if command == 'left':          
            ser.write("L") # write data
        elif command == 'right':
            ser.write("R") # write data
        elif command == 'ahead':
            ser.write("A") # write data
        elif command == 'back':
            ser.write("B") # write data
        elif command == 'stop':
            ser.write("S") # write data 
        ser.close() # close serial 
    	print 'Command:',command

if __name__ == "__main__":
    app.run()