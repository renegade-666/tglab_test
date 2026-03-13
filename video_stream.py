import os
os.system('rpicam-vid -t 0 -n --codec libav --libav-format mpegts -o - | '
          'gst-launch-1.0 fdsrc fd=0 ! tsdemux ! decodebin ! videoconvert ! x264enc tune=zerolatency bitrate=500 speed-preset=superfast ! rtph264pay ! udpsink host=127.0.0.1 port=5000 &')          
os.system('gst-launch-1.0 udpsrc address=127.0.0.1 port=5000 ! application/x-rtp, encoding-name=H264, payload=96 ! queue ! rtph264depay ! decodebin ! autovideosink')
