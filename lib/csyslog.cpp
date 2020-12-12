#include "csyslog.h"

Csyslog*                        Csyslog::mInstance = NULL;
QString                         Csyslog::mSyslogCategory = "graceful-platform-theme";


void Csyslog::syslogInfo(int logLevel, const char *file, const char *func, int line, const char *fmt, ...)
{
#ifdef CSYSLOG_LOG_LEVEL
    if (logLevel > CSYSLOG_LOG_LEVEL) {
        return;
    }
#endif

    QString                     logLevelstr = NULL;
    char                        buf[20480] = {0};
    unsigned long               tagLen = 0;
    va_list                     para;

    if (NULL == mInstance) {
        mInstance = new Csyslog;
    }

    openlog ("", LOG_NDELAY, 0);

    switch (logLevel) {
    case LOG_EMERG:
        logLevelstr = "EMERG";
        break;
    case LOG_ALERT:
        logLevelstr = "ALERT";
        break;
    case LOG_CRIT:
        logLevelstr = "CRIT";
        break;
    case LOG_ERR:
        logLevelstr = "ERROR";
        break;
    case LOG_WARNING:
        logLevelstr = "WARNING";
        break;
    case LOG_NOTICE:
        logLevelstr = "NOTICE";
        break;
    case LOG_INFO:
        logLevelstr = "INFO";
        break;
    case LOG_DEBUG:
        logLevelstr = "DEBUG";
        break;
    default:
        logLevelstr = "UNKNOWN";
    }

    va_start(para, fmt);

    snprintf(buf, sizeof buf - 1, "%s [%s] %s %s line:%-5d ", logLevelstr.toUtf8().data(), mSyslogCategory.toUtf8().data(), file, func, line);

    tagLen = strlen(buf);
    vsnprintf(buf + tagLen, sizeof buf - 1 - tagLen, (const char*)fmt, para);
    syslog(logLevel, "%s", buf);
    closelog();

    va_end(para);
}

Csyslog::Csyslog()
{

}
