var fname;
var lname;
var gender;
var email;
var add;
var city;
function checkIfEmailInString(text) { 
				var re = /(([^<>()[\]\\.,;:\s@\"]+(\.[^<>()[\]\\.,;:\s@\"]+)*)|(\".+\"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))/;
				return re.test(text);
			}
function part1(){
	document.getElementById("new").style.visibility = "visible";
}
function part2()
			{
			var a=document.forms["myForm"]["lname"].value;
			var b=document.forms["myForm"]["fname"].value;
			var c=document.forms["myForm"]["gender"].value;
			var d=document.forms["myForm"]["cemail"].value;
			var e=document.forms["myForm"]["password"].value;
			var f=document.forms["myForm"]["cpassword"].value;
			var h=document.forms["myForm"]["email"].value;
			var i=document.forms["myForm"]["bdate"].value;
			var str = "";
			var error=0;
			if (a==null || a==""){str +="Last Name must be filled out\n";error=1;}
			if (b==null || b==""){str +="First Name must be filled out\n";error=1;}
			if (c==null || c==""){str +="Gender must be filled out\n";error=1;}
			if (d==null || d==""){str +="Confirm email must be filled out\n";error=1;}
			if(d!=null && d!="" && d!==h){str+="Emails must match\n";error=1;}
			if (e==null || e==""){str+="Password must be filled out\n";error=1;}
			if (f==null || f==""){str +="Confirm password must be filled out\n";error=1;}
			if(f!=null && f!="" && f!==e){str+="Passwords must match\n";error=1;}
			if (h==null || h==""){str +="Email must be filled out\n";error=1;}
			if(h!=null && h!="" && !checkIfEmailInString(h)){str +="Email is not valid\n";error=1;}
			if (i==null || i==""){str +="BirthDate must be filled out\n";error=1;}
			if(i!=null && i!="" &&!Date.parse(i)){str +="BirthDate must be valid\n";error=1;}
			if(error==1){
				alert(str);
				return false;
			}
			else{
				fname=b;
				lname=a;
				gender=c;
				email=h;
				document.getElementById("new2").style.visibility = "visible";
				return false;
			}
			}
function part3()
			{
			var a=document.forms["myForm"]["phone"].value;
			var b=document.forms["myForm"]["add1"].value;
			var c=document.forms["myForm"]["city"].value;
			var d=document.forms["myForm"]["country"].value;
			var e=document.forms["myForm"]["mobile"].value;
			var f=document.forms["myForm"]["add2"].value;
			var h=document.forms["myForm"]["zip"].value;
			var str = "";
			var error=0;
			if (a==null || a==""){str +="Phone must be filled out\n";error=1;}
			if (b==null || b==""){str +="Address must be filled out\n";error=1;}
			if (c==null || c==""){str +="City must be filled out\n";error=1;}
			if (d==null || d==""){str +="Country must be filled out\n";error=1;}
			if (e==null || e==""){str+="Mobile be filled out\n";error=1;}
			if (f==null || f==""){str +="Address 2 password must be filled out\n";error=1;}
			if (h==null || h==""){str +="Zip must be filled out\n";error=1;}
			if(error==1){
				alert(str);
				return false;
			}
			else{
				add=b;
				city=c;
				document.getElementById("new3").style.visibility = "visible";
				var table = document.getElementById("mytable");
				var row = table.insertRow(table.rows.length );
				
				var cell1 = row.insertCell(0);
				var cell2 = row.insertCell(1);
				var cell3 = row.insertCell(2);
				var cell4 = row.insertCell(3);
				cell1.innerHTML ="Όνομα:";
				cell2.innerHTML =fname;
				cell3.innerHTML = "Email:";
				cell4.innerHTML =email;
				
				var row = table.insertRow(table.rows.length );
				
				var cell1 = row.insertCell(0);
				var cell2 = row.insertCell(1);
				var cell3 = row.insertCell(2);
				var cell4 = row.insertCell(3);
				cell1.innerHTML ="Επώνυμο:";
				cell2.innerHTML =lname;
				cell3.innerHTML = "Διεύθυνση:";
				cell4.innerHTML =add;
				
				var row = table.insertRow(table.rows.length );
				
				var cell1 = row.insertCell(0);
				var cell2 = row.insertCell(1);
				var cell3 = row.insertCell(2);
				var cell4 = row.insertCell(3);
				cell1.innerHTML ="Φύλο:";
				cell2.innerHTML =gender;
				cell3.innerHTML = "Πόλη:";
				cell4.innerHTML =city;
				return false;
			}
			}