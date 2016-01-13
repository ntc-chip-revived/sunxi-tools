#Windows
For convenience, there is an already built fel.exe in the dist folder. It can be downloaded from here:
https://github.com/NextThingCo/sunxi-tools/blob/windows/dist/fel.exe

##Building (Cross compiling)
If you don't have them, you'll need the mingw cross-compiler toolchains:
```sudo apt-get install mingw-w64 mingw-w64-tools
```
I did not put them in the install_windows.sh script

To install the repository and libusb, and build fel:
```
curl https://raw.githubusercontent.com/NextThingCo/sunxi-tools/windows/install_windows.sh | bash
```
If all goes well, in sunxi-tools, there will be a fel.exe produced

##Windows Driver
Temporary solution:
On windows, install appropriate driver from http://zadig.akeo.ie/

1. Plug in CHIP with a FEL jumper
2. Run zadig
3. Choose the libusbK driver (the other ones do not work)

For the final version, we need to produce the driver ourselves. See:
http://libusbk.sourceforge.net/UsbK3/index.html