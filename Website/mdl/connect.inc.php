<?php 
$conn_Error = 'Could Not Connect.';
$mysql_Host = 'localhost';
$mysql_User = 'root';
$mysql_Pass = NULL;
/*$mysql_User = 'admin_lms';
$mysql_Pass = 'kjsce';*/
$mysql_Db = 'wt_project_lms';

if(!mysql_connect($mysql_Host,$mysql_User,$mysql_Pass) || !mysql_select_db($mysql_Db))
die($conn_Error);
//else
//echo 'Connection Successful';
?>