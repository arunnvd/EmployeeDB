#ifndef _EMP_UTL_H_
#defing _EMP_UTL_H_

#include "employee.h"


void print_emp(emp_detail* emp);
uint_8 emp_get_age(uint_8 age_gender);
char* emp_get_gender(uint_8 age_gender);
char* emp_get_skillset(uint_32 skillset);
char* emp_get_dep(department dep);
char* emp_get_desgnation(emp_designation des);

#endif
