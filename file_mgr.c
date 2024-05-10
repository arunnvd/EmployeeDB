#include "file_mgr.h"

#define FILE_PRFX "db\/empdb_"

EMP_RET save_emp_to_file(emp_detail * emp)
{
    int ret = 0;
    char * file_path = malloc(sizeof(char) * 17);
    sprintf(file_path, FILE_PRFX"%s.bin", emp->emp_id );
    FILE *file_handle = fopen(file_path, "wb");

    if (emp == NULL)
    {
        log_error("Invalid Employee data !!!");
        return EMP_RET_FAIL;
    }

    if (file_handle == NULL)
    {
        log_error("Unable to open file %s for writing \n", file_path);
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

    log_debug("Successfully Written employee[%s] details to file %s\n", emp->name, file_path);
    return EMP_RET_SUCCESS;
}

EMP_RET read_emp_from_file(char *db_path, emp_detail* emp)
{
    if (db_path == NULL || emp == NULL) 
    {
        log_error("Invalid params, unable to read Employee details \n");
        return EMP_RET_FAIL;
    }

    char * file_path = malloc(sizeof(char) * 17);
    sprintf(file_path, FILE_PRFX"%s.bin", db_path);

    FILE * file_handle = fopen(file_path, "rb");

    if(file_handle == NULL)
    {
        log_error("Error opening file [%s], unable to read Employee details \n", file_path);
        return EMP_RET_FAIL;
    }

    fread(emp, sizeof(emp_detail), 1, file_handle);

    log_debug("Successfully read employee(%s) detail from file %s\n", emp->name, file_path);
    
    return EMP_RET_SUCCESS;
}





