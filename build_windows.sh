export PKG_CONFIG_PATH=/home/howie/dev/cross/sunxi-tools/windows/usr/i686-w64-mingw32.static/lib/pkgconfig
CROSS_COMPILE=i686-w64-mingw32- LIBS=-lws2_32 make felw
mv felw fel.exe