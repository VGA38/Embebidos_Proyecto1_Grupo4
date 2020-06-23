import paramiko
import os
import time


#os.system('gst-launch-1.0 udpsrc port=5000 ! application/x-rtp,encoding-name=JPEG,payload=26 ! rtpjpegdepay ! jpegdec ! autovideosink')

#os.system('python ver.py')

host = "192.168.1.9"

port = 22

username = "root"

password = "1234"


command = "killall Detect | gst-launch-1.0 v4l2src device=/dev/video0 ! videoconvert ! jpegenc ! rtpjpegpay ! udpsink host=192.168.1.4 port=5000"

ssh = paramiko.SSHClient()

ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())

ssh.connect(host, port, username, password)


stdin, stdout, stderr = ssh.exec_command(command)

lines = stdout.readlines()

print(lines)
