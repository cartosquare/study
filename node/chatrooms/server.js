// The built-in "http" module provides HTTP server and client functionality
var http = require('http');

// The built-in "fs" module provides filesystem-related functionality
var fs = require('fs');

// The built-in "path" module provides filesystem path-related functionality
var path = require('path');

// The add-on "mime" module provides the ability to derive a MIME type based on a filename extension
var mime = require('mime');

// The cache object is where the cotents of cached files are stored
var cache = {};

// Sending error response
function send404(response) {
	response.writeHead(404, {'Content-Type': 'text/plain'});
	response.write('Error 404: resource not found.');
	response.end();
}

// Sending file data
function sendFile(response, filePath, fileContents) {
	response.writeHead(
		200,
		{'Content-Type': mime.lookup(path.basename(filePath))}
		);
	response.end(fileContents);
}

// Serving static files
function serveStatic(response, cache, absPath) {
	// Check if file is cached in memory
	if (cache[absPath]) {
		// Serve file from memory
		sendFile(response, absPath, cache[absPath]);
	} else {
		// Check if file exits
		fs.exists(absPath, function(exists) {
			if (exists) {
				// Read data from disk
				fs.readFile(absPath, function(err, data) {
					if (err) {
						send404(response);
					} else {
						cache[absPath] = data;
						sendFile(response, absPath, data);
					}

				});
			} else {
				// Send HTTP 404 response
				send404(response);
			}
		});
	}
}


var server = http.createServer(function(request, response) {
	var filePath = false;

	if (request.url == '/') {
		// Determine HTML file to be served by default
		filePath = 'public/index.html';
	} else {
		// Translate URL path to relative file path
		filePath = 'public' + request.url;
	}

	// Get ablsolute file path
	var absPath = './' + filePath;

	// Serve the static file
	serveStatic(response, cache, absPath);
})

server.listen(3000, function() {
	console.log('Server listening on port 3000.');
});






