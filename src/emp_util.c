#include "employee.h"
#include "emp_util.h"

#define AGE_MASK 0xFC
#define GENDER_MASK 0x03

uint_8 emp_get_age(uint_8 age_gender)
{
    return ((age_gender & AGE_MASK) >> 2);
}

char* emp_get_gender(uint_8 age_gender)
{
    uint_8 gender = age_gender & GENDER_MASK ;
    
    if (gender == 1)
        return "Male";
    else if (gender == 2)
        return "Female";

    return "Others";
}

void print_emp_skillset(uint_32 skillset)
{
    BOOL need_seperator = 0;

    if((skillset & SKILLSET_MASK_C) == SKILLSET_MASK_C)
    {
        printf("%s C", (need_seperator?" |": ""));
        need_seperator = 1;
    }
    if((skillset & SKILLSET_MASK_CPP) == SKILLSET_MASK_CPP)
    {
        printf("%s CPP", (need_seperator?" |": ""));
        need_seperator = 1;
    }
    if((skillset & SKILLSET_MASK_JAVA) == SKILLSET_MASK_JAVA)
    {
        printf("%s JAVA", (need_seperator?" |": ""));
        need_seperator = 1;
    }
    if((skillset & SKILLSET_MASK_PYTHON) == SKILLSET_MASK_PYTHON)
    {
        printf("%s Python", (need_seperator?" |": ""));
        need_seperator = 1;
    }
    if((skillset & SKILLSET_MASK_JS) == SKILLSET_MASK_JS)
    {
        printf("%s JavaScript", (need_seperator?" |": ""));
        need_seperator = 1;
    }
    if((skillset & SKILLSET_MASK_SELENIUM) == SKILLSET_MASK_SELENIUM)
    {
        printf("%s Selenium", (need_seperator?" |": ""));
        need_seperator = 1;
    }
    if((skillset & SKILLSET_MASK_CICD) == SKILLSET_MASK_CICD)
    {
        printf("%s CICD", (need_seperator?" |": ""));
        need_seperator = 1;
    }
    if((skillset & SKILLSET_MASK_TS) == SKILLSET_MASK_TS)
    {
        printf("%s TypeScript", (need_seperator?" |": ""));
        need_seperator = 1;
    }
}

char* emp_get_dep(department dep)
{
    if (dep == IOT)
        return "IOT";
    if (dep == CSI)
        return "CSI";
    if (dep == APPDEV)
        return "Application Development";
    if (dep == SECURITY)
        return "Security";

    return "Unknown";
}

char* emp_get_desgnation(emp_designation des)
{
    if (des == SE)
        return "Software Engineer";
    if (des == INTERN)
        return "Intern / Consultant";
    if (des == SSE)
        return "Senior Software Engineer";
    if (des == EXPERT)
        return "Software Expert";
    return "Unknown";
}



void print_emp(emp_detail* emp)
{
    if(emp == NULL)
    {
        log_error("Invalid Params !! \n");
    }

    printf("=================================================\n");
    printf("|   Name        : %s | %s\n", emp->name, emp_get_desgnation(emp->designation));
    printf("|   Emp ID      : %s \n", emp->emp_id);
    printf("|   Skill set   :");
    print_emp_skillset(emp->skillset);
    printf("\n");
    printf("|   Age         : %d \n", emp_get_age(emp->age_gender));
    printf("|   Gender      : %s \n", emp_get_gender(emp->age_gender));
    printf("|   E-Mail      : %s \n", emp->email);
    printf("|   Total Exp   : %d \n", emp->experience);
    printf("|   Department  : %s \n", emp_get_dep(emp->dep));
    printf("|   Salary      : %d Rs\n", emp->salary);
    printf("=========================<end>====================\n");
}
