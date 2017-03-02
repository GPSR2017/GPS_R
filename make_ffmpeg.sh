WORKING_DIR=`pwd`

mkdir $WORKING_DIR/ffmpeg_sources

cd $WORKING_DIR/ffmpeg_sources
wget http://www.tortall.net/projects/yasm/releases/yasm-1.3.0.tar.gz
tar xzvf yasm-1.3.0.tar.gz
cd yasm-1.3.0
./configure --prefix="$WORKING_DIR/ffmpeg_build" --bindir="$WORKING_DIR/bin"
make -j 8
make install -j 8 

cd $WORKING_DIR/ffmpeg_sources
wget http://ffmpeg.org/releases/ffmpeg-snapshot.tar.bz2
tar xjvf ffmpeg-snapshot.tar.bz2
cd ffmpeg
PATH="$WORKING_DIR/bin:$PATH" PKG_CONFIG_PATH="$WORKING_DIR/ffmpeg_build/lib/pkgconfig" ./configure \
  --prefix="$WORKING_DIR/ffmpeg_build" \
  --pkg-config-flags="--static" \
  --extra-cflags="-I$WORKING_DIR/ffmpeg_build/include" \
  --extra-ldflags="-L$WORKING_DIR/ffmpeg_build/lib" \
  --bindir="$WORKING_DIR/bin"
PATH="$WORKING_DIR/bin:$PATH" make -j 8
make install -j 8
hash -r
