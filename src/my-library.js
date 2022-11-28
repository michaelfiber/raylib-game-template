mergeInto(LibraryManager.library, {
	vibrate: function (duration) {
		console.log("Attempt to vibrate for " + duration + " milliseconds.");
		if ('vibrate' in navigator) {
			navigator.vibrate(duration);
		}
	},
});