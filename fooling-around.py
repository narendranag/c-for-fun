import platform

print(platform.machine())

import socket

# the local network interface
HOST = socket.gethostbyname(socket.gethostname())
print(HOST)

# the public network interface
PUBLIC_HOST = socket.gethostbyname_ex(socket.gethostname())
print(PUBLIC_HOST)
