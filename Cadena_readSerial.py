#!/usr/bin/python
# -*- coding: utf-8 -*-
import serial
import time

arduino=serial.Serial('/dev/ttyUSB0',baudrate=9600, timeout = 3.0)
archivo = open('datos.txt',"a")
cadena=''

#######################################################################################
archivo.write(arduino.readline())
print cadena.rstrip('\n')
cadena = ''
print "Lectura exitosa"
arduino.close()
archivo.close()
#################################################################################
