export WORKSPACE_DIR = $(PWD)
export BUILD_DIR     = $(WORKSPACE_DIR)/build
export TESTS_DIR     = ${WORKSPACE_DIR}/tests
export BUILD_TESTS_DIR = ${BUILD_DIR}/tests

export SEARCH_ENGINE_DIR         = $(WORKSPACE_DIR)/search_engine

export ENGINE_DIR                = $(SEARCH_ENGINE_DIR)/engine
export ENGINE_SRC_DIR            = $(ENGINE_DIR)/src
export ENGINE_INC_DIR            = $(ENGINE_DIR)/inc

export WORDS_LIST_DIR            = $(SEARCH_ENGINE_DIR)/words_list
export WORDS_LIST_SRC_DIR        = $(WORDS_LIST_DIR)/src
export WORDS_LIST_INC_DIR        = $(WORDS_LIST_DIR)/inc

export TOOLS_DIR                 = $(SEARCH_ENGINE_DIR)/tools
export TOOLS_SRC_DIR             = $(TOOLS_DIR)/src
export TOOLS_INC_DIR             = $(TOOLS_DIR)/inc

export USR_FCT_DIR               = $(WORKSPACE_DIR)/usr_fct
export USR_FCT_SRC_DIR           = $(USR_FCT_DIR)/src
export USR_FCT_INC_DIR           = $(USR_FCT_DIR)/inc

export UNIT_TESTS_DIR = ${TESTS_DIR}/UnitTests
export INTEGRATION_TESTS_DIR = ${TESTS_DIR}/IntegrationTests
export BUILD_UNIT_TESTS_DIR = ${BUILD_TESTS_DIR}/UnitTests
export BUILD_INTEGRATION_TESTS_DIR = ${BUILD_TESTS_DIR}/IntegrationTests
export CPPCHECK_OUT_FILE = cppcheck_issues.xml
#export TEST_DIR = $(WORKSPACE_DIR)/tests
#export UNIT_TEST_DIR = $(TEST_DIR)/UnitTests
#export INTEGRATION_TEST_DIR = $(TEST_DIR)/IntegrationTests

#export BUILD_TEST_DIR = $(BUILD_DIR)/tests
#export BUILD_INTEGRATION_TEST_DIR = $(BUILD_TEST_DIR)/IntegrationTests
#export BUILD_UNIT_TEST_DIR = $(BUILD_TEST_DIR)/UnitTests

#export BUILD_P_SEARCH_DIR         = $(BUILD_DIR)/parallel_search
#export BUILD_P_SEARCH_CLIENT_DIR  = $(BUILD_DIR)/parallel_search/client
#export BUILD_P_SEARCH_SERVER_DIR  = $(BUILD_DIR)/parallel_search/server
