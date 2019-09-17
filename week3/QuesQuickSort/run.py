#!/usr/bin/python

import os

os.system("pwd")
os.system("make clean")
os.system("cmake .. && make")
os.system("./QuesQuickSort")
