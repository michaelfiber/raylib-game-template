const cacheName = "cache_name_1698440034";

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