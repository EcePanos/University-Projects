function changed()
{
    var studentID = document.getElementById('idstudent').value;
    
    $.ajax({
        type: "POST", url: 'student.php', data: {idStudent: studentID}, dataType: "json",
        success: function(data)
        {
           	document.getElementById('surname').innerHTML = data[1];
           	document.getElementById('name').innerHTML = data[2];
           	document.getElementById('semester').innerHTML = data[3];
           	document.getElementById('sector').innerHTML = data[4];
           	document.getElementById('entry').innerHTML = data[5];
        }
    });
}