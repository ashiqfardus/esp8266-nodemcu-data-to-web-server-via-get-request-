<?php
$host="localhost";
$user="root";
$password="";
$db_name=""; //database name
$con=mysqli_connect("$host","$user","$password")
or die("Connection not established with server");
$db_select=mysqli_select_db($con,"$db_name")
or die("Database not Selected");
$connection=new mysqli($host,$user,$password,$db_name);
?>
