#!/bin/bash

printf "This program :\n"
printf "\t1)find all Api interface in repo\n"
printf "\t2)for each interface source file generate wrap source file, eg: ApiParamWrap.h\n"
printf "\t3)generate dispatch.cpp\n"

function fetch_api_param(){
	touch $2
	cp /dev/null $2
	while read line
	do
		#echo $line
		grep -A100  "struct[ ]\{1,\}"$line -h -I -r ../ > ./.tmp.txt
		end_line=`grep "};" -n  ./.tmp.txt | head -n 1 | awk -F ":" '{print $1}'`
		head -n $end_line ./.tmp.txt >> $2
	done < $1

}

function find_api(){
	find ../ -name "*.h"|xargs grep "ApiErrCode"| grep -v "using" > ./.ifc.txt
	cat ./.ifc.txt | grep -o "[a-z,A-Z]\{1,\}Req" > ./.req.txt
	cat ./.ifc.txt | grep -o "[a-z,A-Z]\{1,\}Rsp" > ./.rsp.txt

	fetch_api_param ./.req.txt ./.req_def.txt
	fetch_api_param ./.rsp.txt ./.rsp_def.txt

	touch ./ApiParamWrap.h
	cp /dev/null ./ApiParamWrap.h
	cat ./.req_def.txt >> ./ApiParamWrap.h
	cat ./.rsp_def.txt >> ./ApiParamWrap.h

	rm -f ./.*txt
}

function gen_wrap(){
	# sed replace too hard， try c++ program 
	echo "to do:"
}


function main(){
	
	#step1 index all api interface into one file
	find_api

	#step2 generate interface wrap
	gen_wrap
	
	#step3  generate dispatch.cpp
}


main
