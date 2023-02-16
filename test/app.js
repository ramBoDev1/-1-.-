var loop = 21;
var i;
var j;
for (var i=1; i<=loop; i++){
   for(var j=1; j<=i; j++){
    document.write (" &nbsp;")
   }
   for(var j=1; j<=(loop-i)+1; j++){
        document.write(" *");
        ;
        
   }
   for(var j=loop-i; j>=1; j--){
        document.write(" *");
        
   }
   document.write("<br/>");
}
<!DOCTYPE html>
<html>
<head> 
    <meta charset="utf-8">
    
</head>
<body>
    Name : <input type ="text" id="num">
    <button onclick="myFunction()">Enter</button>

</body>

<script src="app.js"></script>


</html>