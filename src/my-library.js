mergeInto(LibraryManager.library, {
	speak: function (textPtr) {
		if ('speechSynthesis' in window) {
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
		}
	},
	vibrate: function (duration) {
		if ('vibrate' in navigator) {
			navigator.vibrate(duration);
		}
	},
});