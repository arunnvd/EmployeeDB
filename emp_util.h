#ifndef _EMP_UTL_H_
#defing _EMP_UTL_H_

#include "employee.h"


void print_emp(emp_detail* emp);
uint_8 emp_get_age(uint_8 age_gender);
char* emp_get_gender(uint_8 age_gender);
void print_emp_skillset(uint_32 skillset);
char* emp_get_dep(department dep);
char* emp_get_desgnation(emp_designation des);


typedef enum _skillset {
    SKILLSET_C = 0,
    SKILLSET_CPP,
    SKILLSET_JAVA,
    SKILLSET_PYTHON,
    SKILLSET_JS,
    SKILLSET_SELENIUM,
    SKILLSET_CICD,
    SKILLSET_TS,
}SKILLSET;

#define SKILLSET_MASK_C (1 << SKILLSET_C)
#define SKILLSET_MASK_CPP (1 << SKILLSET_CPP)
#define SKILLSET_MASK_JAVA (1 << SKILLSET_JAVA)
#define SKILLSET_MASK_PYTHON (1 << SKILLSET_PYTHON)
#define SKILLSET_MASK_JS (1 << SKILLSET_JS)
#define SKILLSET_MASK_SELENIUM (1 << SKILLSET_SELENIUM)
#define SKILLSET_MASK_CICD (1 << SKILLSET_CICD)
#define SKILLSET_MASK_TS (1 << SKILLSET_TS)

#endif
