var fs = require('fs')
var path = require('path')
    
function readList(dirname, filter, callback) {


	fs.readdir(dirname, function (err, list) {
		if (err)
			return callback(err);  // early return 

		// ... no error, doing things with list
		var filter_list = [];
    	list.forEach(function (file) {
     		if (path.extname(file) === '.' + filter) {
         		//console.log(file)
         		filter_list.push(file);
     		}

 		})

 		// all went well, call back with 'null' for the error argument
 		callback(null, filter_list);
 })

}

module.exports = readList;