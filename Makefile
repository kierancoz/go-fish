
build:
	cd build/Release; cmake -DCMAKE_BUILD_TYPE=Release ../../; make
.PHONY : build

debug:
	cd build/Debug; cmake -DCMAKE_BUILD_TYPE=Debug ../../; make
.PHONY : debug

test:
	./bin/Release/UnitTests --logger=HRF,all --color_output=true --report_format=HRF --show_progress=no
.PHONY : test

# if future test suites are added, they can all be tested with this command
test_all:
	cd build/Release; make test
.PHONY : test_all

demo:
	./bin/Release/go_fish_demo
.PHONY : demo

# clean: to implement
