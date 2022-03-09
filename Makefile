include usr_paths.mk

#ADD USAGE FUNCTION

#ifeq ($(RUN_MODE), Debug)
#else ifeq ($(RUN_MODE), Release)
#else ifeq ($(RUN_MODE), Coverage) 
#else ifeq ($(RUN_MODE), Perf)
#else
#  $(info MODE should be either Debug, Release, Coverage or Perf)
#  RUN_MODE = Release
#endif

#all: clean client.build server.build

clean:
	@echo "\n ********  Cleaning  ********n\n"
	rm -rf ${BUILD_DIR}

gen:
	@echo "\n ********  Generating $@  ********n\n"
	mkdir -p ${BUILD_DIR}

%.build: gen
	@echo "\n ********  Generating $@  ********n\n"
	cd ${BUILD_DIR} && cmake .. && make $@

%.run:
	@echo "\n ********  Running $@  ********n\n"
	cd ${BUILD_DIR} && cmake .. && make $@

client: gen
	@echo "\n ********  Generating $@  ********n\n"
	cd ${BUILD_DIR} && cmake .. && make $@

server: gen
	@echo "\n ********  Generating $@  ********n\n"
	cd ${BUILD_DIR} && cmake .. && make $@

sonar: client.build server.build
	@echo "\n ********  Running Sonarqube Analysis  ********n\n"
	#docker stop $(docker ps -a -q); docker rm $(docker ps -a -q)
    #docker run -d --name sonarqube -e SONAR_ES_BOOTSTRAP_CHECKS_DISABLE=true -p 9000:9000 sonarqube:latest; docker run --network=host --rm -v "${PWD}:/usr/src" sonarsource/sonar-scanner-cli -X

#all_tests:  