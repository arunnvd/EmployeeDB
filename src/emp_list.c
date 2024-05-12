#include "common_utils.h"
#include "emp_list.h"

static emp_list_item *head = NULL;

EMP_RET insert_emp_with_emp_id(char * emp_id)
{
    emp_list_item * new_emp = (emp_list_item *) malloc(sizeof(emp_list_item));

    if(new_emp == NULL)
    {
        log_error("No Memory available to create new employee, failed!!\n");
        return EMP_RET_FAIL;
    }

    strcpy(new_emp->emp_id, emp_id);
    new_emp->emp = NULL;
    new_emp->next = head;
    head = new_emp;

    return EMP_RET_SUCCESS;
}
