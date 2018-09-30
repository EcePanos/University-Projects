function submitCustom()
{
	var totalRadio = document.getElementById('totalRadio');
	var eforiaRadio = document.getElementById('eforiaRadio');
	var orkwmosiaRadio = document.getElementById('orkwmosiaRadio');
	var eforiaForRadio = document.getElementById('eforiaForRadio');
	var estiaRadio = document.getElementById('estiaRadio');
	var xenesArxesRadio = document.getElementById('xenesArxesRadio');
	var kartelaRadio = document.getElementById('kartelaRadio');
	
	if ((!totalRadio.checked)
		&& (!eforiaRadio.checked)
		&& (!orkwmosiaRadio.checked)
		&& (!eforiaForRadio.checked)
		&& (!estiaRadio.checked)
		&& (!xenesArxesRadio.checked)
		&& (!kartelaRadio.checked))
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
	var totalRadio = document.getElementById('totalRadio');
	var eforiaRadio = document.getElementById('eforiaRadio');
	var orkwmosiaRadio = document.getElementById('orkwmosiaRadio');
	var eforiaForRadio = document.getElementById('eforiaForRadio');
	var estiaRadio = document.getElementById('estiaRadio');
	var xenesArxesRadio = document.getElementById('xenesArxesRadio');
	var kartelaRadio = document.getElementById('kartelaRadio');

	totalRadio.checked = false;
	eforiaRadio.checked = false;
	orkwmosiaRadio.checked = false;
	eforiaForRadio.checked = false;
	estiaRadio.checked = false;
	xenesArxesRadio.checked = false;
	kartelaRadio.checked = false;
}

function back()
{
	history.go(-1);
}