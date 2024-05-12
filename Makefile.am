AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = employee_mgr
employee_mgr_SOURCES = \
					   src/emp.c \
					   src/emp_list.c \
					   src/emp_util.c \
					   src/employee.c \
					   src/file_mgr.c

employee_mgr_CFLAGS = -I$(top_srcdir)/inc

#if LOG_LEVEL==1
#employee_mgr_CFLAGS += -DLOG_LEVEL=1
#endif

#if LOG_LEVEL==2
#employee_mgr_CFLAGS += -DLOG_LEVEL=2
#endif

#if LOG_LEVEL==3
#employee_mgr_CFLAGS += -DLOG_LEVEL=3
#endif

if ENABLE_COLOR_LOGS
employee_mgr_CFLAGS += -g -DCOLORCODE_LOGS

endif
