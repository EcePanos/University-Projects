<?php
if (isset($_POST['idStudent']))
{
	$idStudent=$_POST['idStudent'];	
}


$con = mysqli_connect('localhost', 'root', 'password', 'student');

if (!$con) 
{
    die('Could not connect: ' . mysqli_error($con));
}
mysqli_set_charset($con, 'utf8');
$sql = "SELECT * FROM student WHERE idstudent ='$idStudent '";

$result = $con->query($sql);

if($result->num_rows != 0)
{
	while($row = $result->fetch_assoc()) {
		$data[] = $row['idstudent'];
        $data[] = $row['surname'];
        $data[] = $row['name'];
        $data[] = $row['semester'];
        $data[] = $row['sector'];
        $data[] = $row['entryyear'];
	}	
}

//mysql_close ($con); // Connection Closed.
echo json_encode($data);

?>