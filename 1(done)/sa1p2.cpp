#include <iostream>
#include <string.h> // c lib
#include <stdio.h> // c lib

using namespace std;

/**
 * Traverse  Traverses a properly structured list, and returns the ordered
 * concatenation of all strings, including those in nested sublists.
 *
 * When applied to the two lists drawn above, the following strings
 * would be returned:
 *
 * ConcatAll(gameThree) would return "YankeesDiamondbacks"
 * ConcatAll(nestedNumbers) would return "onethreesix"
 *
 * 收获：　(1)　strcpy, strcat, strlen, strdup  and the wide usage of "char*"
 *              strdup(s)函数主要是拷贝字符串s的一个副本，由函数返回值返回，这个副本有自己的内存空间，和s不相干.strdup函数复制一个字符串,
 *              使用完后要记得删除在函数中动态申请的内存。strdup函数的参数不能为NULL，否则就会报段错误。
 *         (2)  malloc free
 *              使用malloc后一定使用free。比如strdup函数中调用了malloc()函数，因此调用strdup()函数后一定要free()
 *         (3)  tree logic
 *              遍历
 *         (4)  c++命名规则
 *              有点多，没看完
 *         (5)  const变量 const函数
 *              uncheck
 */ 
 
typedef enum{
    Integer, String, List, Nil
} nodeType;

char* ConcatString(char* cur, char* next){
    char* catresult = malloc(strlen(cur) + strlen(next) + 1);
    strcpy(catresult, cur);
    strcat(catresult, next);
    return catresult;
}

char* ConcatAll(nodeType* list){
    switch (*list) {
        case Integer:   
            return strdup("");
        case String:    
            return strdup((char* )(list + 1));
        case Nil:   
            return strdup(""); // 
    }

    nodeType** sublists = (nodeType** )(list + 1);
    char* cur = ConcatAll(sublists[0]);
    char* next = ConcatAll(sublists[1]);
    char* result = ConcatString(cur, next);
    free(cur); // 因为ConcatAll函数中使用了strdup()函数，因此要free
    free(next); // 
    return result;
}

nodeType* genList(){
    
}

int main(){

    return 0;
}
