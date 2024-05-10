#include "employee.h"
#include <string.h>
#include "emp_util.h"
#include "file_mgr.h"

int main(int argc, char *argv[])
{
    emp_detail test;

    /*
    strcpy(test.name, "ARUN");
    test.age_gender = 121;
    strcpy(test.emp_id ,"EMP_001");
    strcpy(test.email, "arun@nagra.com");
    test.designation = EXPERT;
    test.experience = 10;
    test.skillset = 129;
    test.salary = 1000000;
    test.dep = CSI;
    */

    read_emp_from_file("EMP_001", &test);

    print_emp(&test);

    //save_emp_to_file(&test);

    return EXIT_SUCCESS;
}
