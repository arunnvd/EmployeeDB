
#ifndef _COMMON_UTLS_H_
#define _COMMON_UTLS_H_

typedef enum _emp_ret {
    EMP_RET_FAIL = -1,
    EMP_RET_SUCCESS = 0,
}EMP_RET;

typedef unsigned char BOOL;
typedef unsigned char uint_8;
typedef unsigned int  uint_32;


/* ******************************
*          LOGGER MODULE
*  ****************************** */
typedef enum {
    LOG_ERROR = 1,
    LOG_WARN  = 2,
    LOG_DEBUG = 3,
} log_level_t;

#define LOG_LEVEL LOG_DEBUG
#define COLORCODE_LOGS

#ifdef COLORCODE_LOGS 
#define RST     "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#else
#define RST  
#define RED    
#define GREEN  
#define YELLOW 
#endif // COLORCODE_LOGS

#define log_debug(msg, ...)  \
        do{if(LOG_LEVEL >= LOG_DEBUG) printf(GREEN"[%s - line(%d)] [DEBUG] :: " msg""RST,  \
                    __FUNCTION__, __LINE__, ##__VA_ARGS__ );} while (0)
#define log_warning(msg, ...)  \
        do{if(LOG_LEVEL >= LOG_WARN) printf(YELLOW"[%s - line(%d)] [WARNING] :: " msg""RST,  \
                    __FUNCTION__, __LINE__, ##__VA_ARGS__ );} while (0)
#define log_error(msg, ...)  \
        do{if(LOG_LEVEL >= LOG_ERROR) printf(RED"[%s - line(%d)] [ERROR] :: " msg""RST,  \
                    __FUNCTION__, __LINE__, ##__VA_ARGS__ );} while (0)


#endif //_COMMON_UTLS_H_
