var UsersData;
var NowUsers;
var xmlhttp = new XMLHttpRequest();
xmlhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
        UsersData = this.responseText;
    }
};
xmlhttp.open("GET", "Users.json", true);
xmlhttp.send();
function signin(UsersName,keywords){
  for(x in UsersData.Users){
    if(UsersData.Users[x].UsersName!=UsersName){
      continue;
    }
    if(UsersData.Users[x].keywords!=keywords){
      alert("密码错误");
      return false;
    }
    alert("登录成功");
    NowUsers=UsersData.Users[x].UsersName;
    window.location.href="gamecenter.html";
    return true;
  }
  alert("用户名错误");
  return flase;
}
function zc(){
    try{
        var x=document.forms["zc"]["users"].value;
        var y=document.forms["zc"]["pass"].value;
        var z=JSON.parse(UsersData);
        z.n=z.n+1;
        z.Users[z.n]=new Object();
        z.Users[z.n].UsersName=x;
        z.Users[z.n].keywords=y;
        xmlhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
                this.responseText=JSON.stringify(z);
            }
        }
        xmlhttp.open("GET", "Users.json", true);
        xmlhttp.send();
        window.location.href="gamecenter.html";
    }
    catch(err){
        alert(err.message);
    }
  
}