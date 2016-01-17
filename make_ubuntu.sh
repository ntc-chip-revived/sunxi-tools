CROSS_COMPILE=
LIBS=
PREBUILT=$(pwd)/windows/usr/$CROSS_COMPILE"static"
DIST=$(pwd)/dist/usr/$CROSS_COMPILE"static"

#Set up pkgconfig directories and static
mkdir -p $PREBUILT/lib/pkgconfig
mkdir -p $DIST/lib/pkgconfig
cp libsunxi.pc $DIST/lib/pkgconfig/.

mkdir -p dist/usr/$CROSS_COMPILE"static/include"
cp include/libsunxi.h dist/usr/$CROSS_COMPILE"static/include/."

pushd $PREBUILT
find -name '*.pc' | while read pc; do sed -e "s@^prefix=.*@prefix=$PWD@" -i "$pc"; done
popd

pushd $DIST
find -name '*.pc' | while read pc; do sed -e "s@^prefix=.*@prefix=$PWD@" -i "$pc"; done
popd



#libusb
export PKG_CONFIG_PATH=$PREBUILT/lib/pkgconfig

#add in fel
export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:$DIST/lib/pkgconfig


CROSS_COMPILE=$CROSS_COMPILE LIBS=$LIBS make fel-libsunxi
