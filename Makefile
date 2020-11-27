.PHONY: clean demo test test_all debug build setup_build

target = Release
info-file = "./build/.build-info"
exec = make setup_build && cd build && cmake -DCMAKE_BUILD_TYPE=$(target) ../; make

ifeq ($(shell uname -p), unknown) # windows
    PYTHON := python
    OS = windows
else # linux
    PYTHON := python3
	OS = linux
endif

build:
	$(exec)

debug:
	$(eval target=RelWithDebInfo) # target=Debug
	$(exec)

setup_build:
	if test -f $(info-file) && ! grep -q $(OS) $(info-file); then make clean ; fi
	mkdir -p bin
	mkdir -p build
	if ! test -f $(info-file); then touch $(info-file) && echo $(OS) > $(info-file); fi
	cd build

test:
	./bin/UnitTests --logger=HRF,all --color_output=true --report_format=HRF --show_progress=no

# if future test suites are added, they can all be tested with this command
test_a:
	cd build; make test

demo:
	./bin/go_fish_demo

clean:
	rm -r -f bin/
	rm -r -f build/