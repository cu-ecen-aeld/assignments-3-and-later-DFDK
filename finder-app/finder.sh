#!/bin/sh

filesdir=$1
searchstr=$2

if [ "$#" -ne 2 ]; then
	echo "Two parameters should be given!"
	exit 1
else 
	if [ ! -d "${filesdir}" ]; then
		echo "${filesdir} is not a directory!"
		exit 1
	fi

x=0
y=0
while IFS= read -r file; do
	# increment number of files
	x=$((x + 1))
	
	lines=$(grep -c "${searchstr}" "${file}")
	
	# increment number of lines found
	y=$((y + lines))
	
done <<EOF
$(find "${filesdir}" -type f)
EOF

	echo "The number of files are $x and the number of matching lines are $y."
	exit 0
fi