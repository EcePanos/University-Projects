<html>
	<head>
		<title> Applications 7761 </title>
		<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="stylesheet" type="text/css" href="styleapp.css" />
	</head>
	
	<body>
	<?php 
	$firstname=$_GET['firstname']; 
	$lastname=$_GET['lastname'];
	$fname=$_GET['fathername']; 
	$am=$_GET['am'];
	$year=$_GET['year']; 
	$address=$_GET['adress'];
	$thl=$_GET['phone']; 
	$mail=$_GET['email'];
	$date=$_GET['date']; 
	$doc=$_GET['forma'];
	?>
	<div id=image><img src="logo.png"></div>
	<div id=over1>
	<b>ΠΑΝΕΠΙΣΤΗΜΙΟ ΠΑΤΡΩΝ - ΠΟΛΥΤΕΧΝΙΚΗ ΣΧΟΛΗ</b>
	</div>
	<div id=over2>
	ΤΜΗΜΑ ΗΛΕΚΤΡΟΛΟΓΩΝ ΜΗΧΑΝΙΚΩΝ &amp ΤΕΧΝΟΛΟΓΙΑΣ ΥΠΟΛΟΓΙΣΤΩΝ
	</div>
	<div id=hr>
	<hr color=brown>
	</div>
	<div id=head>
	<b>ΠΙΣΤΟΠΟΙΗΤΙΚΟ ΣΠΟΥΔΩΝ</b>
	</div>
	<div id=date>
	Πάτρα, <?php echo $date; ?>
	</div>
	<div id=text>
	Βεβαιούται ότι ο φοιτητής με τα στοιχεία <b><?php echo $lastname; ?> <?php echo $firstname; ?>,</b> όνομα πατρός <br>
	<b><?php echo $fname; ?></b> και αριθμό μητρώου <b><?php echo $am; ?></b> ενεγράφη κατά το ακαδημαϊκό έτος <?php echo $newstring = substr($date, -4)-$year; ?>  στο <b>1ο</b> <br>
	έτος σπουδών του τμήματος <b> ΗΛΕΚΤΡΟΛΟΓΩΝ ΜΗΧΑΝΙΚΩΝ &amp ΤΕΧΝΟΛΟΓΙΑΣ ΥΠΟΛΟΓΙΣΤΩΝ. </b> <br>
	Ο προαναφερόμενος φοιτητής σήμερα είναι εγγεγραμμένος στο <b><?php echo $year; ?></b>ο έτος σπουδών και <br>
	αναμένεται να περατώσει τις σπουδές του το έτος <?php echo $news = substr($date, -4)+5-$year; ?> <br><br>
	Το συγκεκριμένο πιστοποιητικό εκδίδεται για <?php 
		switch($doc)
		{
			case "1":
				echo " την στρατολογια";
				break;
			case  "2":
				echo " για το ΤΣΜΕΔΕ";
				break;
			case "3":
				echo " Επικυρωμένη Φωτοτυπία Καρτέλας";
				break;
			case  "4":
				echo " για την Εφορία";
				break;	
			case "5":
				echo " για την φοιτητική Εστία(Στέγαση)";
				break;
			case  "6":
				echo " για Ξένες Αρχές";
				break;	
			case  "7":
				echo " Απλή Φωτοτυπία Καρτέλας";
				break;
		}
	?>
	</div>
	<div id=foot>
	<b>Ο ΠΡΟΕΔΡΟΣ ΤΟΥ ΤΜΗΜΑΤΟΣ</b>
	<div id=foot2><b> Ο ΓΡΑΜΜΑΤΕΑΣ ΤΟΥ ΤΜΗΜΑΤΟΣ</b></div>
	</div>
	</body>
</html>