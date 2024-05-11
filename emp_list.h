#ifndef _EMP_LIST_H
#define _EMP_LIST_H

#include "employee.h"

typedef struct _emp_list_item {
    char emp_id[8];
    emp_detail *emp;
    struct * next;
}emp_list_item;

#endif // !_EMP_LIST_H
