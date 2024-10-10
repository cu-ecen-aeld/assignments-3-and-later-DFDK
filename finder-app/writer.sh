#!/bin/sh

writefile=$1
writestr=$2

if [ ! $# -eq 2 ]; then
	echo "Two parameters should be given!"
	exit 1
else 
	if [ -f "${writefile}" ]; then
		# overwrite any existing file
		echo ${writestr} > ${writefile}
	else
		# create the path and the new file with content writestr
		directory=$(dirname "${writefile}")
		if ! mkdir -p "${directory}"; then
			echo "Error: Could not create directory ${directory}"
			exit 1
		fi
		echo ${writestr} > ${writefile}
	fi
fi