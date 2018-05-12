echo Building dependencies...

# compiling libevent
cd libevent
chmod a+x ./configure
./configure CPPFLAGS=-fPIC --disable-shared --disable-openssl
make clean
make

cp -R -f ./.libs/*.a ../../../Product/Lib/Debug/
cp -R -f ./.libs/*.a ../../../Product/Lib/Release/
cd ../

# compile protobuf
cd protobuf
chmod a+x ./configure
#./configure --disable-shared CFLAGS="-fPIC" CXXFLAGS="-fPIC"
./configure CFLAGS="-fPIC" CXXFLAGS="-fPIC"
make clean
make

cp -R -f ./src/.libs/*.a ../../../Product/Lib/Debug/
cp -R -f ./src/.libs/*.a ../../../Product/Lib/Release/


cp -R -f ./src/.libs/libprotobuf.so* ../../../Product/Lib/Debug/
cp -R -f ./src/.libs/libprotobuf.so* ../../../Product/Lib/Release/


# back to main dir
pwd
