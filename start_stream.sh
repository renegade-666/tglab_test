#apt-get install gstreamer1.0-tools
#apt-get install libgstrtspserver-1.0-dev gstreamer1.0-rtsp
gcc -o test-launch test-launch.c `pkg-config --cflags --libs gstreamer-rtsp-server-1.0`
rpicam-vid -t 0 -n --codec libav --libav-format mpegts -o - | ./test-launch "( fdsrc fd=0 ! tsdemux ! decodebin ! videoconvert ! x264enc tune=zerolatency bitrate=500 speed-preset=superfast ! rtph264pay name=pay0 pt=96 )"