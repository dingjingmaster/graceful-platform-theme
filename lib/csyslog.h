#ifndef CSYSLOG_H
#define CSYSLOG_H
#include <syslog.h>

#include <QString>


#define CT_SYSLOG(logLevel,...)         Csyslog::syslogInfo(logLevel, __FILE__, __func__, __LINE__, ##__VA_ARGS__);


class Csyslog
{
public:
    static void syslogInfo (int logLevel, const char* file, const char* func, int line, const char* fmt, ...);

private:
    Csyslog ();

private:
    static Csyslog*             mInstance;
    static QString              mSyslogCategory;
};

#endif // CSYSLOG_H
