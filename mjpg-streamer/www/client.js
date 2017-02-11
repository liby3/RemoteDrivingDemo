var net = require('net');


 var client = net.connect({path: '192.168.1.106}, function() {

var client = net.connect({port: 8000}, function() {
    console.log('connect');
    client.write('hello');
});


client.on('data', function(data) {
    console.log(data.toString());
    client.end();
});


client.on('end', function() {
    console.log('exit');
});