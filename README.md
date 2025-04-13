
# ESP32 TFT Image Viewer Over Serial (No SD Card)

- This project is designed to display any custom image on a TFT display using an ESP32 microcontroller, without the need for an SD card. 
- The workflow begins by converting a JPG or PNG image to BMP format using a basic image editor like MS Paint. 
- A Python script then takes the BMP image and converts it into RGB565 format, which is a color format supported by most TFT displays.
-  Once the image is converted, it is sent to the ESP32 via serial communication using a terminal program like CoolTerm. 
- The ESP32 receives this data and directly renders the image onto the TFT screen. 
- This method offers a simple way to send images from a laptop to a microcontroller for display, making it ideal for quick testing or projects where SD card usage is not preferred.

## COMPONENTS

- TFT_Display ST7789V controller

- Jumper Wires

- bread board

- ESP-32 Microcontroller with 32 pins


## Connections:
connects the pin according

| TFT_Display            | ESP32                                                                |
| ----------------- | ------------------------------------------------------------------ |
  |   VCC | 3.3V |
| GND | GND |
|DIN |   Pin 23 |
|CLK| Pin 18  |
|   CS |  Pin 5|
| DC |  Pin 2|
|RST |Pin 4 |
|BL| 3.3V |
