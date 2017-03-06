cmake -D OpenCV_DIR=../opencv_build .
make
./DisplayImage test_image.png
rm -rf CMakeFiles
rm -f CMakeCache.txt
rm -f cmake_install.cmake
rm -f Makefile
rm -f DisplayImage
