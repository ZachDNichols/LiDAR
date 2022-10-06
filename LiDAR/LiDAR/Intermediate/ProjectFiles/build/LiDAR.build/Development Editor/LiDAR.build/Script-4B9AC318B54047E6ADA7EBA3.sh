#!/bin/sh
set -e

IFS=$'\n'

if [ $PLATFORM_NAME = iphoneos ] || [ $PLATFORM_NAME = tvos ]; then 
	FRAMEWORK_DIR=$TARGET_BUILD_DIR/$EXECUTABLE_FOLDER_PATH/Frameworks
	for FRAMEWORK in ${FRAMEWORK_DIR}/*.framework; do
		[ -d "${FRAMEWORK}" ] || continue
		echo Codesigning ${FRAMEWORK}
		codesign --force --sign ${EXPANDED_CODE_SIGN_IDENTITY} --generate-entitlement-der --verbose --preserve-metadata=identifier,entitlements,flags --timestamp=none "${FRAMEWORK}"
	done
fi

