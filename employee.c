#include "employee.h"
#include "common_utils.h"
#include <string.h>


#define EMAIL_SUFFX "@nagra.com"

EMP_RET generate_emp_email(emp_detail * emp)
{
    char name[64];

    if(emp == NULL)
    {
        log_error("Invalid input params !!!");
        return EMP_RET_FAIL;
    }

    if(strlen(emp->name) >= 10)
    {
        strncpy(name, emp->name, 10);
    }
    else 
    {
        strcpy(name, emp->name);
    }

    strcat(name, emp->emp_id);

    sprintf(emp->email, "%s"EMAIL_SUFFX, name);

    log_debug("Generated email for emp %s as %s \n", emp->name, emp->email);

    return EMP_RET_SUCCESS;
}


EMP_RET format_age_gender(uint_8 age, uint_8 gender, emp_detail *emp)
{

    if(emp == NULL)
    {
        log_error("Invalid input params !!!");
        return EMP_RET_FAIL;
    }

    emp->age_gender = (age << 2) | gender ;

    return EMP_RET_SUCCESS;
}

