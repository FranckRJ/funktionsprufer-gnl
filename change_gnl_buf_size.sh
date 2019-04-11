#!/bin/bash

function change_gnl_name
{
	sed -i "" "s/get_next_line(/get_next_line_$num(/g" $file
	sed -i "" "s/get_next_line_[0-9]*(/get_next_line_$num(/g" $file
}

function change_buf_size
{
	sed -i "" "s/define BUFF_SIZE [0-9]*/define BUFF_SIZE $num/" $file
}

num="$1"
file="get_next_line.c"
change_gnl_name
file="get_next_line.h"
change_gnl_name
file="get_next_line.h"
change_buf_size
