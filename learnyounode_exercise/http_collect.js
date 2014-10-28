var bl = require('bl');
var http = require('http');

var url = process.argv[2];
http.get(url, function(response) {
	response.setEncoding('utf-8');
	response.pipe(bl(function(err, data) {
		// Deal with error!!!
		if (err)
			return console.error(err);

		var buffer = data.toString();
		console.log(buffer.length);
		console.log(buffer);
	}))
})