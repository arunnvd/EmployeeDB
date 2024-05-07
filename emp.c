#include "employee.h"
#include <string.h>
#include "emp_util.h"

int main(int argc, char *argv[])
{
    emp_detail test;

    strcpy(test.name, "ARUN");
    test.age_gender = 121;
    strcpy(test.emp_id ,"EMP_001");
    strcpy(test.email, "arun@nagra.com");
    test.designation = EXPERT;
    test.experience = 10;
    test.skillset = 129;
    test.salary = 1000000;
    test.dep = CSI;

    print_emp(&test);

    return EXIT_SUCCESS;
}
