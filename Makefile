
## all #########
all: forge


## forge #######
forge: forge.bc
	clang++ -o ./build/forge ./build/tmp-forge/forge.bc

forge.bc:
	rm -Rf ./build/tmp-forge
	mkdir -p ./build/tmp-forge
	clang++ -O0 -emit-llvm -g3 -Wall -c -fmessage-length=0 -o ./build/tmp-forge/forge.bc ./forge/src/forge.cpp


################

clean:
	rm -Rf ./build
