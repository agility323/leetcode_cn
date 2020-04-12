#!/bin/sh

CPP_STD=c++2a

function build_cpp()
{
	CPP_FILE=`ls *.cpp | head -1`
	if [ -f "$CPP_FILE" ]
	then
		echo "found cpp: $CPP_FILE"
		EXE_FILE=`echo $CPP_FILE | sed 's/.cpp//g'`
		echo "executing cmd: g++ -std=$CPP_STD $CPP_FILE -o $EXE_FILE"
		g++ -std=$CPP_STD $CPP_FILE -o $EXE_FILE
		return 1
	fi
	return 0
}

build_cpp
RET=$?
if [ $RET -eq 0 ]
then
	echo "cpp file not found, looking for dir with specified question number: $1"
	QNO=$1
	DIRS=`find . -name ${QNO}\.* -type d`
	CWD=`pwd`
	for DIR in $DIRS
	do
		cd $DIR
		build_cpp
		cd $CWD
	done
fi

