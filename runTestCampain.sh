#!/bin/bash

display_usage() { 
	echo "This script is responsible for running a test campain." 
	echo -e "\nUsage: \$0 [TEST_FOLDERS]" 
}

TEST_DIR=${PWD}/tests
# Get tests to exclude
IFS=$'\n' read -d '' -r -a lines < excludeList.txt

for dir in "$@"
do
    #echo "${TEST_DIR}/${dir}"
    tests_dir=$(find -L ${TEST_DIR}/${dir} -type d -maxdepth 1 -mindepth 1 -exec basename {} \;)
    for test in ${tests_dir}
    do
        #for contract_type in "${contract_type_list[@]}"
        if [[ ! " ${lines[*]} " =~ " ${test} "  ]]; then
            #echo "$test"
            make ${test}.run
        fi
    done
done

#while getopts u:a:f: flag
#do
#    case "${flag}" in 
#        u) username=${OPTARGS};;
#        a) age=${OPTARGS};;
#        f) fullname=${OPTARGS};;
#    esac
#done