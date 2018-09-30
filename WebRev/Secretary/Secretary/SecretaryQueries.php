<!DOCTYPE html>
<html>
	<head>
		<title> SecretaryQueries 7761</title>
		<meta charset="UTF-8">	
		
		<meta name = "viewport" content = "width = device-width, initial-scale=1.0">
		<link rel = "stylesheet" type = "text/css" href = "SecretaryQueries.css" />
		<script type = "text/javascript" src = "SecretaryQueries.js"></script>
	</head>


	<body bgcolor = "#FEDEAD">
		<?php 
			$answer = $_POST['option'];  
			$servername = "localhost";
			$username = "root";
			$password = "";
			$dbname = "secretary";
		?>
		<div id = "header" class = "row">
			<div class = "col-3">&nbsp </div>
			<div class = "col-7">
				<img src = "eceDept.jpg"></img>
			</div>
			<div class = "col-2">&nbsp </div>
		</div>

		<div class="row">
  			<div class="col-2"> &nbsp </div>
  			<div class = "col-8" id = "upatras">
  				<p>ΠΑΝΕΠΙΣΤΗΜΙΟ ΠΑΤΡΩΝ <br>ΠΟΛΥΤΕΧΝΙΚΗ ΣΧΟΛΗ<br>ΤΜΗΜΑ ΗΛΕΚΤΡΟΛΟΓΩΝ ΜΗΧΑΝΙΚΩΝ ΚΑΙ ΤΕΧΝΟΛΟΓΙΑΣ ΥΠΟΛΟΓΙΣΤΩΝ</p>
  			</div>
  			<div class="col-2"> &nbsp </div>
		</div>
		<div id = "noOptionDiv">
			<div class = "row">
				<div class="col-3"> &nbsp </div>
				<div class = "col-6" id = "options"><p>ΚΑΡΤΕΛΑ ΑΠΟΤΕΛΕΣΜΑΤΩΝ</p>
				</div>
				<div class="col-3"> &nbsp </div>
			</div>
			<div class = "row">
				<div class="col-4"> &nbsp </div>
				<div class = "col-5">

					<table id = "table1" cellpadding = "5%">
	 					
	  					<?php 
	  						if ($answer == "total") { ?>
								<tr>
									<th class="tg-yw4l" colspan="3"><b>ΠΙΝΑΚΑΣ ΑΙΤΗΘΕΝΤΩΝ ΠΙΣΤΟΠΟΙΗΤΙΚΩΝ</b></th>
								</tr>
								<tr>
									<td class="tg-yw4l">Αύξων Αριθμός</td>
									<td class="tg-yw4l">Είδος Πιστοποιητικού</td>
									<td class="tg-yw4l">Πλήθος Πιστοποιητικών</td>
								</tr>
								
								
						<?php
   								$conn = new mysqli($servername, $username, $password, $dbname);
								//$conn =mysql_connect($servername,$username, $password);
								//mysql_select_db($dbname,$conn);
   								mysqli_set_charset($conn,"utf8");
								
								// Check connection
								if ($conn->connect_error) {
    								die("Connection failed: " . $conn->connect_error);
								} 
								$sql = "SELECT certificate.CertificateID,certificate.CertificateName,COUNT(application.ApplictionId) AS CNT FROM certificate,application WHERE certificate.CertificateID = application.ApplictionId GROUP BY certificate.CertificateName ORDER BY certificate.CertificateID";
								$result = $conn->query($sql);
								if ($result->num_rows > 0) {
    								// output data of each row
   		 							while($row = $result->fetch_assoc()) {
   		 				?>
     	  								<tr>
	  										<td><?php echo $row['CertificateID']?></td>
	  										<td><?php echo $row['CertificateName']?></td>
	  										<td><?php echo $row['CNT']?></td>
	  									</tr>
	  								<?php	
    								}
								}
							}								
							else if($answer == "eforia" )
							{
									?>
								<tr>
									<th class="tg-yw4l" colspan="4"><b>ΠΙΝΑΚΑΣ ΑΙΤΗΣΕΩΝ ΦΟΙΤΗΤΩΝ ΓΙΑ ΤΗΝ ΕΦΟΡΙΑ</b></th>
								</tr>
								<tr>
									<td class="tg-yw4l">Αριθμός Μητρώου</td>
									<td class="tg-yw4l">Επώνυμο</td>
									<td class="tg-yw4l">Όνομα</td>
									<td class="tg-yw4l"> Έτος Εγγραφής</td>
								</tr>
							<?php 
								$conn = new mysqli($servername, $username, $password, $dbname);
								mysqli_set_charset($conn,"utf8");
								// Check connection
								if ($conn->connect_error) {
									die("Connection failed: " . $conn->connect_error);
								} 
								$sql = "SELECT students.* FROM students,application WHERE students.StudentsId = application.StudentId AND application.ApplictionId = 4";
								$result = $conn->query($sql);
								if ($result->num_rows > 0) {
									// output data of each row
									while($row = $result->fetch_assoc()) {
							?>
     	  							<tr>
	  									<td><?php echo $row['StudentsId']?></td>
	  									<td><?php echo $row['LastName']?></td>
										<td><?php echo $row['FirstName']?></td>
										<td><?php echo $row['FirstYear']?></td>
	  								</tr>
	  					<?php	
									}
								}
							}
							else if($answer == "orkomwsia" )
							{
						?>
								<tr>
									<th class="tg-yw4l" colspan="4"><b>ΠΙΝΑΚΑΣ 5ετών ΦΟΙΤΗΤΩΝ ΓΙΑ ΟΡΚΩΜΟΣΙΑ</b></th>
								</tr>
								<tr>
									<td class="tg-yw4l">Αριθμός Μητρώου</td>
									<td class="tg-yw4l">Επώνυμο</td>
									<td class="tg-yw4l">Όνομα</td>
									<td class="tg-yw4l">Έτος Εγγραφής</td>
								</tr>
							<?php 
								$conn = new mysqli($servername, $username, $password, $dbname);
								mysqli_set_charset($conn,"utf8");
								//mysql_set_charset('utf8', $conn);
								// Check connection
								if ($conn->connect_error) {
									die("Connection failed: " . $conn->connect_error);
								} 
								$sql = "SELECT students.* From students WHERE students.FirstYear <= 2011";
								$result = $conn->query($sql);
								if ($result->num_rows > 0) {
									// output data of each row
									while($row = $result->fetch_assoc()) {
							?>
     	  							<tr>
	  									<td><?php echo $row['StudentsId']?></td>
	  									<td><?php echo $row['LastName']?></td>
										<td><?php echo $row['FirstName']?></td>
										<td><?php echo $row['FirstYear']?></td>
	  								</tr>
	  					<?php	
									}
								}
							}
							else {
    							echo "0 results";
							}   							
							
							
	  					?>
					</table>
				</div>
					<div class="col-3"> &nbsp </div>
			</div>
			<div class = "row">
				<div class = "col-4"> &nbsp </div>
				<div class = "col-5"> 
					
							 
								<?php
								if($answer == "orkomwsia" )
								{
									$conn = new mysqli($servername, $username, $password, $dbname);
									mysqli_set_charset($conn,"utf8");
									//mysql_set_charset('utf8', $conn);
									// Check connection
									if ($conn->connect_error) {
										die("Connection failed: " . $conn->connect_error);
									} 
									$sql = "SELECT COUNT( students.StudentsId ) / (SELECT COUNT( students.StudentsId ) FROM students ) *100 AS pososto FROM students WHERE students.FirstYear <=2011";
									$result = $conn->query($sql);
									if ($result->num_rows > 0) {
										// output data of each row
										while($row = $result->fetch_assoc()) {
										?>
										<table id = "pososto">
											<tr>
											<td> Το ποσοστό των φοιτητών που αποφοιτούν: <?php echo $row['pososto'] ?> % </td>
											</tr>
										</table>
										<?php
	  				
										}
								}
							}
							?>
							
					





				</div>
				<div class = "col-3"> &nbsp </div>			
			</div>
			<div class = "row">
				<div class = "col-5"> &nbsp </div>
				<div class = "col-4"> <input type = "button" onclick = "back()" value = "Επιστροφή στην προηγούμενη σελίδα"> </div>		
				<div class = "col-3"> &nbsp </div>
				
			</div>
		</div>
	</body>
</html>