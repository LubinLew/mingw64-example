TARGET  := example.exe
OUTPUT  := objs

##########################################################
CXX     := /usr/bin/i686-w64-mingw32-g++-posix
AR      := /usr/bin/i686-w64-mingw32-ar
STRIP   := /usr/bin/i686-w64-mingw32-strip
WINDRES := /usr/bin/i686-w64-mingw32-windres

INCS    := -Iinc -Icurl/inc
CFLAGS  := -Wall -O2
DFLAGS  :=
GUIOPT  := -municode -mwindows
LFLAGS  := -static-libgcc -static-libstdc++ -Lcurl/lib -lcurl

OBJECTS := $(patsubst %.cpp,${OUTPUT}/%.o,$(wildcard src/*.cpp))
RES     := $(patsubst %.rc,${OUTPUT}/%.res,$(wildcard res/*.rc))

##########################################################
all:${TARGET}

${TARGET}: ${OBJECTS} ${RES}
	@ echo [LINK] Build $@
	@ ${CXX} ${GUIOPT}  $^ -s -o $@ ${LFLAGS}

.PHONY:clean
clean:
	rm -rf ${OUTPUT} *.exe

###############################################
${OUTPUT}/src/%.o: src/%.cpp
	@ mkdir -p $(@D)
	@ echo "[CC]   $^"
	@ ${CXX} -c ${CFLAGS} ${DFLAGS} ${INCS} $^ -o $@

${OUTPUT}/res/%.res: res/%.rc
	@ mkdir -p $(@D)
	@ echo "[RES]  $@"
	@ ${WINDRES} $^ -O coff -o $@
