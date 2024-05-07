#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "common_utils.h"

#define FILE_PATH "empdb.bin"

EMP_RET save_emp_to_file(emp_detail * emp)
{
    int ret = 0;
    FILE *file_handle = fopen(FILE_PATH, "wb");

    if (emp == NULL)
    {
        log_error("Invalid Employee data !!!");
        return EMP_RET_FAIL;
    }

    if (file_handle == NULL)
    {
        log_error("Unable to open file "FILE_PATH"for writing \n");
        return EMP_RET_FAIL;
    }

    ret = fwrite(emp, sizeof(emp_detail), 1, file_handle);

    if (!ret)
    {
        log_error("Error Writing to File !!!\n");
        fclose(file_handle);
        return EMP_RET_FAIL;
    }
    fclose(file_handle);

    log_debug("Successfully Written employee[%s] details to file", emp->name);
    return EMP_RET_SUCCESS;
}

