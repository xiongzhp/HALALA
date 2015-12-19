var express = require('express')
  , http = require('http')
  , path = require('path');
var app = express();
var server = http.createServer(app).listen(3000);
var io = require('socket.io').listen(server);

var SerialPort = require("serialport").SerialPort
var sp = new SerialPort("/dev/tty.usbmodem1421", {
	  baudrate: 38400
	}, false); // this is the openImmediately flag [default is true]

sp.open(function (error) {
  if ( error ) {
    console.log('failed to open: '+error);
  } 
  else {
  // Now server is connected to Arduino
    console.log('Serial Port Opend');  
    io.sockets.on('connection', function (socket) {
      //Connecting to client 
      console.log('Socket connected');
      socket.on('emoji', function(data){
        sp.write(data); 
        console.log('data received: ' + data);
        // sp.on('data', function(data) {
        //   console.log('ec: ' + data);
        // });  
      });
    });  
  }
});

app.set('port', process.env.PORT || 3000);
app.use(express.static(path.join(__dirname, 'public')));
app.get('/', function (req, res) {
  res.send('Hello World!');
});
app.get('/emonitor',function(req,res,next){
  res.sendFile('public/emotion.html',{ root: __dirname });
});


server.listen(app.get('port'), function(){
  console.log("Express server listening on port " + app.get('port'));
});
