var fs = require('fs');
var path = require('path');

var dir_name = process.argv[2];
//console.log(dir_name);

var filter = process.argv[3];
//console.log(filter);

fs.readdir(dir_name, function(err, list) {
	for (var i = 0; i < list.length; ++i) {
//		console.log(list[i]);
//		console.log(path.extname(list[i]));

		if (path.extname(list[i]) === ('.' + filter))
			console.log(list[i]);
	}
})

/*
	var fs = require('fs')
    var path = require('path')
    
    fs.readdir(process.argv[2], function (err, list) {
      list.forEach(function (file) {
        if (path.extname(file) === '.' + process.argv[3])
          console.log(file)
      })
    })
*/