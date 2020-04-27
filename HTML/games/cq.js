const x1=new Array(1,3,5,7),x2=new Array(2,3,6,7),x3=new Array(4,5,6,7);
function gzcs(){
    alert("请想一个0~7的数\n按确定继续");
    var atf="";
    for(var i=1;i<=4;i++){
        atf+=x1[i];
        atf+=" ";
    }
    var x;
    if(confirm(atf+"\n这些数里有你想的数吗？？\n")){
        x+=1;
    }
    atf="";
    for(var i=1;i<=4;i++){
        atf+=x2[i];
        atf+=" ";
    }
    if(confirm(atf+"这些数里有你想的数吗？？\n")){
        x+=2;
    }
    atf="";
    for(var i=1;i<=4;i++){
        atf+=x3[i];
        atf+=" ";
    }
    if(confirm(atf+"这些数里有你想的数吗？？\n")){
        x+=4;
    }
    alert("你想的数是"+x);
}