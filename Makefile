# SPDX-FileCopyrightText: 2021 - Sebastian Ritter <bastie@users.noreply.github.com>
# SPDX-License-Identifier: MIT

#
# author: Sͬeͥbͭaͭsͤtͬian
#

## all #########
all: clean forge


## forge #######
forge: forge.all
	clang++ -o ./build/forge             \
	   ./build/tmp-forge/xIO.bc          \
	   ./build/tmp-forge/FFI.bc          \
	   ./build/tmp-forge/Blade.bc        \
	   ./build/tmp-forge/Iron.bc         \
	   ./build/tmp-forge/Ore.bc          \
	   ./build/tmp-forge/forge.bc        \
	   

forge.all:
	clang++ -std=c++2b -O0 -emit-llvm -g3 -Wall -c -fmessage-length=0 -o ./build/tmp-forge/xIO.bc        ./forge/src/xIO.cpp
	clang++ -std=c++2b -O0 -emit-llvm -g3 -Wall -c -fmessage-length=0 -o ./build/tmp-forge/FFI.bc        ./forge/src/FFI.cpp
	clang++ -std=c++2b -O0 -emit-llvm -g3 -Wall -c -fmessage-length=0 -o ./build/tmp-forge/forge.bc      ./forge/src/forge.cpp
	clang++ -std=c++2b -O0 -emit-llvm -g3 -Wall -c -fmessage-length=0 -o ./build/tmp-forge/Blade.bc      ./forge/src/Blade.cpp 
	clang++ -std=c++2b -O0 -emit-llvm -g3 -Wall -c -fmessage-length=0 -o ./build/tmp-forge/Iron.bc       ./forge/src/Iron.cpp 
	clang++ -std=c++2b -O0 -emit-llvm -g3 -Wall -c -fmessage-length=0 -o ./build/tmp-forge/Ore.bc        ./forge/src/Ore.cpp 

################

clean:
	rm -Rf ./build
	mkdir -p ./build/tmp-forge
	

# EOF (Tschüß è!😀)

# never ending!
