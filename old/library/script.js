function goto(goal) {
	var sites = document.getElementsByClassName("content");
	var home_button = document.getElementById("home-button");
	var home_content = document.getElementById("home-content");
	for (var i = sites.length - 1; i >= 0; i--) {
		if(sites[i].classList.contains(goal)){
			sites[i].classList.add("active");
		}else{
			sites[i].classList.remove("active");
		}
		if(goal != "home"){
			if(!home_button.classList.contains("visible")){
				home_button.classList.add("visible");
				home_content.classList.remove("visible");
			}
		}else{
			home_button.classList.remove("visible");
			home_content.classList.add("visible");
		}
	}
}
window.onscroll = function(event) {
	// console.log(window.pageYOffset);
	if(window.pageYOffset <= 30){
		document.getElementById("header").style.height = 80-window.pageYOffset + "px";
		document.getElementById("top_text").style.fontSize = 40-window.pageYOffset/3 + "px";
		document.getElementById("top_text").style.lineHeight = 80-window.pageYOffset + "px";
		document.getElementById("home-button").style.top = 50-window.pageYOffset + "px";
		document.getElementById("mail-button").style.top = 50-window.pageYOffset + "px";
		document.getElementById("header").style.boxShadow = "0px 0px 0px #FFF";
	}
	if(window.pageYOffset == 31){
		document.getElementById("header").style.boxShadow = "0px 2px 5px 0px rgba(0, 0, 0, 0.05)";
	}
	if(window.pageYOffset == 34){
		document.getElementById("header").style.boxShadow = "0px 2px 5px 0px rgba(0, 0, 0, 0.15)";
	}
	if(window.pageYOffset >= 36){
		document.getElementById("header").style.boxShadow = "0px 2px 5px 0px rgba(0, 0, 0, 0.25)";
	}
}

function changeColors() {
	var letters = '0123456789ABCDEF'.split('');
    var color = '#';
    for (var i = 0; i < 6; i++ ) {
        color += letters[Math.floor(Math.random() * 16)];
    }
	document.getElementById("header").style.background = color;
	h1 = document.getElementsByTagName("h1");
	for (var i = h1.length - 1; i >= 0; i--) {
		h1[i].style.color = color;
	};
	a = document.getElementsByTagName("a");
	for (var i = a.length - 1; i >= 0; i--) {
		a[i].style.color = color;
	};
	setTimeout(function() { changeColors(); }, 10000);
}

function removeAds() {
	script = document.getElementsByTagName("script");
	for (var i = script.length - 1; i >= 0; i--) {
		// console.log(script[i]);
		// console.log(script[i].src);
		if (script[i].src.indexOf("ad") > -1){
			script[i].parentElement.removeChild(script[i]);
		};
	};
}