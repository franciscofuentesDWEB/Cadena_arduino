#!/usr/bin/python
# -*- coding: utf-8 -*-
import MySQLdb

host   = "localhost"
user   = "root"
passwd = "1234"
db     = "Cadena"

######################### CONEXiÓN A LA BASE DE DATOS ##########################
db = MySQLdb.connect(host, user, passwd, db)
cursor = db.cursor()
db.commit()

###########LIMPIAMOS BASE DE DATOS ############################
query4 = "DELETE FROM Datos;"
cursor.execute(query4)
print query4

###########DEJAMOS DESDE CERO LA PK #####################
query2 = "ALTER TABLE Datos AUTO_INCREMENT = 0;"
cursor.execute(query2)

#########################ALMACENAR DATOS ######################################
archivo = open("datos.txt",'r')
i = 0
for linea in archivo.readlines():
	#print(i)	
	if(i>=0):
		archivo=linea.split('\t')
		archivo=linea.split(';')
		archivo[1]=archivo[1].rstrip('\n')
		query = "insert into Datos(luz,sonido,temperatura) values('%d', '%d','%d')" % (int(archivo[0]),int(archivo[1]),int(archivo[2])) 
		#cursor.execute("SELECT * FROM Laboratorio")
		print(query)
		cursor.execute(query)
		db.commit()
	else:
		i = i+1

####################################################################################################### 
archivo.close()
cursor.close()
db.close()
