include usr_paths.mk

ifeq ($(RUN_MODE), Debug)
else ifeq ($(RUN_MODE), Release)
else ifeq ($(RUN_MODE), Coverage) 
else ifeq ($(RUN_MODE), Perf)
else
  $(info MODE should be either Debug, Release, Coverage or Perf)
  RUN_MODE = Release
endif

%.build:
	mkdir -p ${BUILD_DIR}/${RUN_MODE}
	echo "\n\n$@"
	cd ${BUILD_DIR}/${RUN_MODE} && cmake -DCMAKE_BUILD_TYPE=${RUN_MODE} ../.. && make $@

clean:
	rm -rf ${BUILD_DIR}/