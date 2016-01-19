#clone the repository
#git clone -b windows https://github.com/NextThingCo/sunxi-tools.git
#pushd sunxi-tools

mkdir -p lib && pushd lib

#grab the static 32 bit mingw compiled version of the library
curl http://pkg.mxe.cc/repos/tar/mxe-i686-w64-mingw32.static/mxe-i686-w64-mingw32.static-libusb1_1.0.19.tar.xz | tar xvJ

#rename to properly prefixed name
pushd usr
mv i686-w64-mingw32.static i686-w64-mingw32-static

#modify the pkg-config file for libusb so it points here
pushd i686-w64-mingw32-static
find -name '*.pc' | while read pc; do sed -e "s@^prefix=.*@prefix=$PWD@" -i "$pc"; done

export PKG_CONFIG_PATH=$PWD/lib/pkgconfig


popd
popd
popd

