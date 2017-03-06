mkdir opencv_build
cd opencv_build
wget https://github.com/opencv/opencv/archive/3.2.0.zip
unzip 3.2.0.zip
cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=./ opencv-3.2.0/
make -j10


