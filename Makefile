
build:
	cd build/Release; cmake -DCMAKE_BUILD_TYPE=Release ../../; make
.PHONY : build

debug:
	cd build/Debug; cmake -DCMAKE_BUILD_TYPE=Debug ../../; make
.PHONY : debug