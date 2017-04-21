# Script to write video frames to files then run OCR on them.

videoFile="VDO_0032.avi"
mkdir stills

ffmpeg -i ${videoFile} -f image2 stills/image-%03d.jpg
stills=($(find stills/ -name 'image-*.jpg'))
for f in ${stills[@]}; do
    tesseract $f stdout >> out.txt
done
