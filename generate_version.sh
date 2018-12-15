#!/bin/bash

DESCRIBE=`git describe --tags`
MAJOR=`git describe --tags | tr -s '.' | tr '.' '-' | awk -F '-' '{print $1}'`
MINOR=`git describe --tags | tr -s '.' | tr '.' '-' | awk -F '-' '{print $2}'`
PATCH=`git describe --tags | tr -s '.' | tr '.' '-' | awk -F '-' '{print $3}'`
COMMIT=$(git rev-parse --short HEAD)

echo $DESCRIBE

rm src/version.h 2> /dev/null

echo "#define MAJOR ( "$MAJOR" )"     >> config/version.h
echo "#define MINOR ( "$MINOR" )"     >> config/version.h
echo "#define PATCH ( "$PATCH" )"     >> config/version.h
echo "#define COMMIT ( 0x"$COMMIT" )" >> config/version.h

var="$MAJOR.$MINOR.$PATCH"

echo "Package: wikictl" > wikictl/DEBIAN/control
echo "Version: $var" >> wikictl/DEBIAN/control
echo "Section: custom" >> wikictl/DEBIAN/control
echo "Priority: optional" >> wikictl/DEBIAN/control
echo "Architecture: all" >> wikictl/DEBIAN/control
echo "Essential: no" >> wikictl/DEBIAN/control
echo "Installed-Size: 1024" >> wikictl/DEBIAN/control
echo "Maintainer: therickys93@gmail.com" >> wikictl/DEBIAN/control
echo "Description: Command Line Application for https://github.com/therickys93/wikicontroller.git" >> wikictl/DEBIAN/control
