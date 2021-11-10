#!/bin/sh

FLAGS="-std=c++2a -Iinclude/"

function build_one()
{
	exe=`echo $file | sed 's/.cpp//g'`
	g++ $FLAGS $file -o $exe
}

function build_many()
{
	for file in $files; do
		build_one
	done
}

arg=$1
cd `dirname $0`
if [ "$arg" = "" ]; then
	echo "begin to build latest modified ...."
	files=`ls -t src/*.cpp | head -1`
	echo "the file is: $files"
	build_many
elif [ "$arg" = "all" -o "$arg" = "xxx" ]; then
	echo "begin to build all ...."
	files=`find src/ -name "*\.cpp"`
	build_many
else
	files=`find src/ -name "${arg}*\.cpp"`
	echo "begin to build files: $files"
	build_many
fi

