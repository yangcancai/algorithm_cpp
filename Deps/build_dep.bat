git submodule update --init --recursive

rem rd /s /q vcpkg

git clone https://github.com/Microsoft/vcpkg.git

cd vcpkg

call .\bootstrap-vcpkg.bat

rem vcpkg install libevent:x64-windows-static

rem vcpkg install protobuf:x64-windows-static

rem vcpkg install lua:x64-windows-static

rem vcpkg install sdl2:x64-windows-static

vcpkg install gtest:x64-windows-static

cd..

xcopy vcpkg\installed\x64-windows-static\lib lib\Release\ /s /e /Y
rem xcopy vcpkg\installed\x64-windows-static\bin ..\_Out\Release\  /s /e /Y
xcopy vcpkg\installed\x64-windows-static\debug\lib lib\Debug\  /s /e /Y
rem xcopy vcpkg\installed\x64-windows-static\debug\bin ..\_Out\Debug\  /s /e /Y
cd..