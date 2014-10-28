var fs =require('fs');

function callback(err, data) {
	var new_lines = data.toString().split('\n').length - 1;
	console.log(new_lines);
}

fs.readFile(process.argv[2], callback);
