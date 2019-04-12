PKG_CONFIG_PATH=/usr/local/opt/qt5/lib/pkgconfig:/usr/local/opt/libxml2/lib/pkgconfig \
../configure --prefix=$(pwd)/../install
time make -j16 install