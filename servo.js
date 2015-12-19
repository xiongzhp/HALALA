var SerialPort = require("serialport").SerialPort
var serialPort = new SerialPort("/dev/cu.usbmodemfa131", {
  baudrate: 115200
}, false); // this is the openImmediately flag [default is true]

serialPort.open(function (error) {
  if ( error ) {
    console.log('failed to open: '+error);
  } else {
    console.log('open');
    serialPort.on('data', function(data) {
      console.log('data received: ' + data);
    });
    // var message = new Buffer("GO 123");
    serialPort.write("30,150");
    // function writeThenDrainThenWait(duration) {
    //   console.log('Calling write...');
    //   serialPort.write(message, function() {
    //     console.log('...Write callback returned...');
    //     // At this point, data may still be buffered and not sent out from the port yet (write function returns asynchrounously).
    //     console.log('...Calling drain...');
    //     serialPort.drain(function() {
    //       // Now data has "left the pipe" (tcdrain[1]/FlushFileBuffers[2] finished blocking).
    //       // [1] http://linux.die.net/man/3/tcdrain
    //       // [2] http://msdn.microsoft.com/en-us/library/windows/desktop/aa364439(v=vs.85).aspx
    //       console.log('...Drain callback returned...');
    //       console.log('...Waiting', duration, 'milliseconds...');
    //       setInterval(writeThenDrainThenWait, duration);
    //     });
    //   });
    // };
    // writeThenDrainThenWait(1000);

  }
});