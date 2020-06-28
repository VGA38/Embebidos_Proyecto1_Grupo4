import paramiko 
ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect(hostname='192.168.1.9',username='root',password='1234',port=22)
sftp_client=ssh.open_sftp()

sftp_client.get('/home/root/Intrusiones.txt','Intrusiones.txt')

sftp_client.close()
ssh.close()
