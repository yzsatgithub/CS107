#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

int main(){
    char* dup_str;
    string newstring;
    char* str = "abcd";
    newstring = c_str(str);
//    newstring = strdup(str);
    printf("%s \n", newstring);
    free(dup_str);
	return 0;
}
