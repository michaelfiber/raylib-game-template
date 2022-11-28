mergeInto(LibraryManager.library, {
	speak: function (textPtr) {
		const synth = window.speechSynthesis;

		let text = UTF8ToString(textPtr);
		console.log("SPEAK: " + text);
		const utterThis = new SpeechSynthesisUtterance(text);

		utterThis.onend = function (event) {
			console.log("SpeechSynthesisUtterance.onend");
		};

		utterThis.onerror = function (event) {
			console.error("SpeechSynthesisUtterance.onerror");
		};

		synth.speak(utterThis);
	},
	vibrate: function (duration) {
		console.log("Attempt to vibrate for " + duration + " milliseconds.");
		if ('vibrate' in navigator) {
			navigator.vibrate(duration);
		}
	},
});