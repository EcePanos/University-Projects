function submitCustom()
{
	var totalRadio = document.getElementById('totalRadio');
	var eforiaRadio = document.getElementById('eforiaRadio');
	var orkwmosiaRadio = document.getElementById('orkwmosiaRadio');
	var eforiaForRadio = document.getElementById('eforiaForRadio');
	var estiaRadio = document.getElementById('estiaRadio');
	var xenesArxesRadio = document.getElementById('xenesArxesRadio');
	var kartelaRadio = document.getElementById('kartelaRadio');
	var prwto = document.getElementById('prwto');
	var deutero = document.getElementById('deutero');
	var str1 = prwto.options[prwto.selectedIndex].text;
	var str2 = deutero.options[deutero.selectedIndex].text;
	
	if (((!totalRadio.checked)
		&& (!eforiaRadio.checked)
		&& (!orkwmosiaRadio.checked)
		&& (!eforiaForRadio.checked)
		&& (!estiaRadio.checked)
		&& (!xenesArxesRadio.checked)
		&& (!kartelaRadio.checked))
		&& (str1 == "Select an Option")
		&& (str2 == "Select an Option")
		)
		
	{
		alert("Πρέπει να επιλέξετε κάποια από τις επιλογές.");
		return false;
	}
	else
	{
		if(totalRadio.checked)
		{
			document.getElementById('noOptionDiv').style.display = 'none';
		}
	}
}

function cancel()
{
	window.location.reload();
}

function submit2()
{
	var prwto = document.getElementById('prwto');
	var deutero = document.getElementById('deutero');
	var str1 = prwto.options[prwto.selectedIndex].text;
	var str2 = deutero.options[deutero.selectedIndex].text;
	
	if ((str1 == "Select an Option")
		&& (str2 == "Select an Option"))
	{
		alert("Πρέπει να επιλέξετε κάποια από τις επιλογές.");
		return false;
	}
	else if ((str1 != "Select an Option") && (str2 != "Select an Option"))
	{
		alert("Πρέπει να επιλέξετε μία από τις επιλογές.");
		cancel();
		return false;
	}
	else
	{
		document.getElementById('am').style.visibility = "visible";
		document.getElementById('amnew').style.visibility = "visible";
		document.getElementById('submit1').style.visibility = "hidden";
		document.getElementById('submitDiv').innerHTML =  '<input id = "submit1" type="button" value="Υποβολή Βαθμολογίας" onclick = "update()" >'
	}




}

function back()
{
	history.go(-1);
}

function update()
{
	var prwto = document.getElementById('prwto');
	var deutero = document.getElementById('deutero');
	var str1 = prwto.options[prwto.selectedIndex].text;
	var str2 = deutero.options[deutero.selectedIndex].text;
	var course;
	if ((str1 != "Select an Option") && (str2 == "Select an Option"))
	{
		course = (str1);
	}
	else if ((str2 != "Select an Option") && (str1 == "Select an Option"))
	{ 
		course = (str2);
	}

	var am = document.getElementById('am1');
	var amText = am.options[am.selectedIndex].text;
	var grade = document.getElementById('grade1');
	var gradeText = grade.options[grade.selectedIndex].text;
	if(amText == "Select an Option")
	{
		alert("Παρακαλώ επιλέξτε φοιτητή.")
		return false;
	}
	else
	{
		if(gradeText == "Select an Option")
		{
			alert("Παρακαλώ επιλέξτε βαθμό.")
			return false;
		}
		else
		{
			 $.ajax({
		        type: "POST",
		        url: 'update.php',
		        data: {am: amText,
		        		grade: gradeText,
		        		cour: course},
		        		async:false,
		        success: function(data)
		        {
					alert("Succesfully Updated");
		        }
    		}); 
		}
	}
}