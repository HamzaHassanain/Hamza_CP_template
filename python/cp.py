import os
from sys import stdin, stdout

local_checker = "local.hamza"


class IO(object):

    def __init__(self):
        global local_checker
        super(IO, self).__init__()

        self.is_local = os.path.isfile(local_checker)

        if self.is_local:
            self.write_stream = open("output.txt", 'w')
            self.read_stream = open("input.txt", 'r')

    def read(self):
        if self.is_local:
            return self.read_stream.readline()
        else:
            return stdin.readline()

    def write(self, *messages):
        if self.is_local:
            for message in messages:
                self.write_stream.write(str(message))
        else:
            for message in messages:
                stdout.write(str(message))

    def __del__(self):
        if self.is_local:
            self.write_stream.close()
            self.read_stream.close()


io = IO()

tc = int(io.read())

for t in range(tc):

    n = io.read()
    arr = list(map(int, io.read().split()))

    arr.sort()

    cnt = 0
    cur_sub = 0
    for i in arr:
        if i > cur_sub:
            cnt += 1
            cur_sub += i-cur_sub

    io.write(cnt, "\n")
