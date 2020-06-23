import paramiko
import os

host = "192.168.1.9"

port = 22

username = "root"

password = "1234"


command = "killall gst-launch-1.0 | ./Detect"


ssh = paramiko.SSHClient()

ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())

ssh.connect(host, port, username, password)


stdin, stdout, stderr = ssh.exec_command(command)

lines = stdout.readlines()

print(lines)

#os.system('killall gst-launch-1.0')
