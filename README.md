# mingw64 example

## Install

Platform: Ubuntu

```bash
apt install mingw-w64
```

> i686-w64-mingw32-*   are toolchain for 32-bit Windows Application
> 
> x86_64-w64-mingw32-* are toolchain for 64-bit Windows Application

## useful mingw-gcc/g++ options

| Options             | Description                       | Default                               |
| ------------------- | --------------------------------- | ------------------------------------- |
| `-s`                | strip                             | Contains debug information            |
| `-municode`         | support unicode, `wWinMain` entry | `WinMain` entry                       |
| `-mwindows`         | GUI, not console                  | PE32 executable (console) Intel 80386 |
| `-static-libgcc`    | link Static C Runtime             | Dynamic                               |
| `-static-libstdc++` | link Static C++ Runtime           | Dynamic                               |

## Example

Use libcurl to download https://curl.se/logo/curl-logo.svg

```txt
Project
│
├─inc
│      http.h        -- libcurl wrapper
├─src
│      http.cpp      -- libcurl wrapper
│      main.cpp
│
├─curl               -- libcurl
│  ├─inc
│  │     curl.h
│  └─lib
│        libcurl.dll
│
└─res
      example-icon.rc  -- add icon for the .exe file
      example-info.rc  -- add detail information for the .exe file
      logo.ico
```

### Build

```bash
git clone https://github.com/LubinLew/mingw64-example.git
cd mingw64-example/example

make
[CC]   src/http.cpp
[CC]   src/main.cpp
[RES]  objs/res/example-icon.res
[RES]  objs/res/example-info.res
[LINK] Build example.exe
```

### example.exe

![example](example.gif)
