var count=1;
			
			 function SomeDeleteRowFunction() {
     
				 var current = window.event.srcElement;
				while ( (current = current.parentElement)  && current.tagName !="TR");
					current.parentElement.removeChild(current);
				return false;
    }
			function getSelectedText(elementId) {
				var elt = document.getElementById(elementId);

				if (elt.selectedIndex == -1)
					return null;

				return elt.options[elt.selectedIndex].text;
			}
			function validateForm()
			{
			var a=document.forms["form1"]["fname"].value;
			var b=document.forms["form1"]["lname"].value;
			var c=document.forms["form1"]["code"].value;
			
			var str = "";
			var error=0;
			
			if (a==null || a==""){str +="Name must be filled out\n";error=1;}
			if (b==null || b==""){str +="Last Name must be filled out\n";error=1;}
			if (c==null || c==""){str +="Code must be filled out\n";error=1;}
			if(c!=null && c!="" && isNaN(c)){str+="Code must be a number\n";error=1;}
			if(c!=null && c!="" && !isNaN(c) && c.length!=8){str+="Code must be 8 numbers\n";error=1;}
			
			if(error==1){
				alert(str);
				return false;
			}
			else{
				document.getElementById('board').style.visibility = "visible";
				var table = document.getElementById("mytable");
				
				var row = table.insertRow(table.rows.length );
				
				var cell1 = row.insertCell(0);
				var cell2 = row.insertCell(1);
				var cell3 = row.insertCell(2);
				var cell4 = row.insertCell(3);
				var cell5 = row.insertCell(4);
				var cell6 = row.insertCell(5);
				var cell7 = row.insertCell(6);
				var cell8 = row.insertCell(7);
				cell1.innerHTML = count.toString();
				cell2.innerHTML =a;
				cell3.innerHTML = b;
				cell4.innerHTML = getSelectedText('sect');
				cell5.innerHTML =c;
				cell6.innerHTML =getSelectedText('sect2');
				cell7.innerHTML = getSelectedText('sect3');
				cell8.innerHTML = "<button onclick='SomeDeleteRowFunction()'>delete</button>";
				
				count++;
				return false;
			}
			
			}