#!/bin/bash

CC="clang++"
NAME="RGB_video"
C_FLAGS="-Wall -Wextra -std=c++11 -O0 -fPIC"
FRAMEWORK_FLAGS="-I/opt/homebrew/Cellar/opencv/4.7.0_2/include/opencv4  -lopencv_core -lopencv_highgui -lopencv_videoio -lopencv_imgproc"
SRC=$(find ../src/ -type f -name "*.cpp")
ARGS=""
for i in {1..10}
do
	if [ -n "${!i}" ]; then
		ARGS+=${!i}
		ARGS+=" "
	fi
done

$CC $C_FLAGS $SRC -o $NAME $FRAMEWORK_FLAGS

EXECUTE="./$NAME $ARGS"
$EXECUTE	
