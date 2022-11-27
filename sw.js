const cacheName = "cache_name_5e087ba6b5af7ca295434b1d607877b30157544d";

self.addEventListener('install', (event) => {
	event.waitUntil(caches.open(cacheName));
});


// Cache all requests. This is why the PWA option should be set to false during dev.
self.addEventListener('fetch', async (event) => {
	let cache = await caches.open(cacheName);
	let response = await cache.match(event.request);

	if (!response) {
		response = await fetch(event.request.url);
		cache.put(event.request, response.clone());
	}

	event.respondWith(response);
});