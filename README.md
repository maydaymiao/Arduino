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
####Preparation####
Download Adafruit MQTT library from: https://github.com/adafruit/Adafruit_MQTT_Library/archive/master.zip. In the Arduino IDE, click Sketch>Include Library>Add .ZIP Library. Navigate to the ZIP file or folder containing the new library and click on it.
