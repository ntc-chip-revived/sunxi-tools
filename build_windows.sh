#libusb
export PKG_CONFIG_PATH=/home/howie/dev/cross/sunxi-tools/windows/usr/i686-w64-mingw32.static/lib/pkgconfig

#add in fel
export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/home/howie/dev/cross/sunxi-tools/dist/usr/i686-w64-mingw32-static/lib/pkgconfig

echo libusb
echo `pkg-config --libs libusb-1.0`

echo
echo sunxi
echo `pkg-config --libs libsunxi`
echo
CROSS_COMPILE=i686-w64-mingw32- LIBS=-lws2_32 make fel-libsunxi
