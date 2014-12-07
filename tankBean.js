var SerialPort = require("serialport").SerialPort

var serialPort = new SerialPort("/tmp/tty.LightBlue-Bean", {
  baudrate: 115200
});

serialPort.on('open', function(error) {
	console.log('opened!');
});

serialPort.on('data', function(error, data ) {
	console.log(data);
});

serialPort.on('error', function(error, data ) {
  console.log(data);
});

var stdin = process.stdin;
stdin.setRawMode( true );
stdin.resume();
stdin.setEncoding( 'utf8' );

stdin.on( 'data', function( key ){

  if ( key === '\u0003' ) {
    process.exit();
  }

  process.stdout.write( key );

  serialPort.write(key, function(err, results) {

  	if (err) {
	    console.log('err ' + err);
	}

  });

});

var XboxController = require('xbox-controller');
var xbox = new XboxController('Microsoft Xbox Wired Gamepad');

xbox.on('left:move', function(position){
  console.log('left:move', position);
});

xbox.on('right:move', function(position){
  console.log('right:move', position);
});
