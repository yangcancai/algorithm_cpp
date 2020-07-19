#!/bin/bash
git submodule update --init --recursive
sysOS=`uname -s`
if [ ! -d "vcpkg" ]; then
  git clone https://github.com/Microsoft/vcpkg.git
  fi
  cd vcpkg
  ./bootstrap-vcpkg.sh
if [ $sysOS == "Darwin" ];then
    ./vcpkg install gtest:x64-osx

elif [ $sysOS == "Linux" ];then
    ./vcpkg install gtest:x64-linux
fi
cd ..

if [ $sysOs == "Darwin" ];then
      cp -r -f vcpkg/installed/x64-os/lib/* ./lib/Release/
      cp -r -f vcpkg/installed/x64-os/debug/lib/* ./lib/Debug/
  else
     cp -r -f vcpkg/installed/x64-linux/lib/* ./lib/Release/
     cp -r -f vcpkg/installed/x64-linux/debug/lib/* ./lib/Debug/
fi
