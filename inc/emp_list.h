#ifndef _EMP_LIST_H
#define _EMP_LIST_H

#include "employee.h"

typedef struct _emp_list_item {
    char emp_id[8];
    emp_detail *emp;
    struct _emp_list_item *next;
}emp_list_item;

EMP_RET insert_emp_with_emp_id(char * emp_id);

#endif // !_EMP_LIST_H
