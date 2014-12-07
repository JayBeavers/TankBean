TankBean
=======

A repository for the TankBean sumo prototype from RobotsConf 2014

Based on the LightBlue Bean, Zumo chassis, the ZumoMotors library.

The Zumo chassis is unmodified.  Pins 7,8,9, and 10 are jumpered over to pins D0, D1, D2, and D3 on the LightBlue Bean.
An Arduino UNO needs to be on the chassis to provide regulated +5V power, the Zumo shield has no onboard power regulator.
The UNO should be programmed with a 'null' sketch, empty setup() and loop().

We fiddled with using a level shifter between the Zumo shield (5V) and the LightBlue Bean (3V).  Turns out we didn't seem
to need it.

Bugs
====

The ZumoMotors library needed to be modified to disable custom PWM as this turned out to be incompatible with the LightBlue Bean.

The Zumo was unable to drive directly backwards.  It could power one motor at a time, but was unable to drive both
motors backwards at the same time.
