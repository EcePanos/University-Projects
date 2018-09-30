<!DOCTYPE html>
<html>
	<head>
		<title> SecretaryQueries 7761</title>
		<meta charset="utf-8">		
		<meta name = "viewport" content = "width = device-width, initial-scale=1.0">
		<link rel = "stylesheet" type = "text/css" href = "SecretaryQueries.css" />
		<script type = "text/javascript" src = "SecretaryQueries.js"></script>
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
	</head>

	<body bgcolor = "#FEDEAD">
	<?php 
			//$answer = $_POST['option'];  
			$servername = "localhost";
			$username = "root";
			$password = "";
			$dbname = "ecedept";
		?>
		<div id = "header" class = "row">
			<div class = "col-2">&nbsp</div>
			<div class = "col-8">
				<img src = "eceDept.jpg"></img>
			</div>
			<div class = "col-2">&nbsp</div>
		</div>

		<div class="row">
  			<div class="col-1"> &nbsp</div>
  			<div class = "col-10" id = "upatras">
  				<p>ΠΑΝΕΠΙΣΤΗΜΙΟ ΠΑΤΡΩΝ <br>ΠΟΛΥΤΕΧΝΙΚΗ ΣΧΟΛΗ<br>ΤΜΗΜΑ ΗΛΕΚΤΡΟΛΟΓΩΝ ΜΗΧΑΝΙΚΩΝ ΚΑΙ ΤΕΧΝΟΛΟΓΙΑΣ ΥΠΟΛΟΓΙΣΤΩΝ</p>
  			</div>
  			<div class="col-1"> &nbsp</div>
		</div>
		<div id = "noOptionDiv">
		<div class = "row">
			<div class="col-1"> &nbsp</div>
			<div class = "col-4" id = "options"><p>ΕΠΙΛΟΓΕΣ ΕΚΔΟΣΗΣ ΠΙΣΤΟΠΟΙΗΤΙΚΩΝ</p></div>
			<div class="col-1"> &nbsp</div>
			<div class = "col-5" id = "options"><p>ΕΙΣΑΓΩΓΗ ΒΑΘΜΟΛΟΓΙΑΣ</p></div>
			<div class="col-3"> &nbsp</div>
			
			<div class="col-5"> &nbsp</div>
		</div>
		<div class = "row">
			<div class="col-12"> &nbsp</div>
		</div>
		<div class = "row">
			<div class = "col-2"> &nbsp</div>
			<div class = "col-4">
				<form action = "SecretaryQueries.php" method = "POST" onsubmit = "return submitCustom()">
				<table id = "optionsTable" cellpadding = "6%">
	  			<tr> 
	   			 	<td>Συνολική Κατάσταση Αιτήσεων</td>
	    			<td><input type="radio" name="option" value="total" id = "totalRadio"></td>
	  			</tr>
				<tr>
					<td>Κατάσταση αιτήσεων για Εφορία</td>
				  	<td><input type="radio" name="option" value="eforia" id = "eforiaRadio"></td>
				</tr>
				<tr>
				    <td>Κατάσταση Φοιτητών Ορκωμοσίας</td>
				    <td><input type="radio" name="option" value="orkomwsia" id = "orkwmosiaRadio"></td>
				</tr>
				<tr>
				    <td>Για την εφορία</td>
				    <td><input type="radio" name="option" value="eforiaFor" id = "eforiaForRadio"></td>
				</tr>
				<tr>
				    <td>Για τη φοιτιτική εστία (στέγαση)</td>
				    <td><input type="radio" name="option" value="estia" id = "estiaRadio"></td>
				</tr>
				<tr>
				    <td>Για Ξένες Αρχές</td>
				    <td><input type="radio" name="option" value="xenesArxes" id = "xenesArxesRadio"></td>
				</tr>
				<tr>
				    <td>Απλή φωτοτυπία καρτέλας</td>
				    <td><input type="radio" name="option" value="kartela" id = "kartelaRadio"></td>
				</tr>
				</table>
				
			</div>
			
			<div class = "col-2" id = "borders"><p>Μαθήματα Ά Εξαμήνου</p></div>
			<div class="col-1"> &nbsp</div>
			<div class = "col-2" id = "borders"><p>Μαθήματα Β Εξαμήνου</p></div>
			<div class="col-1"> &nbsp</div>
			
			<div class = "row">
				<div class = "col-2" ><select id = "prwto"><option disabled selected value = "selectPrwto"> Select an Option </option>
					<?php 
						$conn = new mysqli($servername, $username, $password, $dbname);
								//$conn = mysql_connect($servername,$username, $password)
   								mysqli_set_charset($conn, 'utf8');
								///mysql_select_db($dbname,$conn);
								
								// Check connection
								if ($conn->connect_error) {
    								die("Connection failed: " . $conn->connect_error);
								} 
								$sql = "SELECT Courses_id FROM  `courses` WHERE Semester LIKE  '1ο'";
								$result = $conn->query($sql);
								if ($result->num_rows > 0) {
    								// output data of each row
   		 							while($row = $result->fetch_assoc()) {
					?>
					
						<option><?php echo $row['Courses_id'] ?> </option>
						
					<?php 			}
								}
					?>
					</select>
					<br>
					<p id ="am"> Αριθμός Μητρώου: <br>
						<select id = "am1"><option disabled selected value = "selectDeutero"> Select an Option </option>
					<?php 
						$conn = new mysqli($servername, $username, $password, $dbname);
								//$conn = mysql_connect($servername,$username, $password)
   								mysqli_set_charset($conn, 'utf8');
								///mysql_select_db($dbname,$conn);
								
								// Check connection
								if ($conn->connect_error) {
    								die("Connection failed: " . $conn->connect_error);
								} 
								$sql = "SELECT Students_id FROM students";
								$result = $conn->query($sql);
								if ($result->num_rows > 0) {
    								// output data of each row
   		 							while($row = $result->fetch_assoc()) {
					?>
					
						<option><?php echo $row['Students_id'] ?> </option>
						
					<?php 			}
								}
					?>
						</select>
					</p>
					</div>
				<div class="col-1"> &nbsp</div>
				<div class = "col-2"><select id = "deutero"><option disabled selected value = "selectDeutero"> Select an Option </option>
				<?php 
						$conn = new mysqli($servername, $username, $password, $dbname);
								//$conn = mysql_connect($servername,$username, $password)
   								mysqli_set_charset($conn, 'utf8');
								///mysql_select_db($dbname,$conn);
								
								// Check connection
								if ($conn->connect_error) {
    								die("Connection failed: " . $conn->connect_error);
								} 
								$sql = "SELECT Courses_id FROM  `courses` WHERE Semester LIKE  '2ο'";
								$result = $conn->query($sql);
								if ($result->num_rows > 0) {
    								// output data of each row
   		 							while($row = $result->fetch_assoc()) {
					?>
					
						<option><?php echo $row['Courses_id'] ?> </option>
						
					<?php 			}
								}
					?>
				</select>
				<br>
				<p id = "amnew"> Βαθμός: <br>
					<select id = "grade1"><option disabled selected value = "selectDeutero"> Select an Option </option>
						<option>0</option>
						<option>1</option>
						<option>2</option>
						<option>3</option>
						<option>4</option>
						<option>5</option>
						<option>6</option>
						<option>7</option>
						<option>8</option>
						<option>9</option>
						<option>10</option>
						
					</select>
				</p>
				</div>
				<div class="col-1"> &nbsp</div>
			</div>
		</div>
		
		<div class = "row">
			<div class="col-12"> &nbsp</div>
		</div>
		<div class = "row">
			<div class = "col-2"> &nbsp</div>
			<div class = "col-1"> <input type="submit" value="Υποβολή Επιλογής" ></div>
			<div class = "col-1	"> &nbsp</div>
			<div class = "col-1"> <input type="button" value="Ακύρωση" onclick = "cancel()"></div>
			<div class = "col-1"> &nbsp</div>
			<div class = "col-1" id = "submitDiv"> <input id = "submit1" type="button" value="Εύρεση Φοιτητών" onclick = "submit2()" ></div>
			<div class = "col-1"> &nbsp</div>
			<div class = "col-1"> <input type="button" value="Ακύρωση" onclick = "cancel()"></div>
		</div>
		</form>
	</div>
	</body>
</html>