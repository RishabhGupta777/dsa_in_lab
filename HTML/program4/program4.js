
let i=1;
document.write('For Loop');
for(i=1;i<=5;i++){
    document.write('<li class="for_loop">Hello,The current index using for is:'+i+'</li>');
}
document.write("<br>");
document.write("<br>");
document.write('While Loop');
while(i<=10){
    document.write('<li style="list-style-type:none">&#9670;&nbsp&nbsp Hello,The current index using for is:'+2*i+'</li>');
    i++;
}
document.write("<br>");
document.write("<br>");
document.write('Do While Loop');
do{
    document.write('<li style="list-style-type:square">Hello,The current index using for is:'+5*i+'</li>');
    i++;
}while(i<=15);  

