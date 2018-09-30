<?php

if(isset($_POST['am']))
{
	$am = $_POST['am'];
}

if(isset($_POST['grade']))
{
	$grade = $_POST['grade'];
}

if(isset($_POST['cour']))
{
	$cour = $_POST['cour'];
}

$con = mysqli_connect('localhost','root','','ecedept');

if (!$con) 
{
    die('Could not connect: ' . mysqli_error($con));
}
mysqli_select_db($con,"ecedept");

$sql = 'SELECT * FROM grades WHERE Courses_id = "' . $cour . '" AND Students_id = "' . $am . '"';

$result = $con->query($sql);

if($result->num_rows != 0)
{
	$sql = 'UPDATE grades SET Grades = ' . $grade . ' WHERE Courses_id = "' . $cour . '" AND Students_id = "' . $am . '"';
	mysqli_query($con,$sql);
}
else
{
	$sql = 'INSERT INTO grades VALUES ("'.$cour.'","'.$am .'",'.$grade.')';
	mysqli_query($con,$sql);
}
mysqli_close($con);

?>