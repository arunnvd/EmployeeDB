#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_utils.h"

typedef enum _emp_designation {
    INTERN,
    SE,
    SSE,
    EXPERT,
}emp_designation;

typedef enum _department {
    IOT,
    CSI,
    APPDEV,
    SECURITY,
}department;


typedef struct _employee {
    char            name[64];
    uint_8          age_gender; // 1st 2 Bit --> Gender, Next 6bit --> age
    char            emp_id[8];  // auto generated when new employee added 
    char            email[64];  // auto generated
    emp_designation designation;
    uint_8          experience;
    uint_32         skillset;
    uint_32         salary;
    department      dep;
}emp_detail;


EMP_RET generate_emp_email(emp_detail* emp);
EMP_RET format_age_gender(uint_8 age, uint_8 gender, emp_detail *emp);


#endif
