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


void generate_emp_email(emp_detail* emp);


/* ******************************
*          LOGGER MODULE
*  ****************************** */
typedef enum {
    LOG_ERROR = 1,
    LOG_WARN  = 2,
    LOG_DEBUG = 3,
} log_level_t;

#define LOG_LEVEL LOG_DEBUG

#define log_debug(msg, ...)  \
        do{if(LOG_LEVEL >= LOG_DEBUG) printf("[%s - line(%d)] [DEBUG] :: " msg,  \
                    __FUNCTION__, __LINE__, ##__VA_ARGS__ );} while (0)
#define log_warning(msg, ...)  \
        do{if(LOG_LEVEL >= LOG_WARN) printf("[%s - line(%d)] [WARNING] :: " msg,  \
                    __FUNCTION__, __LINE__, ##__VA_ARGS__ );} while (0)
#define log_error(msg, ...)  \
        do{if(LOG_LEVEL >= LOG_ERROR) printf("[%s - line(%d)] [ERROR] :: " msg,  \
                    __FUNCTION__, __LINE__, ##__VA_ARGS__ );} while (0)


#endif
