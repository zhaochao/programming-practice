#!/usr/bin/env python
#Very short script that reuses example_1_4.py
from example_1_4 import diskspace_func
import subprocess

def tmp_space():
    tmp_usage = "du"
    tmp_arg = "-h"
    tmp_path = "/tmp"
    print "Space used in /tmp directory"
    subprocess.call([tmp_usage, tmp_arg, tmp_path])

def main():
    diskspace_func()
    tmp_space()

if __name__ == "__main__":
    main()
