#!/bin/bash

./change_gnl_buf_size.sh 1
make "libgnl-1.a"
./change_gnl_buf_size.sh 2
make "libgnl-2.a"
./change_gnl_buf_size.sh 10
make "libgnl-10.a"
./change_gnl_buf_size.sh 32
make "libgnl-32.a"
./change_gnl_buf_size.sh 100
make "libgnl-100.a"
./change_gnl_buf_size.sh 9999
make "libgnl-9999.a"
./change_gnl_buf_size.sh 10000000
make "libgnl-10000000.a"
