## Weather-Wall-Frame

![20161213_113325](https://cloud.githubusercontent.com/assets/4143545/21150623/a426813c-c12d-11e6-85b5-b26e7f49f47a.jpg)

Weather Wall Frame is designed to convey concise information about weather outside the user’s residence. It consists of two modules which work with each other in order to create a glanceable display and convey information about the climate that is specific to his residence.



## Step 1: DataGetter
![img_9752](https://cloud.githubusercontent.com/assets/4143545/21150600/97e559de-c12d-11e6-8a44-eb03e1b65b76.JPG)

## Description:

The DataGetter module is placed just outside the house within the range of an internet WIFI connection to sense data such as humidity, temperature, light intensity, heat index and dew point using sensors. This information is then uploaded into a cloud to be used by the display module.

## Components:
- DHT22
- light sensor
- Photon
- Jumper Wires
- Bread Board
- 4.7k Ohm Register
- 10k Ohm register

## Circuit:
Refer the image above for circuit board connections.

## File:
WeatherDataGetter.ino
- Compile and flash the above file using web IDE called https://build.particle.io or flash the WeatherDataGetter.bin on the photon



## Step 2: Display
- ![fullsizerender 3](https://cloud.githubusercontent.com/assets/4143545/21150576/7fd2c87c-c12d-11e6-90fa-2622bb0ab06e.jpg)

## Description:

The Display module is a wall Frame programmed to access the weather data on the cloud and display it on the wall frame. It gives subtle hints about the climate outside so that the user might take necessary precautions while going outdoors.

## Components:
- LED's (Green-1, Blue-1, RED-1, White-1, Yellow-2)
- Servo Motor
- Photon
- Jumper Wires
- Bread Board

## Circuit:
Refer the image above for circuit board connections.

## File:
- WeatherAmbientDisplay.ino

Compile and flash the above file using web IDE called 
- https://build.particle.io

or flash the WeatherAmbientDisplay.bin on the photon

## Files Required

The above INO files contain the codes for the photons which need to be compiled before flashing, whereas the BIN files are the per-compiled and could be directly flashed on the photons.


## youtube link: 
- https://youtu.be/Ra9XClivUCs

## Link to instructables: 
- http://www.instructables.com/id/Weather-Wall-Frame/
