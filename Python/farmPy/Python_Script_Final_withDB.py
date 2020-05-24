
import string
import serial
import numpy
import matplotlib.pyplot as plt
from drawnow import *

#!/usr/bin/python

import MySQLdb

# Open database connection
db = MySQLdb.connect(
    host = 'localhost',
    user = 'root',
    passwd = '',
    db='testdb'
        )

# prepare a cursor object using cursor() method
cursor = db.cursor()


tempC = [0]
humidity = [0]
moisture = [0]
count = 0

plt.ion()

arduinoData = serial.Serial('COM4', 9600)

def makeFig():
    plt.ylim(0, 60)
    plt.title('Sensor Data')
    plt.ylabel('Temperature in Degrees C')
    plt.plot( tempC, 'ro-', label = 'Temperature')
    plt.legend( loc = 'upper left')

    plt2 = plt.twinx()
    plt.ylim( 0,100)
    plt2.plot( moisture, 'bs-', label = 'Soil Moisture %')
    plt2.set_ylabel('Percentage')
    plt2.plot( humidity, 'gD-', label = 'Humidity %')
    plt2.legend( loc = 'upper right')
     
while True:
    #arduinoData.write('N')
    while (arduinoData.inWaiting() == 0):
        pass
    data = arduinoData.readline()
    dataArray = data.split(',')
    #print dataArray[0]
    #print dataArray[1]
    #print dataArray[2]
    temp = float( dataArray[0])
    humid = float(dataArray[1])
    moist = float(dataArray[2])

    
    # Prepare SQL query to INSERT a record into the database.
    sql = "INSERT INTO ALLVALUES(TEMP, \
       HUMIDITY, SOIL) \
       VALUES ( '%d','%d', '%d' )" % \
       (temp, humid, moist)
    try:
       # Execute the SQL command
       cursor.execute(sql)
       # Commit your changes in the database
       db.commit()
    except:
       # Rollback in case there is any error
       db.rollback()
    tempC.append(temp)
    humidity.append(humid)
    moisture.append(moist)
    drawnow(makeFig)
    plt.pause(0.000001)
    count = count + 1
    if(count >= 30):
        tempC.pop(0)
        humidity.pop(0)
        moisture.pop(0)
    
