/**
* @file
* @brief test ini file api
* @author Deng Yangjun
* @date 2007-1-9
* @version 0.2
*/
#include <stdio.h>
#include "inifile.h"

#define BUF_SIZE 256

int main()
{
	const char *file ="test.ini";
	const char *section = "student";
	const char *name_key = "name";
	const char *age_key = "age";
	char name[BUF_SIZE]={0};
	int age;

	//write name key value pair
	if(!write_profile_string(section,name_key,"Tony",file))
	{
		printf("write name pair to ini file fail\n");
		return -1;
	}
	
	//write age key value pair
	if(!write_profile_string(section,age_key,"20",file))
	{
		printf("write age pair to ini file fail\n");
		return -1;
	}
	
	printf("[%s]\n",section);
	//read string pair, test read string value
	if(!read_profile_string(section, name_key, name, BUF_SIZE,"",file))
	{
		printf("read ini file fail\n");
		return -1;
	}
	else
	{
		printf("%s=%s\n",name_key,name);
	}

	//read age pair, test read int value.
	//if read fail, return default value
	age = read_profile_int(section,age_key,0,file);
	printf("%s=%d\n",age_key,age);
	
	char aa[BUF_SIZE]={0};
	if(!read_profile_string("aaa-1", "aa", aa, BUF_SIZE, "", file)){
		printf("read ini file failed!\n");
		return -1;
	}else{
		printf("[aaa-1].aa=%s\n", aa);
	}
	
	if(!read_profile_string("aaa-10", "aa", aa, BUF_SIZE, "", file)){
		printf("read ini file failed!\n");
		return -1;
	}else{
		printf("[aaa-10].aa=%s\n", aa);
	}
	
	if(!read_profile_string("aaa-10", "width", aa, BUF_SIZE, "", file)){
		printf("read ini file failed!\n");
		return -1;
	}else{
		printf("[aaa-10].width=%s\n", aa);
	}
	
	if(!read_profile_string("aaa-10", "width2", aa, BUF_SIZE, "", file)){
		printf("read ini file failed!\n");
		return -1;
	}else{
		printf("[aaa-10].width2=%s\n", aa);
	}
	
	if(!read_profile_string("a", "o", aa, BUF_SIZE, "", file)){
		printf("read ini file failed!\n");
		return -1;
	}else{
		printf("[a].o=%s\n", aa);
	}
	
	if(!read_profile_string("aaa-10", "port", aa, BUF_SIZE, "", file)){
		printf("read ini file failed!\n");
		return -1;
	}else{
		printf("[aaa-10].port=%s\n", aa);
	}
	
	if(!read_profile_string("aaa-10", "port1", aa, BUF_SIZE, "", file)){
		printf("read ini file failed!\n");
		return -1;
	}else{
		printf("[aaa-10].port1=%s\n", aa);
	}
	
	return 0;
}

