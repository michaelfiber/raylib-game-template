mergeInto(LibraryManager.library, {
	Say: function (textPtr) {
		if ('speechSynthesis' in window) {
			if (window.speechSynthesis.speaking) return;
			let text = UTF8ToString(textPtr);
			const utterThis = new SpeechSynthesisUtterance(text);
			window.speechSynthesis.speak(utterThis);
		}
	},
	Vibrate: function (...durations) {
		if ('vibrate' in navigator) {
			navigator.vibrate(durations);
		}
	},
});