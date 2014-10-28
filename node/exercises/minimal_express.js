var express = require('express');
var app = express();

app.get('/', function(req, res) {
  res.end('Hello');
});

app.listen(3000);
