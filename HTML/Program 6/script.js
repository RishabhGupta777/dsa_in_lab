let btn1 = document.querySelector("#btn1");
btn1.onclick = ()=>{
    console.log("btn1 was clicked");
    let a = 25;
    a++;
    console.log(a);
}

let div = document.querySelector("div");

//eventlistner ke through hum same event pe multiple kaam karwa sakte h ,
// so , event ke liye hum hamesha event listner ka hi use karenge

    div.addEventListener("mouseover",()=> {
        console.log("you are inside div")
    }) ;
    div.addEventListener("click",()=> {
        console.log("div ko kyu click kiya?")
    }) ;



    
let modeBtn=document.querySelector("#mode");
let body= document.querySelector("body");
let currentMode = "black";

modeBtn,addEventListener("click",()=>{
    if(currentMode==="light"){
        currentMode="dark";
        body.classList.add("dark");
        body.classList.remove("light");
    }  else {
        currentMode="light";
        body.classList.add("light");
        body.classList.remove("dark");
    }
});