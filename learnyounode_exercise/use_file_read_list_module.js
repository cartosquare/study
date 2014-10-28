var mymodule = require('./file_read_list_module')

mymodule(process.argv[2], process.argv[3], function(err, list) {
	if (err) {
		console.log(err);
	} else {
		//console.log(message);
		list.forEach(function (file) {
         	console.log(file)
 		})
	}
});