/*=============================================================================
#     FileName: 9-staffasc.c
#         Desc: only function for question 9 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-10-25 01:49:25
=============================================================================*/
#include <string.h>

int
staff_ascending_by_name(void *v1, void *v2) {
    staff_t *s1 = v1, *s2 = v2;
    return strcmp(s1->name, s2->name);
}
