#clone the repository
git clone -b windows https://github.com/NextThingCo/sunxi-tools.git

mkdir windows && pushd windows

#grab the static 32 bit mingw compiled version of the library
curl http://pkg.mxe.cc/repos/tar/mxe-i686-w64-mingw32.static/mxe-i686-w64-mingw32.static-libusb1_1.0.19.tar.xz | tar xvJ

#modify the pkg-config file for libusb so it points here
find -name '*.pc' | while read pc; do sed -e "s@^prefix=.*@prefix=$PWD@" -i "$pc"; done

export PKG_CONFIG_PATH=$PWD/usr/i686-w64-mingw32.static/lib/pkgconfig

popd
make fel

