#!/usr/bin/python

import MySQLdb

# Open database connection
#db = MySQLdb.connect("127.0.0.1","adminUser","0209","adminuser" )

db = MySQLdb.connect(
    host = 'localhost',
    user = 'root',
    passwd = '',
    db='testdb'
        )
# prepare a cursor object using cursor() method
cursor = db.cursor()

# execute SQL query using execute() method.
cursor.execute("SELECT VERSION()")

# Fetch a single row using fetchone() method.
data = cursor.fetchone()

print "Database version : %s " % data

# disconnect from server
db.close()
