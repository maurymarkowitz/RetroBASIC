#!/bin/sh
#!/bin/bash
srcDir=src
if which cppcheck >/dev/null; then
cppcheck -j 4 --enable=all --inline-suppr $srcDir 2>cppcheck.txt 1>/dev/null
pwd=$(pwd)
sed "s|\[|${pwd}/|" cppcheck.txt | sed 's|\]: |: warning: |'
rm cppcheck.txt
else
echo "warning: cppcheck not installed, install here: http://brewformulas.org/Cppcheck"
fi

