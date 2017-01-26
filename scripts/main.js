var myHeading = document.querySelector('h1');
//myHeading.innerHTML = 'Hello world!';

var myImage = document.querySelector('img');

myImage.onclick = function() {
	var mySrc = myImage.getAttribute('src');
	if(mySrc === 'images/tomatoes.jpg'){
		myImage.setAttribute('src', 'images/watermelon.jpg');
	}
	else{
		myImage.setAttribute('src', 'images/tomatoes.jpg');
	}
	
}

var myButton = document.querySelector('button');
var myHeading = document.querySelector('h1');

function setUserName() {
	var myName = prompt('Please enter your name.');
	localStorage.setItem('name', myName);
	myHeading.innerHTML = 'Hello! ' + myName;
	
}

if(!localStorage.getItem('name')) {
  setUserName();
} else {
  var storedName = localStorage.getItem('name');
  myHeading.innerHTML = 'Hello, ' + storedName;
}

myButton.onclick = function(){
	setUserName();
}