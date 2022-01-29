# curl for windows

download from [https://curl.se](https://curl.se/windows/)

Version: [7.81.0](https://curl.se/windows/dl-7.81.0/curl-7.81.0-win32-mingw.zip)

Arch: x86(32 bit)


```bash
$ file bin/libcurl.dll
libcurl.dll: PE32 executable (DLL) (console) Intel 80386 (stripped to external PDB), for MS Windows

$ file lib/libcurl.dll.a
libcurl.dll.a: current ar archive

$ file lib/libcurl.a
libcurl.a: current ar archive
```
> *.a are not statically linked with OpenSSL and other libraries.
>
> https://github.com/curl/curl-for-win/issues/12


## Visual Studio Setting

1. C/C++ -> General -> Additional Include Directories -> add `curl\inc`

2. Linker -> Input -> Additional Dependencies -> add `curl\lib\libcurl.dll.a`

3. Build Events -> Post-Build Event -> add `xcopy /y /d "curl\lib\libcurl.dll" "$(OutDir)"`



