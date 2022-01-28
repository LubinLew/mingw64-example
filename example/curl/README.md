# curl for windows

download from [https://curl.se](https://curl.se/windows/)

version:# 7.80.0

arch: x86(32 bit)


```bash
$ file libcurl.dll
libcurl.dll: PE32 executable (DLL) (console) Intel 80386 (stripped to external PDB), for MS Windows

$ file libcurl.dll.a
libcurl.dll.a: current ar archive
```



## Visual Studio Setting

1. C/C++ -> General -> Additional Include Directories -> add `curl\inc`

2. Linker -> Input -> Additional Dependencies -> add `curl\lib\libcurl.dll.a`

3. Build Events -> Post-Build Event -> add `xcopy /y /d "curl\lib\libcurl.dll" "$(OutDir)"`



