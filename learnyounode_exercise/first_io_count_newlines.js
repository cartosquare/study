var fs = require('fs');

//console.log(process.argv[2]);
var buffer = fs.readFileSync(process.argv[2]);
var str = buffer.toString();
//console.log(str);
var sub_strs = str.split('\n');
//console.log(sub_strs);
console.log(sub_strs.length - 1);