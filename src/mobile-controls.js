var leftHolder;
var rightHolder;

function buildDpad() {
	var bUp = document.createElement('button');
	bUp.innerText = '^';
	bUp.style.width = "33%";
	bUp.style.left = "33%";
	leftHolder.appendChild(bUp);
}

function init() {
	leftHolder = document.querySelector("#left-control-holder");
	rightHolder = document.querySelector("#right-control-holder");

	buildDpad();
}

window.addEventListener('DOMContentLoaded', () => {
	init();
});

