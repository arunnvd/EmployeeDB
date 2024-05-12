AC_INIT([employee_mgr], [1.0])
AM_INIT_AUTOMAKE
AC_PROG_CC

AC_ARG_ENABLE([color-logs],
  [AS_HELP_STRING([--enable-color-logs],
                  [Enable color coded logs])],
  [enable_color_logs=$enableval],
  [enable_color_logs=no])

AC_ARG_WITH([log-level],
            [AS_HELP_STRING([--with-log-level=LEVEL],
                            [Set log level (error, warning, debug)])],
            [log_level=$withval],
            [log_level=error])

AM_CONDITIONAL([ENABLE_COLOR_LOGS], [test "$enable_color_logs" = yes])

case "$log_level" in
  error)
    log_val=1
    ;;
  warning)
    log_val=2
    ;;
  debug)
    log_val=3
    ;;
esac

AC_DEFINE_UNQUOTED([LOG_LEVEL], [$log_val], [log level])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT

