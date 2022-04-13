include usr_paths.mk

ifeq ($(RUN_MODE), Release)
else ifeq ($(RUN_MODE), Coverage)
else
  $(info MODE should be either Release or Coverage)
  RUN_MODE = Release
endif

all: clean search-engine

help: ## Display help on each available target
	@echo "Command format : make TARGET"

clean:
	@echo "\n ********  Cleaning ... ********n\n"
	rm -rf ${BUILD_DIR}
	rm -f ${CPPCHECK_OUT_FILE}
	rm -rf Coverage

gen:
	@echo "\n ********  Generating $@  ********n\n"
	mkdir -p ${BUILD_DIR}

%.build: gen
	@echo "\n ********  Generating $@  ********n\n"
	cd ${BUILD_DIR} && cmake .. && make $@

%.run: gen
	@echo "\n ********  Running $@  ********n\n"
	cd ${BUILD_DIR} && cmake .. && make $@

search-engine: gen
	@echo "\n ********  Generating $@  ********n\n"
	cd ${BUILD_DIR} && cmake .. && make $@

cppcheck:
	@echo "\n ********  Running cppcheck Analysis  ********n\n"
	cppcheck --enable=all --xml --suppress=missingIncludeSystem -I ${ENGINE_INC_DIR} -I ${TOOLS_INC_DIR}  -I ${WORDS_LIST_INC_DIR} -I ${USR_FCT_INC_DIR} ${SEARCH_ENGINE_DIR}  2> ${CPPCHECK_OUT_FILE}

all-tests: all
	@echo "\n ********  Running all tests in ${RUN_MODE} mode ********n\n"
	./runTestCampain.sh IntegrationTests/ UnitTests/

cov-compute:
	@echo "\n ********  Running computing coverage  ********n\n"
	mkdir -p Coverage/html
	# Also done in codeCoverage.cmake, have to do it twice
	lcov --directory . --no-external --capture --output-file Coverage/full_campain.info --rc lcov_branch_coverage=1
	lcov --remove Coverage/full_campain.info "${PWD}/usr_fct/*" "${PWD}/tests/*" -o Coverage/filtered_campain.info --rc lcov_branch_coverage=1
	# Generation of a html report
	genhtml --branch-coverage Coverage/filtered_campain.info --output-directory Coverage/html/
	# gcovr example: point to gda files and cpp files
	# Use gcovr in order to import coverage results in sonar. Xml files need to be in Cobertura 
	# format to be read by sonar. May have to delete functionToCoverage lines in xml
	# gcovr build/tests/UnitTests/TU-0004/CMakeFiles/tu_4.dir/__/__/__/search_engine/words_list/src/ -r . --sonarqube -o out.xml

sonar: cppcheck all
	@echo "\n ********  Running Sonarqube Analysis  ********n\n"
	# Command to stop and remove all running containers 
	docker stop $(docker ps -a -q); docker rm $(docker ps -a -q)
	# Command to start sonar server
    docker run -d --name sonar_cxx -e SONAR_ES_BOOTSTRAP_CHECKS_DISABLE=true -p 9000:9000 sonar/cxx:v1; 
	# Command to launch sonar analysis (add -X for debugging)
	docker run --network=host --rm -e SONAR_HOST_URL="http://localhost:9000" -e SONAR_LOGIN="5bfe408324211b9d35509c05f4fa11e047b7ef78" -v "${PWD}:/usr/src" sonarsource/sonar-scanner-cli

uml: 
	@echo "\n ********  UML generation   ********n\n"
	hpp2plantuml -i ${ENGINE_INC_DIR}/engine.h -i ${WORDS_LIST_INC_DIR}/words_list.h -o output.iuml

# SONAR_LOGIN = 5bfe408324211b9d35509c05f4fa11e047b7ef78