export WORKSPACE_DIR = $(PWD)
export BUILD_DIR     = $(WORKSPACE_DIR)/build

export P_SEARCH_DIR         = $(WORKSPACE_DIR)/parallel_search
#export P_SEARCH_CLIENT_DIR  = $(WORKSPACE_DIR)/parallel_search/client
#export P_SEARCH_SERVER_DIR  = $(WORKSPACE_DIR)/parallel_search/server

export TEST_DIR = $(WORKSPACE_DIR)/tests
export UNIT_TEST_DIR = $(TEST_DIR)/unit
export INTEGRATION_TEST_DIR = $(TEST_DIR)/integration
export TEST_CLIENT_DIR = $(INTEGRATION_TEST_DIR)/client
export TEST_SERVER_DIR = $(INTEGRATION_TEST_DIR)/server

export BUILD_TEST_DIR = $(BUILD_DIR)/tests
export BUILD_INTEGRATION_TEST_DIR = $(BUILD_TEST_DIR)/integration
export BUILD_UNIT_TEST_DIR = $(BUILD_TEST_DIR)/unit
export BUILD_TEST_CLIENT_DIR = $(BUILD_INTEGRATION_TEST_DIR)/client
export BUILD_TEST_SERVER_DIR = $(BUILD_INTEGRATION_TEST_DIR)/server

export BUILD_P_SEARCH_DIR         = $(BUILD_DIR)/parallel_search
export BUILD_P_SEARCH_CLIENT_DIR  = $(BUILD_DIR)/parallel_search/client
export BUILD_P_SEARCH_SERVER_DIR  = $(BUILD_DIR)/parallel_search/server
