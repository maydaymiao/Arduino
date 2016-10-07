欢迎来到我的Github，如果你也对工业4.0或者IoT感兴趣可以通过以下方式联系我：<br>
Welcome to my Github, if you are interested in Industrial 4.0 and IoT as well, please feel free to contact me: <br>
Location: @Shanghai, China<br>
Email: maydaymiao@126.com<br>
Linkedin: https://www.linkedin.com/profile/in/michael-miao-21939749

# Arduino
## **Catalogue**
* [1. ESP8266](#1)
  * [1.1. AT Command](#1.1)
  * [1.2. Adafruit MQTT Simluation](#1.2)
  * [1.3. Adafruit MQTT DHT11](#1.3)
* [2. Apple Homekit](#1)
  * [2.1. Home app and Siri control - LED](#2.1)


##<h2 id="1">1. ESP8266</h2>
####Introduction####
The ESP8266 is a great inexpensive device that gives you WIFI connectivity as well as a couple GPIO ports to connect sensors, has WiFi connectivity, an onboard processor, and is compatible with the Arduino IDE. There are different modules of ESP8266 available like ESP-01, 02, 03, 04... In this tutorial, I will use ESP-01. Here is a list of other module: http://www.esp8266.com/wiki/doku.php?id=esp8266-module-family.
####Parts####
Arduino Uno, USB to TTL adapter, Jumper wire, Breadboard, 330 Ohm resistor
####Preparation####
* Enter http://arduino.esp8266.com/stable/package_esp8266com_index.json into Additional Board Manager URLs field. You can add multiple URLs, separating them with commas.
* Open Boards Manager from Tools > Board menu and install esp8266 platform (and don't forget to select your ESP8266 board from Tools > Board menu after installation).

##<h3 id="1.1">1.1. AT Command</h3>
####Wiring####

![](https://github.com/maydaymiao/Arduino/blob/master/images/esp-01.jpg)
![](https://github.com/maydaymiao/Arduino/blob/master/images/arduino_esp8266_ttl.jpg)

* 【Arduino】3.3V →【ESP8266】VCC
* 【Arduino】3.3V →【ESP8266】CH_PD
* 【Arduino】GND →【ESP8266】GND
* 【Arduino】GND →【USB To TTL】GND
* 【USB To TTL】TXD→【ESP8266】URXD
* 【USB To TTL】RXD→【ESP8266】UTXD

Once you connect these properly, after installing the driver, you will get the port allotment under device manager while the converter is connected to a USB port of PC. There are some serial Terminal software available, I use a tool called Realterm which you can find and download from: http://realterm.sourceforge.net.<br>
After installing the Realterm, go to Port page, Feed in the port number seen under Device manager (mine is port 4) & speed as 115200  (Baud Rate). Then go to send page, select CR and LF in the EOL column. Now type in AT, The module will respond with OK. Here is the list of AT commands: http://www.pridopia.co.uk/pi-doc/ESP8266ATCommandsSet.pdf.

##<h3 id="1.2">1.2. Adafruit MQTT Simluation</h3>
There is a detail tuturial from Adafruit web: https://learn.adafruit.com/mqtt-adafruit-io-and-you?view=all, here I just summarize and highlight some points may casue problems, espically the wiring part you may meet error when you upload the code into the ESP8266 if you didn't not wire properly.

####Preparation####
Download Adafruit MQTT library from: https://github.com/adafruit/Adafruit_MQTT_Library/archive/master.zip. In the Arduino IDE, click Sketch>Include Library>Add .ZIP Library. Navigate to the ZIP file or folder containing the new library and click on it.</h3>
Select Generic ESP8266 Module, upload speed = 115200 and the right COM port.

####Wiring####
* 【Arduino】3.3V →【ESP8266】VCC
* 【Arduino】3.3V →【ESP8266】CH_PD
* 【Arduino】GND →【ESP8266】GND
* 【Arduino】GND →【USB To TTL】GND
* 【USB To TTL】TXD →【ESP8266】URXD
* 【USB To TTL】RXD →【ESP8266】UTXD
* 【USB To TTL】RTS -> 【ESP8266】RST (IMPORTANT)
* 【ESP8266】GPIO0 -> 330Ohm resitior -> GND (IMPORTANT)

####Load up example####
In the Arduino IDE, click File>Example>Adafruit MQTT Library>mqtt_esp8266, set up your WiFi credentials and adafruit.io username & key. NOW you can upload the sketch to your ESP8266. You should be able to see the upload 100% complete in the IDE as below.

![](https://github.com/maydaymiao/Arduino/blob/master/images/ide.png)

####Publication and Subscription test####
**Firstly, make sure you remove the RST and GPIO0 wire from ESP8266 after the sketch upload complete.**<br>
Then open up the serial console as soon as the sketch is done uploading, and click back to your adafruit.io dashboard. You'll see something like this. Click on/off button in your dashboard, you will see the singal going back to your serial console.

![](https://github.com/maydaymiao/Arduino/blob/master/images/adafruit_mqtt_demo.JPG)

![](https://github.com/maydaymiao/Arduino/blob/master/images/esp8266_running_wiring.jpg)

##<h3 id="1.3">1.3. Adafruit MQTT DHT11</h3>
Here a detail tuturial from Adafruit web: https://learn.adafruit.com/home-automation-in-the-cloud-with-the-esp8266-and-adafruit-io?view=all, but there are some bugs on that sketch which you will meet some error message after upload, this is because some recent changes to the Adafruit MQTT library, but that project has not yet been updated. Specifically, support for PROGMEM has been eliminated. So, you can just clone my sketch into your IDE which will work perfectly: https://github.com/maydaymiao/Arduino/blob/master/Adafruit_ESP8266_DHT11.ino.

####Preparation####
You will need to install the following Arduino libraries:<br>
[Adafruit MQTT library](https://github.com/adafruit/Adafruit_MQTT_Library)<br>
[DHT sensor library](https://github.com/adafruit/DHT-sensor-library)

####Wiring####
Similar as the last project, the only difference is to connect GPIO2 on ESP8266 to DHT11 DAT pin.
* 【Arduino】3.3V →【ESP8266】VCC
* 【Arduino】3.3V →【ESP8266】CH_PD
* 【Arduino】GND →【ESP8266】GND
* 【Arduino】GND →【USB To TTL】GND
* 【USB To TTL】TXD →【ESP8266】URXD
* 【USB To TTL】RXD →【ESP8266】UTXD
* 【USB To TTL】RTS -> 【ESP8266】RST (IMPORTANT)
* 【ESP8266】GPIO0 -> 330Ohm resitior -> GND (IMPORTANT)
* 【ESP8266】GPIO2 -> DHT11 DAT -> 1K resistor -> 【DHT】VCC -> 3.3V
* 【DHT】GND -> GND 


####Load up sketch####
Clone my sketch into your Arduino IDE: https://github.com/maydaymiao/Arduino/blob/master/Adafruit_ESP8266_DHT11.ino

####Test####
**Again, make sure you remove the RST and GPIO0 wire from ESP8266 after the sketch upload complete, and you may need to plug out and plug in again of your CH_PD pin from breadboard**<br>
Open your Adafruit IO, you should be able to see the data change. Here is my portal: https://io.adafruit.com/maydaymiao/esp8266. Enjoy~

![](https://github.com/maydaymiao/Arduino/blob/master/images/esp8266_dht11_dashboard.png)

##<h2 id="2">2. Apple Homekit</h2>
####Introduction####
In iOS 9, along with Siri, you could use a number of third-party apps from developers and device makers to control devices. But adding a built-in app and other controls in the latest version of iOS should help make it easier for users.<br>
A new Home app from ios 10 lets you simply and securely set up, manage and control your home all in one place. Accessories can be managed individually or grouped into scenes so they work together with a single command and can be controlled by using Siri. 

##<h3 id="2.1">2.1. Home app and Siri control - LED</h3>
####Overview####
https://www.youtube.com/watch?v=6-IZMlTjPUk. From this video, it should give you the idea that what I have achieved for this experiment. Basically, there are two kinds of control here - home app which is the new feature released under ios 10 and Siri. If you have read the previous tutorials, you should know what is MQTT broker and ESP8266 and these are the critical parts in this experiment. Now let's start. Here are the components involved:<br>

* HAP-NodeJS running on the Ubuntu 16.04
* MQTT Broker running on the Raspberry Pi
* LED connected to an ESP8266 module
* ios 10 and home app

Here is how it works: Tell Siri to turn on/off the light -> Trigger an action on HAP-NodeJS server -> HAP-NodeJS publishes a "light on/off" message to MQTT Broker with a certain topic -> ESP8266 subscribes the message from MQTT Broker with the same topic -> Physically turn on/off the light.

####HAP-NodeJS####
In most of other tutorials, they are all talking about installing HAP-NodeJS on a Raspberry Pi (https://gist.github.com/elvisimprsntr/f23c76587d48be0ec4b9), and this is what I initially tried, however I failed at the step which requires to install libavahi-compat-libdnssd-dev because of some dependency missing, maybe I will try later. But anyway, I install the HAP-NodeJS in Ubuntu finally and it works well. One tip is please do NOT use a virtual machine to install the Ubuntu unless you select the bridge mode of network. Because all the devices must be under same network.<br>

This is a brief guide to installing HAP-NodeJS on an Ubuntu/Debian system. (Copy from: https://github.com/KhaosT/HAP-NodeJS/wiki/Installing)<br>

Install node.js, npm, node-gyp and other things we need:<br>
```linux
sudo apt-get update
sudo apt-get install nodejs npm git-core libnss-mdns libavahi-compat-libdnssd-dev
sudo npm config set registry http://registry.npmjs.org/
sudo npm install -g node-gyp
```

Clone the HAP-NodeJS project:<br>
`git clone https://github.com/KhaosT/HAP-NodeJS.git`

Go into the directory where you cloned it:<br>
`cd HAP-NodeJS`

Rebuild npm:<br>
`npm rebuild`

Try to run the server:<br>
`node Core.js`<br>

It will probably give you errors about missing modules. Install these using `sudo npm install <module name>`, replacing <module name> with the name of the module it is missing. After installing the module it wanted, run npm rebuild and try to run the server again with node Core.js. Repeat installing missing modules until the server launches with no errors. HAP-NodeJS is now all set up.

####MQTT Broker####
Please refer to my Raspberry Pi repository: https://github.com/maydaymiao/Raspberry_Pi

####ESP8266 Arduino sketch####
You can find the source code at: https://github.com/maydaymiao/Arduino/blob/master/Mqtt_LocalRaspberry_Led.ino

