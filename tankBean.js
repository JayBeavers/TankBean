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