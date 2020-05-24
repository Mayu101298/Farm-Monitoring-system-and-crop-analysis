<?php 
$conn_Error = 'Could Not Connect.';
$mysql_Host = 'localhost';
$mysql_User = 'root';
$mysql_Pass = NULL;
$mysql_Db = 'testdb';
	
if(!mysql_connect($mysql_Host,$mysql_User,$mysql_Pass) || !mysql_select_db($mysql_Db))
die($conn_Error);
else
echo 'Connection Successful';
?>

<?php
	$url1=$_SERVER['REQUEST_URI'];
	header("Refresh: 600; URL=$url1");
?>
	
<?php
	$myQuery = "SELECT * FROM ALLVALUES";
	echo "<table border=10>";
	echo "<TR><TH>COUNT</TH><TH>TEMP</TH><TH>HUMIDITY</TH><TH>MOISTURE</TH></TR>";
		if($query = mysql_query($myQuery)){
			if(mysql_num_rows($query) == NULL)
				echo "Nothing found";
			else{
				while($query_row = mysql_fetch_assoc($query)){
					$cnt = $query_row['count'];
					$tmp = $query_row['temp'];
					$hum = $query_row['humidity'];
					$moi = $query_row['soil'];
					echo "<tr><td>$cnt</td><td>$tmp</td><td>$hum</td><td>$moi</td></tr>";
				}
			}
		}
		else
			echo mysql_error();	
?>