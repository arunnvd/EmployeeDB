#include "file_mgr.h"
#include "common_utils.h"
#include "emp_list.h"

#define FILE_PRFX "db\/empdb_"
static uint_16 g_total_emp_cnt = 0;
static BOOL db_init_done = FALSE;

static void update_total_emp_count(uint_16 count)
{
    g_total_emp_cnt = count;
}

static void increment_total_emp_count()
{
    g_total_emp_cnt += 1;
}

static void decrement_total_emp_count()
{
    if(g_total_emp_cnt)
        g_total_emp_cnt -= 1;
}

uint_16 get_total_emp_count()
{
    if(!db_init_done)
        file_mgr_db_init();

    return g_total_emp_cnt;
}

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


EMP_RET file_mgr_db_init()
{
    if(db_init_done)
    {
        log_warning("File DB already init completed, Doing nothing here\n");
        return EMP_RET_FAIL;
    }

    const char* sh_command = "bash file_list.sh db";
    FILE * sh_exe = popen(sh_command, "r");

    if(!sh_exe)
    {
        log_error("Unable to execute shell script, Init Failed \n");
        return EMP_RET_FAIL;
    }

    update_total_emp_count(0);
    char buffer[128];

    while(fgets(buffer, sizeof(buffer), sh_exe) != NULL)
    {
        char emp_id[8];

        strncpy(emp_id, buffer+6, 7);
        emp_id[7] = '\0';
        log_debug("Adding Employee %s to Local DB \n", emp_id);

        insert_emp_with_emp_id(emp_id);
        increment_total_emp_count();
    }

    db_init_done = TRUE;

    return EMP_RET_SUCCESS;
}













