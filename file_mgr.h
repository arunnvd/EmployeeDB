#ifndef _FILEMGR_H_
#define _FILEMGR_H_
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

EMP_RET save_emp_to_file(emp_detail* emp);
EMP_RET read_emp_from_file(char *db_path, emp_detail* emp);

#endif // !_FILEMGR_H_

