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

# Prepare SQL query to INSERT a record into the database.
sql = "SELECT * FROM allvalues \
       WHERE temp >= '%d'" % (20)
try:
   # Execute the SQL command
   cursor.execute(sql)
   # Fetch all the rows in a list of lists.
   results = cursor.fetchall()
   for row in results:
      fname = row[0]
      lname = row[1]
      age = row[2]
      sex = row[3]
      
      # Now print fetched result
      print "Count=%d,Temp=%d,Humidity=%d,Moisture=%d" % \
             (fname, lname, age, sex)
except:
   print "Error: unable to fetch data"

# disconnect from server
db.close()
